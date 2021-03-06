/*
 * DBC to SQL Converter
 * Copyright (C) 2009  David Vas, Anubisss
 * <http://code.google.com/p/dbctosql/>

 * Updated by Dagfinn (Droidfinn) in 2012.

 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <fstream>

#include "common/common.h"
#include "dbc/dbc.h"
#include "structs/spell.h"
#include "structs/spellitemenchantment.h"
#include "structs/dungeonencounter.h"
#include "common/progressbar.h"

#define SQL_INSERTS_PER_QUERY   300

#define SLASH_BUFFER            2000

bool check_dbc();
void test();
void dump_sql(const std::string dbc_translation[][2], DBCFileLoader *DBCFile,const std::string sql_filename, const std::string table_name);
bool LoadCheckDump(const std::string dbc_translation[][2], const int columns, const int rows, const std::string dbc_filename, const std::string sql_filename, const std::string table_name);

int main(int argc, char *argv[])
{
    bool wasRun=false;
    if(argc > 1) // To add support for more dbc files you need to add an else if statement under. And you'll need to create a .h file in the structs folder.
    {
        if(!strcmp(argv[1], "Spell.dbc")|!strcmp(argv[1], "3.3.5a"))
            wasRun=LoadCheckDump(spell_definition,SPELL_DBC_COLUMN_NUMS, SPELL_DBC_ROWS_NUMS, SPELL_DBC, SPELL_SQL, SPELL_TABLE);
        if(!strcmp(argv[1], "SpellItemEnchantment.dbc")|!strcmp(argv[1], "3.3.5a"))
            wasRun=LoadCheckDump(spellItemEnch_definition,SPELLITEMENCH_DBC_COLUMN_NUMS, SPELLITEMENCH_DBC_ROWS_NUMS, SPELLITEMENCH_DBC, SPELLITEMENCH_SQL, SPELLITEMENCH_TABLE);
        if(!strcmp(argv[1], "DungeonEncounter.dbc")|!strcmp(argv[1], "3.3.5a"))
            wasRun=LoadCheckDump(dungeonEncounter_definition,DUNGEONENCOUNTER_DBC_COLUMN_NUMS, DUNGEONENCOUNTER_DBC_ROWS_NUMS, DUNGEONENCOUNTER_DBC, DUNGEONENCOUNTER_SQL, DUNGEONENCOUNTER_TABLE);
        if(!wasRun)
            std::cout << "File not supported or unknown command. Type " << argv[0] << " for more info and supported files." << std::endl;
    }

    if(argc == 1) // If you add support for more dbc files. Please remember to add it to the list under.
    {
        std::cout << "*** DBCtoSQL v" << DBCTOSQL_VER << "*** <" << DBCTOSQL_WEB << ">" << std::endl;
        std::cout << "Usage: " << argv[0] << " <file name> <client version if needed> to convert one supported dbc file to sql" << std::endl;
        std::cout << "Usage: " << argv[0] << " <client version> to convert all supported dbc file for that client version" << std::endl << std::endl;
        std::cout << "Supported DBCs:\n";
        std::cout << "    Spell.dbc (" << SPELL_CLIENT_VERSION << ")" << std::endl;
        std::cout << "    SpellItemEnchantment.dbc (" << SPELLITEMENCH_CLIENT_VERSION << ")" << std::endl;
        std::cout << "    DungeonEncounter.dbc (" << DUNGEONENCOUNTER_CLIENT_VERSION << ")" << std::endl;

    }

    #ifdef WIN32
        std::cout << "\n\nPlease press Enter to exit...";
        getchar();
    #endif

    return 0;
}

bool LoadCheckDump(const std::string dbc_translation[][2], const int columns, const int rows, const std::string dbc_filename, const std::string sql_filename, const std::string table_name)
{
    DBCFileLoader DBCFile;
    if(DBCFile.Load(dbc_filename.c_str(), columns, rows))
	    dump_sql(dbc_translation, &DBCFile, sql_filename, table_name);
    return true;
}

void dump_sql(const std::string dbc_translation[][2], DBCFileLoader *DBCFile,const std::string sql_filename, const std::string table_name)
{
    std::cout << sql_filename.c_str() << " - Creating file..." << std::endl;
    std::ofstream sqlFile(sql_filename.c_str());
   if(!sqlFile)
    {
	std::cout << "Unable to open file " << sql_filename << " " << sqlFile << std::endl;
        return;
    }

    std::cout << sql_filename << " - Creating the SQL table struct..." << std::endl;
    sqlFile << "-- DBCtoSQL v" <<  DBCTOSQL_VER << std::endl << std::endl; 
    sqlFile << "-- Web: " << DBCTOSQL_WEB << std::endl << std::endl;
    sqlFile << "DROP TABLE IF EXISTS `" << table_name << "`;" << std::endl;
    sqlFile << "CREATE TABLE `" << table_name << "` (" << std::endl;

    for(uint16 i = 0; i < DBCFile->getNumFields() ; i++)
    {
        if(!strcmp(dbc_translation[i][0].c_str(), "uint32"))
            sqlFile <<  "    `" << dbc_translation[i][1] << "` INT (11) UNSIGNED DEFAULT '0' NOT NULL," << std::endl;
        else if(!strcmp(dbc_translation[i][0].c_str(), "int32"))
            sqlFile <<  "    `" << dbc_translation[i][1] << "` INT (11) DEFAULT '0' NOT NULL," << std::endl;
        else if(!strcmp(dbc_translation[i][0].c_str(), "uint16"))
            sqlFile <<  "    `" << dbc_translation[i][1] << "` INT (11) UNSIGNED DEFAULT '0' NOT NULL," << std::endl;
        else if(!strcmp(dbc_translation[i][0].c_str(), "int16"))
            sqlFile <<  "    `" << dbc_translation[i][1] << "` INT (11) DEFAULT '0' NOT NULL," << std::endl;
        else if(!strcmp(dbc_translation[i][0].c_str(), "float"))
            sqlFile <<  "    `" << dbc_translation[i][1] << "` FLOAT DEFAULT '0' NOT NULL," << std::endl;
        else if(!strcmp(dbc_translation[i][0].c_str(), "flag96"))
            sqlFile <<  "    `" << dbc_translation[i][1] << "` INT (11) UNSIGNED DEFAULT '0' NOT NULL," << std::endl;
        else if(!strcmp(dbc_translation[i][0].c_str(), "char*") | !strcmp(dbc_translation[i][0].c_str(), "char"))
            sqlFile <<  "    `" << dbc_translation[i][1] << "` TEXT," << std::endl;
        else
        {
            std::cout << "ERROR: unknown column type: " << dbc_translation[i][0] << "  in column: " << dbc_translation[i][1] << std::endl;
            std::cout << "Please check the .h file that holds the translation table and make sure only valid types are used: uint32, int32, uint16, int16, float, flag96, char* or char" << std::endl;
            return;
        }
    }

    sqlFile << "    PRIMARY KEY(`" << dbc_translation[0][1] << "`)" << std::endl;
    sqlFile << ") ENGINE=MyISAM DEFAULT CHARSET=utf8;" << std::endl << std::endl << std::endl;

    std::cout << sql_filename << " - DONE\n\n";

    // start dumping the data from the DBC

    std::cout << sql_filename << " - Dumping data...\n";

    Bar ProgressSpell(DBCFile->getNumRows());

    char tstrSpell[SLASH_BUFFER];

    for(uint32 j = 0; j < DBCFile->getNumRows(); j++)
    {
        // new insert block
        if((j % SQL_INSERTS_PER_QUERY) == 0)
        {
            sqlFile << "\nINSERT INTO `" << table_name << "` (";
            for(uint16 k = 0; k < DBCFile->getNumFields(); k++)
            {
                sqlFile << "`" << dbc_translation[k][1]  << "`";
                if(k !=  DBCFile->getNumFields() - 1)
                    sqlFile << "," ;
            }
            sqlFile << ") VALUES " << std::endl << "(";
        }
        else
            sqlFile << ",(";

       for(uint32 l = 0; l < DBCFile->getNumFields(); l++)
       {
            if(!strcmp(dbc_translation[l][0].c_str(), "uint32"))
                sqlFile <<  (uint32)DBCFile->getRecord(j).getUInt32(l);
            else if(!strcmp(dbc_translation[l][0].c_str(), "uint16"))
                sqlFile <<  (int16)DBCFile->getRecord(j).getUint16(l);
            else if(!strcmp(dbc_translation[l][0].c_str(), "int32"))
                sqlFile <<  (int32)DBCFile->getRecord(j).getInt32(l);
            else if(!strcmp(dbc_translation[l][0].c_str(), "int16"))
                sqlFile <<  (int32)DBCFile->getRecord(j).getInt16(l);
            else if(!strcmp(dbc_translation[l][0].c_str(), "float"))
                sqlFile << DBCFile->getRecord(j).getFloat(l);
            else if(!strcmp(dbc_translation[l][0].c_str(), "flag96"))
                sqlFile << (flag96)DBCFile->getRecord(j).getUInt32(l);
            else if(!strcmp(dbc_translation[l][0].c_str(), "char*") | !strcmp(dbc_translation[l][0].c_str(), "char"))
            {
                const char *dstr = DBCFile->getRecord(j).getString(l);
                uint16 otherindex = 0;
                for(uint16 m = 0; m <= strlen(dstr); m++)
                {
                    if(dstr[m] == '\'' || dstr[m] == '"')
                    {
                        tstrSpell[otherindex++] = '\\';
                        tstrSpell[otherindex++] = dstr[m];
                    }
                    else
                        tstrSpell[otherindex++] = dstr[m];
                }
                sqlFile << "\""<< tstrSpell << "\"";
            }

            if(l != DBCFile->getNumFields() - 1)
                sqlFile << ",";
        }

        // end of insert block
        if((( j + 1) % SQL_INSERTS_PER_QUERY) == 0)
            sqlFile << ");" << std::endl;
        else if(j == DBCFile->getNumRows() - 1)
            sqlFile << ");" << std::endl;
        else
            sqlFile << ")" << std::endl;

        ProgressSpell.Step();
    }

    std::cout << std::endl << sql_filename << " - DONE\n\n";

    sqlFile << std::endl <<  "-- EOF" << std::endl;
    sqlFile.close();
    std::cout << sql_filename << " - Closed\n\n";
}

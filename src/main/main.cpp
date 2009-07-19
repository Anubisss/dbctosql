/*
 * DBC to SQL Converter
 * Copyright (C) 2009  David Vas, Anubisss
 * <http://code.google.com/p/dbctosql/>

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

#include "common/common.h"
#include "dbc/dbc.h"
#include "structs/spell.h"
#include "common/progressbar.h"

#define SQL_INSERTS_PER_QUERY   300

DBCFileLoader DBCSpell;

bool check_dbc();
void dump_sql();

int main()
{
    std::cout << "*****************************************************************************\n";
    std::cout << "DBCtoSQL v" << DBCTOSQL_VER << "\n<" << DBCTOSQL_WEB <<">\n";
    std::cout << "*****************************************************************************\n\n\n";

    std::cout << "Supported DBCs:" << std::endl << "    Spell.dbc format:\n";
    std::cout << "        DBC columns numbers:        " << SPELL_DBC_COLUMN_NUMS << std::endl;
    std::cout << "        DBC rows numbers:           " << SPELL_DBC_ROWS_NUMS << std::endl;
    std::cout << "        DBC supported client build: " << SPELL_DBC_CLIENT_BUILD << "\n\n";

    DBCSpell.Load(SPELL_DBC);

    if(check_dbc())
    {
        dump_sql();
        std::cout << "Ready. DBCs converted to SQLs.\n";
    }

    #ifdef WIN32
        std::cout << "\n\nPlease press Enter to exit...";
        getchar();
    #endif

    return 0;
}

bool check_dbc()
{
    if(!DBCSpell.getNumFields())
    {
        std::cout << "ERROR: Can not open file: " << SPELL_DBC << std::endl;
        return false;
    }
    else
        std::cout << SPELL_DBC << " - Opened successful." << std::endl << SPELL_DBC << " - fields: "
        << DBCSpell.getNumFields() << ", rows: " << DBCSpell.getNumRows() << std::endl;

    if(DBCSpell.getNumFields() != SPELL_DBC_COLUMN_NUMS)
    {
        std::cout << SPELL_DBC << " - ERROR: Column numbers do not match with the supported DBC format." << std::endl;
        return false;
    }
    if(DBCSpell.getNumRows() != SPELL_DBC_ROWS_NUMS)
    {
        std::cout << SPELL_DBC << " - ERROR: Rows numbers do not match with the supported DBC format." << std::endl;
        return false;
    }
    std::cout << SPELL_DBC << " - DBC format: OK." << "\n\n";
    return true;
}

void dump_sql()
{
    std::cout << SPELL_DBC << " - Creating the SQL table struct...\n";

    FILE *fsql = fopen(SPELL_SQL, "w");
    if(!fsql)
        return;

    fprintf(fsql, "-- DBCtoSQL v%s\n\n", DBCTOSQL_VER);
    fprintf(fsql, "-- Web: %s\n\n\n", DBCTOSQL_WEB);

    fprintf(fsql, "DROP TABLE IF EXISTS `%s`;\n", SPELL_TABLE);
    fprintf(fsql, "CREATE TABLE `%s` (\n", SPELL_TABLE);

    for(uint16 i = 0; i < SPELL_DBC_COLUMN_NUMS; i++)
    {
        if(!strcmp(sql_translation_table[i][0], "uint32"))
            fprintf(fsql, "    `%s` INT (11) UNSIGNED DEFAULT '0' NOT NULL,\n", sql_translation_table[i][1]);
        else if(!strcmp(sql_translation_table[i][0], "int32"))
            fprintf(fsql, "    `%s` INT (11) DEFAULT '0' NOT NULL,\n", sql_translation_table[i][1]);
        else if(!strcmp(sql_translation_table[i][0], "float"))
            fprintf(fsql, "    `%s` FLOAT DEFAULT '0' NOT NULL,\n", sql_translation_table[i][1]);
        else if(!strcmp(sql_translation_table[i][0], "flag96"))
            fprintf(fsql, "    `%s` INT (11) UNSIGNED DEFAULT '0' NOT NULL,\n", sql_translation_table[i][1]);
        else if(!strcmp(sql_translation_table[i][0], "char*"))
            fprintf(fsql, "    `%s` TEXT,\n", sql_translation_table[i][1]);
        else
            fprintf(fsql, "    ERROR: unknown column type: %s in column: %s\n", sql_translation_table[i][0], sql_translation_table[i][1]);
    }

    fprintf(fsql, "    PRIMARY KEY(`%s`)\n", SPELL_TABLE_INDEX);
    fprintf(fsql, ") ENGINE=MyISAM DEFAULT CHARSET=utf8;\n");

    fprintf(fsql, "\n\n");

    std::cout << SPELL_DBC << " - DONE\n\n";

    // start dumping the data from the DBC

    std::cout << SPELL_DBC << " - Dumping data...\n";

    Bar Progress(DBCSpell.getNumRows());

    char tstr[2000];

    for(uint32 j = 0; j < DBCSpell.getNumRows(); j++)
    {
        // new insert block
        if((j % SQL_INSERTS_PER_QUERY) == 0)
        {
            fprintf(fsql, "\nINSERT INTO `%s` (", SPELL_TABLE);
            for(uint16 i = 0; i < SPELL_DBC_COLUMN_NUMS; i++)
            {
                fprintf(fsql, "`%s`", sql_translation_table[i][1]);
                if(i != SPELL_DBC_COLUMN_NUMS - 1)
                    fprintf(fsql, ",");
            }
            fprintf(fsql, ") VALUES \n");
            fprintf(fsql, "(");
        }
        else
            fprintf(fsql, ",(");

        for(uint16 i = 0; i < SPELL_DBC_COLUMN_NUMS; i++)
        {
            if(!strcmp(sql_translation_table[i][0], "uint32"))
                fprintf(fsql, "%lu", DBCSpell.getRecord(j).getUInt32(i));
            else if(!strcmp(sql_translation_table[i][0], "int32"))
                fprintf(fsql, "%ld", DBCSpell.getRecord(j).getInt32(i));
            else if(!strcmp(sql_translation_table[i][0], "float"))
                fprintf(fsql, "%f", DBCSpell.getRecord(j).getFloat(i));
            else if(!strcmp(sql_translation_table[i][0], "flag96"))
                fprintf(fsql, "%lu", DBCSpell.getRecord(j).getUInt32(i));
            else if(!strcmp(sql_translation_table[i][0], "char*"))
            {
                const char *dstr = DBCSpell.getRecord(j).getString(i);
                uint16 otherindex = 0;
                for(uint16 k = 0; k <= strlen(dstr); k++)
                {
                    if(dstr[k]== '\'' || dstr[k ]== '"')
                    {
                        tstr[otherindex++] = '\\';
                        tstr[otherindex++] = dstr[k];
                    }
                    else
                        tstr[otherindex++] = dstr[k];
                }
                fprintf(fsql, "\"%s\"", tstr);
            }

            if(i != SPELL_DBC_COLUMN_NUMS - 1)
                fprintf(fsql, ",");
        }

        // end of insert block
        if((( j + 1) % SQL_INSERTS_PER_QUERY) == 0)
            fprintf(fsql, ");\n");
        else if(j == DBCSpell.getNumRows() - 1)
            fprintf(fsql, ");\n");
        else
            fprintf(fsql, ")\n");

        Progress.Step();
    }

    std::cout << std::endl << SPELL_DBC << " - DONE\n\n";

    fprintf(fsql, "\n");
    fprintf(fsql, "-- EOF\n");
    fclose(fsql);

    std::cout << SPELL_DBC << " - Closed\n\n";
}

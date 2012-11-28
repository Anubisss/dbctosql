/*
 * DBC to SQL Converter
 * Copyright (C) 2012  Dagfinn (Uberdaff)
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

#ifndef __DUNGEONENCOUNTER_H__
#define __DUNGEONENCOUNTER_H__

char const *DUNGEONENCOUNTER_DBC   = "DungeonEncounter.dbc";
char const *DUNGEONENCOUNTER_SQL   = "DungeonEncounter.sql";
char const *DUNGEONENCOUNTER_TABLE = "DungeonEncounter";
char const *DUNGEONENCOUNTER_CLIENT_VERSION = "3.3.5a";

#define DUNGEONENCOUNTER_DBC_CLIENT_BUILD  12340 // 3.3.5a

#define DUNGEONENCOUNTER_DBC_COLUMN_NUMS   23
#define DUNGEONENCOUNTER_DBC_ROWS_NUMS    612

const std::string dungeonEncounter_definition[DUNGEONENCOUNTER_DBC_COLUMN_NUMS][2] =
{
    {"uint16", "ID"},
    {"uint16", "mapId"},
    {"uint16", "difficulty"},
    {"uint16", "unk0"},
    {"uint16", "encounterIndex"},
    {"char*",  "description[1]"},
    {"char*",  "description[2]"},
    {"char*",  "description[3]"},
    {"char*",  "description[4]"},
    {"char*",  "description[5]"},
    {"char*",  "description[6]"},
    {"char*",  "description[7]"},
    {"char*",  "description[8]"},
    {"char*",  "description[9]"},
    {"char*",  "description[10]"},
    {"char*",  "description[11]"},
    {"char*",  "description[12]"},
    {"char*",  "description[13]"},
    {"char*",  "description[14]"},
    {"char*",  "description[15]"},
    {"char*",  "description[16]"},
    {"uint16", "nameFlags"},
    {"uint16", "unk1"},
};

#endif

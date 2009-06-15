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

#include "dbc/dbc.h"

DBCFileLoader::DBCFileLoader()
{
    data = NULL;
    stringTable = NULL;
}

DBCFileLoader::~DBCFileLoader()
{
    if(data)
        delete [] data;
    if(stringTable)
        delete [] stringTable;
}

bool DBCFileLoader::Load(char const *filename)
{
    FILE *pf = fopen(filename, "rb");
    if(!pf)
        return false;

    uint32 header;

    if(fread(&header, 4, 1, pf) != 1)
        return false;

    if(header != WDBC_HEADER)
        return false;

    if(fread(&recordCount, 4, 1, pf) != 1) // Number of records
        return false;

    if(fread(&fieldCount, 4, 1, pf) != 1) // Number of fields
        return false;

    if(fread(&recordSize, 4, 1, pf) != 1) // Size of a record
        return false;

    if(fread(&stringSize, 4, 1, pf) != 1) // String size
        return false;

#ifdef USING_BIG_ENDIAN
    recordCount = swap32(recordCount);
    fieldCount = swap32(fieldCount);
    recordSize = swap32(recordSize);
    stringSize = swap32(stringSize);
#endif

    data = new unsigned char[recordSize * recordCount + stringSize];
    stringTable = data + recordSize * recordCount;

    if(!data || !stringTable)
        return false;

    //fread(data, recordSize * recordCount, 1, pf);
    if(fread(data, recordSize * recordCount + stringSize , 1, pf) != 1)
        return false;

    if(fread(stringTable, stringSize, 1, pf) != 1)
        return false;

    /* swap all the rows */
#ifdef USING_BIG_ENDIAN
    uint32 *tbl = (uint32*)data;
    for(uint32 i = 0; i < (fieldCount * recordCount); i++)
    tbl[i] = swap32((uint32)tbl[i]);
#endif
    fclose(pf);
    return true;
}

DBCFileLoader::Record DBCFileLoader::getRecord(size_t id)
{
    assert(data);
    return Record(*this, data + id * recordSize);
}

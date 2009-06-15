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

#include "progressbar.h"

#include <cstdio>

char const *Bar::empty = " ";
char const *Bar::full  = "\x3D"; // win
// char const *Bar::full  = "*"; // *nix

Bar::~Bar()
{
    printf("\n");
    fflush(stdout);
}

Bar::Bar(uint32 row_count)
{
    rec_no = 0;
    rec_pos = 0;
    indic_len = 50;
    num_rec = row_count;

    printf("\x3D"); // win
    // printf("["); // *nix

    for(uint8 i = 0; i < indic_len; i++)
        printf(empty);

    printf("\x3D 0%%\r\x3D"); // win
    // printf("] 0%%\r["); // *nix

    fflush(stdout);
}

void Bar::Step()
{
    uint32 i, n;

    if(num_rec == 0)
        return;

    rec_no++;

    n = rec_no * indic_len / num_rec;

    if(n != rec_pos)
    {
        printf("\r\x3D"); // win
        // printf("\r["); // *nix

        for(i = 0; i < n; i++)
            printf(full);

        for(; i < indic_len; i++)
            printf(empty);

        float percent = (((float)n / (float)indic_len) * 100);

        printf("\x3D %i%%  \r\x3D", (uint16)percent); // win
        // printf("] %i%%  \r[", (uint16)percent); // *nix

        fflush(stdout);

        rec_pos = n;
    }
}

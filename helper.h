/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * helper.h
 * Copyright (C) 2017 M.J.Ahmadi <mohammad.j.ahmadi@gmail.com>
 * 
 * pjdate is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * pjdate is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _HELPER_H
#define _HELPER_H

#define boolean   unsigned short int
#define true      1
#define false     0


int _div (int a, int b);
char *_inttostr (int a);
char *_strconcat (char *s1, const char *s2);
char *_append (const char *s, char c);
char *_substring (char s[], int p, int l);
int _file_exist (const char *filename);

#endif //_HELPER_H

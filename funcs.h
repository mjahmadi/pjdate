/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * funcs.h
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

#ifndef _FUNCS_H
#define _FUNCS_H


void print_error (char *error_msg, int error_code);
pjdate get_cur_gdate (void);
pjdate get_cur_pjdate (void);
void print_pjdate (pjdate jd, char *fmt);
pjdate compare_pjdate (char *str);
int pjdate_difference (char *str);
pjdate file_modification_date (char *filename);

#endif /* _FUNCS_H */

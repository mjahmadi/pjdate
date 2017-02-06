/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * pjdate.h
 * Copyright (C) 2017 M.J.Ahmadi <mohammad.j.ahmadi@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _PJDATE_H
#define _PJDATE_H


typedef struct
{
	char *year,
	     *month,
	     *day;
	/* TODO
		 *hour,
		 *minute,
		 *seconds;
	*/
}pjdate;

static int g_days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int j_days_in_month[] = {31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29};

char * persian_weekday_name (int weekday);
char * persian_weekday_abbreviation_name (int weekday);
char * persian_month_name (int month);
pjdate jalali_to_gregorian(int j_y, int j_m, int j_d);
pjdate gregorian_to_jalali (int g_y, int g_m, int g_d);

#endif /* _PJDATE_H */

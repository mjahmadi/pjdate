/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * pjdate.c
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

#ifndef _PJDATE_C
#define _PJDATE_C

#include <stdio.h>
#include "pjdate.h"
#include "helper.h"


char *persian_weekday_name (int weekday)
{
	char *buf;
	switch (weekday) {
		case 1:
			buf = "شنبه";
			break;
		case 2:
			buf = "یکشنبه";
			break;
		case 3:
			buf = "دوشنبه";
			break;
		case 4:
			buf = "سه شنبه";
			break;
		case 5:
			buf = "چهار شنبه";
			break;
		case 6:
			buf = "پنجشنبه";
			break;
		case 7:
			buf = "جمعه";
			break;
	}
	
	return buf;
}


char *persian_weekday_abbreviation_name (int weekday)
{
	char *buf;
	switch (weekday) {
		case 1:
			buf = "ش";
			break;
		case 2:
			buf = "ی";
			break;
		case 3:
			buf = "د";
			break;
		case 4:
			buf = "س";
			break;
		case 5:
			buf = "چ";
			break;
		case 6:
			buf = "پ";
			break;
		case 7:
			buf = "ج";
			break;
	}
	
	return buf + '\0';
}

 
char *persian_month_name (int month)
{
	char *buf;
	switch (month) {
		case 1:
			buf = "فروردین";
			break;
		case 2:
			buf = "اردیبهشت";
			break;
		case 3:
			buf = "خرداد";
			break;
		case 4:
			buf = "مرداد";
			break;
		case 5:
			buf = "تیر";
			break;
		case 6:
			buf = "شهریور";
			break;
		case 7:
			buf = "مهر";
			break;
		case 8:
			buf = "آبان";
			break;
		case 9:
			buf = "آذر";
			break;
		case 10:
			buf = "دی";
			break;
		case 11:
			buf = "بهمن";
			break;
		case 12:
			buf = "اسفند";
			break;
	}
	
	return buf;
}


pjdate jalali_to_gregorian(int j_y, int j_m, int j_d)
{
	int i;
	int jy = j_y - 979;
	int jm = j_m - 1;
	int jd = j_d - 1;

	int j_day_no = 365 * jy + _div(jy, 33) * 8 + _div(jy % 33 + 3, 4);
	for (i = 0; i < jm; ++i) {
		j_day_no += j_days_in_month[i];
	}

	j_day_no += jd;

	int g_day_no = j_day_no + 79;

	int gy = 1600 + 400 * _div(g_day_no, 146097);
	g_day_no = g_day_no % 146097;

	int leap = true;
	if (g_day_no >= 36525) {
		g_day_no--;
		gy += 100 * _div(g_day_no,  36524);
		g_day_no = g_day_no % 36524;

		if (g_day_no >= 365) {
			g_day_no++;
		} else {
			leap = false;
		}
	}

	gy += 4 * _div(g_day_no, 1461);
	g_day_no %= 1461;

	if (g_day_no >= 366) {
		leap = false;

		g_day_no--;
		gy += _div(g_day_no, 365);
		g_day_no = g_day_no % 365;
	}

	for (i = 0; g_day_no >= g_days_in_month[i] + (i == 1 && leap); i++) {
		g_day_no -= g_days_in_month[i] + (i == 1 && leap);
	}
	
	int gm = i + 1;
	int gd = g_day_no + 1;
	
	pjdate pjdate;
	pjdate.year  = _inttostr(gy);
	pjdate.month = _inttostr(gm);
	pjdate.day   = _inttostr(gd);
	
	return pjdate;
}


pjdate gregorian_to_jalali (int g_y, int g_m, int g_d)
{
	int i;
	int gy = g_y - 1600;
	int gm = g_m - 1;
	int gd = g_d - 1;

	int g_day_no = 365 * gy + _div(gy + 3, 4) - _div(gy + 99, 100) + _div(gy + 399, 400);

	for (i=0; i < gm; ++i) {
		g_day_no += g_days_in_month[i];
	}


	if (gm > 1 && ((gy % 4 == 0 && gy % 100 != 0) || (gy % 400 == 0))) {
		g_day_no++;
	}

	g_day_no += gd;

	int j_day_no = g_day_no - 79;

	int j_np = _div(j_day_no, 12053);
	j_day_no = j_day_no % 12053;

	int jy = 979 + 33 * j_np + 4 * _div(j_day_no, 1461);

	j_day_no %= 1461;

	if (j_day_no >= 366) {
		jy += _div(j_day_no - 1, 365);
		j_day_no = (j_day_no-1) % 365;
	}

	for (i = 0; i < 11 && j_day_no >= j_days_in_month[i]; ++i) {
		j_day_no -= j_days_in_month[i];
	}

	int jm = i+1;
	int jd = j_day_no + 1;

	pjdate pjdate;
	pjdate.year  = _inttostr(jy);
	pjdate.month = _inttostr(jm);
	pjdate.day   = _inttostr(jd);

	return pjdate;
}


#endif /* _PJDATE_C */

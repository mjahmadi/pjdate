/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
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

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "helper.h"
#include "pjdate.h"
#include "about.h"
#include "funcs.h"

char *_format = "%Y-%M-%D";

int main (int argc, char *argv[])
{
	int opt;
	
	const char *short_options = "f:j:g:c:r:d:";
	const struct option long_options[] = {
		{ "help",			0, NULL, 'h' },
		{ "format",			1, NULL, 'f' },
		{ "to-jalali",		1, NULL, 'j' },
		{ "to-gregorian",	1, NULL, 'g' },
		{ "compare",		1, NULL, 'c' },
		{ "reference",		1, NULL, 'r' },
		{ "datediff",		1, NULL, 'd' },
		{ "version",		0, NULL, 'v' },
		{  NULL,			0, NULL,  0  }
	};
	
	pjdate _pjdate = get_cur_pjdate();
	
	while ((opt = getopt_long(argc, argv, short_options, long_options, NULL)) != -1) {
		switch (opt) {
			//--help
			case 'h':
				print_usage(stdout, EXIT_SUCCESS);
				break;
				
			//--format
			case 'f':
				_format = argv[optind - 1];
				break;
				
			//--to-jalali
			case 'j':
				_pjdate = gregorian_to_jalali(atoi(_substring(argv[optind - 1], 0, 4)),
										     atoi(_substring(argv[optind - 1], 5, 2)),
											 atoi(_substring(argv[optind - 1], 8, 2)));
				break;
				
			//--to-gregorian
			case 'g':
				_pjdate = jalali_to_gregorian(atoi(_substring(argv[optind - 1], 0, 4)),
										     atoi(_substring(argv[optind - 1], 5, 2)),
											 atoi(_substring(argv[optind - 1], 8, 2)));
				break;
				
			//--compare
			case 'c':
				_pjdate = compare_pjdate(argv[optind - 1]);
				break;
				
			//--reference
			case 'r':
				if (_file_exist(argv[optind - 1])) {
					_pjdate = file_modification_date(argv[optind - 1]);				
				} else {
					print_error("Referenced file does not exist.", 1);
				}
				break;
				
			//-FIXME --difference
			case 'd':
				//_pjdate = pjdate_difference(argv[optind - 1]);				
				break;
				
			//--version
			case 'v':
				print_version();
				break;
				
			default:
				print_usage(stderr, EXIT_FAILURE);
				exit(EXIT_SUCCESS);
				break;
		}
	}
	
	print_pjdate(_pjdate, _format);
	
	if (optind < argc) {
		fprintf(stderr, "Expected argument after options.\n");
		exit(EXIT_FAILURE);
	}

	
	return EXIT_SUCCESS;
}

# pjdate
The persian jalali calendar date tool for GNU command line.

Display persian date in jalali calendar command line tool.
Usage: pjdate [OPTION]... [+FORMAT]
  -f   --format           Formats output with the given pattern.
  -j   --to-jalali        Converts given gregorian date to persian jalali date.
                          The format must be like this: 'YYYY-MM-DD'
  -g   --to-gregorian     Converts given persian jalali date to gregorian date.
                          The format must be like this: 'YYYY-MM-DD'
  -c   --compare          Will compare two different persian jalali date.
                          this option returns the bigger date.
                          The format must be like this: 'YYYY-MM-DD:YYYY-MM-DD'
  -r   --reference        Display the last modification time of FILE in jalali date.
       --help             Display this usage information and exit.
       --version          Output version information and exit.

FORMAT controls the output. Interpreted sequences are:
  '%a'   locale's abbreviated weekday name.
  '%A'   locale's full weekday name.
  '%B'   locale's full month name.
  '%d'   day of month (e.g., 14).
  '%D'   day of month with leading zero (e.g., 05).
  '%m'   month (1..12).
  '%M'   month with leading zero (01..12).
  '%y'   Two digit year with leading zero.
  '%Y'   Four digit year.
  '%j'   day of year (1..366).
  '%u'   day of week (1..7).
  '%U'   week number of year.

Examples:
   To get current persian jalali date issue the following:

   $ pjdate 

   To convert persian jalali date to gregorian date issue the following:

   $ pjdate -g '1395-09-20'

   To convert gregorian date to persian jalali date issue the following:

   $ pjdate -j '2016-12-20'

   To change the format of the output issue the following:

   $ pjdate -f '%y-%m-%d' 

   To get last modification date in persian jalali calendar issue the following:

   $ pjdate -r '~/PATH/TO/FILE'

/* rewrite routine of day_of_year and month_date using pointers(discuss) */
/* 25.01.2017 6:10pm to 7:00 pm
   27.01.2017 2:10pm to      pm	*/

#include<stdio.h>
static char daytab[2][3] = {{0,31,28,31,30,31,30,31,31,30,31,30,31}, {0,31,29,31,30,31,30,31,31,30,31,30,31}};
int day_of_year(int year, int month, int day)
{
	int leap, i;
	
	leap = year%4 == 0 && year % 100 != 0 || year%400 == 0;
	for (i = 1, daytab[leap]++; i < month; i++, daytab[leap]++)
		day += (*daytab[leap]);
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap, i;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1, daytab[leap]++; yearday > daytab[leap]; i++, daytab[leap]++)
		yearday -= (*daytab[leap]);
	*pmonth = i;
	*pday = yearday;
}

void main()
{
	int month;
	int day;
	int yearday;
	printf("yearday(1998, 7, 30) = %d\n", (yearday=day_of_year(1998,7,30)));
	month_day(1998, yearday, &month, &day);
	printf("yearday : %d month : %d day : %d", yearday, month, day); 
}	
		

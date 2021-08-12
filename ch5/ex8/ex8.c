/* there is no error checking in function.remedy this defect */
/* 25.01.2017 4:45pm to  5:232pm*/

#include<stdio.h>
static int daytab[2][13] ={ {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day)
{
	int leap, i;
	
	leap = year%4 == 0 && year % 100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap, i;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
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
		

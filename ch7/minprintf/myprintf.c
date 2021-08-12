#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<ctype.h>
void myprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int ival, width, precision, adjust;
	double dval;

width = precision = adjust = 0;

	va_start(ap, fmt);

	for(p = fmt; *p != '\0'; p++)
	{
		if(*p != '%')
		{
			putchar(*p);
			continue;
		}
		if(*++p == '-')
			adjust = 1;	//set to left
		while(isdigit(*++p))
			width = width * 10 + (*p - '0');
		if(*p == '.')
		{
			while(isdigit(*++p))
				precision = precision * 10 + (*p - '0');
		}

		printf("adjust = %d, width = %d, precision = %d\n", adjust, width, precision);
		switch(*p)
		{
		case 'i':
		case 'd': ival = va_arg(ap,int);
				  printf("%d", ival);
				  break;
		case 'f': dval = va_arg(ap, double);
				  printf("%f",dval);
				  break;
		case 's': sval = va_arg(ap, char *);
				  printf("%s", sval);
				  break;
		case '%': printf("%%");
				  break;
		default : putchar(*p);

		}
	}
	va_end(ap);
}

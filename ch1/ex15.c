/* Conversion of temperature from fahrenheit to celsius using functions */

#include<stdio.h>

float convert(int);

int main()
{
	int lower,upper,step,count;
	float celsius;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	for (count = lower; count <= upper; count = count + step)
		printf("%3d %7.2f\n", count, convert(count));
	return 0;
}

float convert(int fahrenheit)
{
	float celsius;
	
	celsius = (5.0/9.0) * (fahrenheit - 32.0);
	return celsius;
}

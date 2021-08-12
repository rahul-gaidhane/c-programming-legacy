/*
 * main.c
 *
 *  Created on: 28-Mar-2017
 *      Author: rahul
 */
#include<stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	void diff(FILE *, FILE *);

	fp1 = fopen(*++argv, "r");
	fp2 = fopen(*++argv, "r");

	diff(fp1, fp2);

	fclose(fp1);
	fclose(fp2);

	return 0;
}


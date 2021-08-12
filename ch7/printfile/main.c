/*
 * main.c
 *
 *  Created on: 23-May-2017
 *      Author: rahul
 */
#include<stdio.h>
#define LINESIZE 100
#define LINESPERPAGE 20

int main(int argc, char *argv[])
{
	char line[LINESIZE];
	FILE *fp;
	int count;
	int page_count = 1;

	if(argc == 1)
		printf("ERROR : too few arguments");
	else
	{
		while(--argc > 0)
		{
			count = 1;
			fp = fopen(*++argv,"r");
			//printf("filename : %s", *argv);

			while(fgets(line, LINESIZE, fp) != NULL)
			{
					if(count == 1)
					{
						printf("\n****************************************************************\n\n");
						printf("%s %d\n\n", *argv, page_count++);
						printf("%s",line);
						count++;
					}
					else if(count == LINESPERPAGE)
					{
						printf("%s\n", line);
						count = 1;
					}
					else
					{
						printf("%s",line);
						count++;
					}

			}
			fclose(fp);
		}
	}
}

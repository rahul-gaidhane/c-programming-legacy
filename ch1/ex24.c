/* Write a program to check a C program for rudimentary syntax error like 
   unbalanced parantheses, brackets and braces. Don't forget about quotes
   , both single and double, escape sequences, and comments.              */
/* 6.10.16	6:30 pm */ 	  

#include<stdio.h>
#define ON 1
#define OF 0

int main()
{
    char c;
    int count[10], i; //slash, backslash;
	
 //   slash = backslash = OFF;	
	
    for (i = 0; i < 10; i++)
        count[i] = 0;
	
    while ((c = getchar()) != '\0')
    {
	switch(c)
        {
            case ('(' || ')')			:count[0];
	                               	 	 continue;
	    case ('[' || ']')			:count[1];
					 	 continue;
	    case ('{' || '}')			:count[2];
					 	 continue;
	    case (''')				:count[3];
					 	 continue;
	    case ('"')				:count[4];
					 	 continue;
	  //  case ('/')	 			:slash = ON;
	  //     				 	 continue;
	  //   case ('\')	 			:backslash = ON;
	  //				 	         continue;
	    default		 		:continue;
	}
    }
    if ((count[0] % 2) == 0)
        printf("Unbalanced Parantheses");
    if ((count[1] % 2) == 0)
        printf("Unbalanced brackets");
    if ((count[2] % 2) == 0)
	printf("Unbalanced braces");
    if ((count[3] % 2) == 0)
 	printf("Unbalanced Single quotes");
    if ((count[4] % 2) == 0)
	printf("Unbalnced double quotes");
} 			

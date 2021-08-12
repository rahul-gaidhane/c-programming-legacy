/* To print input one word per line */

#include<stdio.h>
#define IN 1
#define OUT 0

int main()
{ 
	int state,i;
 	char c;

	i = 0;
        
   	/* get input */  
 	while ((c = getchar()) != EOF)
        {
       		state = IN; 
        	if (c == ' ' || c == '\t' || c == '\\')
                {      	
			i++;
                        if (i == 1)
			{	
 				printf("\n");
			} 
            	        state = OUT;
             	}
                else if (state == IN)		
                {	i = 0;
                	putchar(c);
                }
	}
 	return 0;
}

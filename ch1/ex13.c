/* To print histogram of length of words */

#include<stdio.h>
#define IN 1
#define OUT 0

int main()
{
 	int nw, state, c, nwhite, wlen, i, j;
        int alen[100];

        wlen = nwhite = i = nw = 0; 
        state = IN;
        
 	while ((c = getchar()) != EOF)
        {	
		if (c == ' ' || c == '\n' || c == '\t') 
                {       
                        nwhite++;
			if (nwhite == 1)
                        {    
          			alen[i] = wlen; 
                		state = OUT;
				wlen = 0;
				i++;	
                                nw++;
			}
                }
                else 
                {
			state = IN; 
			nwhite = 0;
		}
                if (state == IN) 
			wlen++;
	}
		
        for (i = 0; i < nw; i++)
        {
		printf("\n");
		for (j = 1; j <= alen[i]; j++)
                        printf("=");
        }   
        printf("\n");
	return 0;
}

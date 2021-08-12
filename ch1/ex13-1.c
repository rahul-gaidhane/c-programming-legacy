/*To print histogram in vertical orientation*/

#include<stdio.h>
#define OUT 1
#define IN 0

int main()
{
	int c, state, nwhite, wlen, nw, i, j, k, wlng;
        int alen[100];
        int temp[100]; 
	
	nwhite  = nw = i = k = wlng = 0;   
        wlen = 0; 

        while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{	
			nwhite++;
			if (nwhite == 1)
			{
				alen[i] = wlen;
				wlen = 0;
				state = OUT;
				i++;	
				++nw;
				
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
		if(wlng < alen[i])
		wlng = alen[i];
   	}
        printf("\n");
        for (i = 0; i < nw; i++)
        { 
		temp[i] = wlng - alen[i];
	}
	printf("\t\t");
	
	printf("scale:on x-axis:\\t = one word\n");
	printf("\t\t      on y axis:1 letter = ||");	  
 	
	printf("\n");
        for (i = 0; i < wlng; i++)
	{
		for(j = 0, k = 0; j < nw; j++, k++)
		{
			if (i >= temp[k])
				printf("||");
                	printf("\t"); 
		}
		printf("\n");
	}
	printf("1st\t2nd\t3rd");
        
	for(i=4; i<=nw; i++)
	printf("\t%dth", i); 	       
	printf("\n");
	
	printf("Words\n");
		
        return 0;   
}
		    

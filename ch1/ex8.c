/* count blanks, tabs and newlines */

#include<stdio.h>
int main()
{ 
  long c, nb, nt, nl;

  nb = nt = nl = 0;
  while ((c = getchar()) != EOF)
  {  if ( c == ' ' )
     ++nb;
     if ( c == '\n')
     ++nl;
     if ( c == '\t')
     ++nt;
	putchar(c);
  }
  printf("no. of blanks = %ld\nno. of tabs = %ld\nno. of newlines = %ld",nb,nt,nl);
  return 0;
}  

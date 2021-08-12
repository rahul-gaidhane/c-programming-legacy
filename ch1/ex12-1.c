/* print the output one word per line */

#include<stdio.h>

int main()
{
 int c;

 while ((c = getchar()) != EOF)
 {
  if (c == ' ')
  printf("\n");
  else 
  putchar(c);
 } 
 return 0;
}

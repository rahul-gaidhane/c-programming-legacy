/*Replace string of one or more blank by a single blank */

#include<stdio.h>

int main()
{
 int c,nb;

 nb = 0;
 
 while ((c = getchar()) != EOF)
 {
  if (c == ' ')
  nb++;
  else 
  nb = 0;
  if (nb == 1)
  putchar(c);
  else if (nb >=2)
  ; 
  else
  putchar(c);
 }
 return 0;
}

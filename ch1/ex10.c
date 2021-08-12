/* replace tab by \t, backspace by \b, backlash by \\ */

#include<stdio.h>

int main()
{ 
 int n,nt,nb,ns;
 
 nt = nb = ns = 0;
 
 while ((n = getchar()) != EOF)
 { 
  if (n == '\t')
  { 
   printf("\\t");
   nt++;
  }
  else if(n == '\b')
  {
   printf("\\b");
   nb++;
  }
  else if (n == '\\')
  {
  printf("\\\\");
  ns++;
  }
  else
  putchar(n);
 }   
 printf("\nnt = %d\nnb = %d\nns = %d",nt,nb,ns);
 return 0;

}

/* count lines, words, and characters in input */

#include<stdio.h>
#define IN 1
#define OUT 0

int main()
{
 int c, nl,nw,nc, state;

 state = OUT;
 nl = nw = nc = 0;
 while ((c = getchar()) != EOF)
 {
  ++nc;
  if (c == '\n')
  ++nl;
  if (c == ' ' || c == '\n' || c == '\t')
  state = OUT;
  else if (state == OUT)
  {
   state = IN;
   ++nw;
  }
 }
 printf("number of lines : %d\nnumber of words : %d\nnumber of characters : %d\n", nl, nw, nc);
 return 0;
}
 

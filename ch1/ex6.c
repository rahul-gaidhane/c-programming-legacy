/* Verify the expression "getchar() != EOF" */
 
#include<stdio.h>
int main()
{ int k;
  
  k = (getchar() != EOF);//verification
  printf("The value of \"getchar() != EOF\" is %d\n", k);
  printf("Verified\n");
  return 0;
}
 

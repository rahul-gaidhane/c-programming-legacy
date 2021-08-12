/* Temperature conversion program in reverse order */

#include<stdio.h>
int main()
{ int fahr, lower = 0, upper = 30, step = 20;
  float celsius;//dynamic intialization
  
  for (fahr = upper; fahr >= lower; fahr -= step)//condition
  { celsius = (5.0 / 9.0) * (fahr - 32);
    printf("%3d %6.2f\n", fahr, celsius);
  }         
  return 0;
}

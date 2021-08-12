/* Celsius to Fahrenheit */

#include<stdio.h>
int main()
{ int celsius, lower = 0, upper = 100, step = 10;
  float fahr = 0.0; //intialization
  
  celsius=lower;
  
  while (celsius <= upper) //condition
  { fahr = ((9.0 * celsius) / 5.0) + 32;
    printf("%3d %6.2f\n", celsius, fahr); 
    celsius = celsius + step;//increment 
  }
  return 0;
}

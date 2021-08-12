#include<stdio.h>
int main()
{ float celsius;
  float fahr;
  float lower,upper,step;
  lower=0;
  upper=300.66;
  step=20;
  
  fahr=lower;
  printf("Temperature conversion\n");
  while (fahr<=upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%5.0f %2.4f\n",fahr,celsius);
    fahr = fahr + step; 
  }
}

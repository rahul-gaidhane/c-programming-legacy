/* check floats constants */
#include<stdio.h>
#include<float.h>

int main()
{
//	FLT_ROUNDS = 0;
 	printf("FLT_RADIX	: %d\n",FLT_RADIX);
	printf("FLT_ROUNDS	: %d\n",FLT_ROUNDS);	
  	printf("FLT_DIG		: %d\n",FLT_DIG);
	printf("FLT_EPSILON	: %f\n",FLT_EPSILON);
	printf("FLT_MANT_DIG	: %d\n",FLT_MANT_DIG);
	printf("FLT_MAX		: %f\n",FLT_MAX);
	printf("FLT_MAX_EXP	: %d\n",FLT_MAX_EXP);
	printf("FLT_MIN		: %f\n",FLT_MIN);
	printf("FLT_MIN_EXP	: %d\n",FLT_MIN_EXP);
	printf("DBL_DIG		: %d\n",DBL_DIG);
	printf("DBL_EPSILON	: %f\n",DBL_EPSILON);
	printf("DBL_MANT_DIG	: %d\n",DBL_MANT_DIG);
	printf("DBL_MAX		: %f\n",DBL_MAX);
	printf("DBL_MAX_EXP	: %d\n",DBL_MAX_EXP);
	printf("DBL_MIN		: %f\n",DBL_MIN);
	printf("DBL_MIN_EXP	: %d\n",DBL_MIN_EXP);
//	printf("%e to %e\n",FLT_MAX,FLT_MIN);

//	for (i = 2; i > 1; i++)
//		;
//	printf("%f",i);
	return 0;
}

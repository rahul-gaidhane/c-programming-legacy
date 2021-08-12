#include<stdio.h>
void a(void);
void b(void);
int x = 56;
void main() {
	printf("main = %d\n",x);
	a();
	b();
}
void a(void)
{
	printf("a = %d\n",--x);
	b();
	printf("a = %d\n",--x);
}
void b(void)
{
	printf("b = %d\n",--x);
}

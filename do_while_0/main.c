/*
 * Why we need to use do {...} while (0) in macros
 * https://hownot2code.com/2016/12/05/do-while-0-in-macros/
 */
#include <stdio.h>

#define foo(x) do { x *= 2; x += 1; } while (0)

#define foo1(x) x *= 2; x += 1;
#define foo2(x) {x *= 2; x += 1;}
int main(void)
{
	/*
	 * do {...} while(0) in macros make it behave like function
	 */
	int x = 1;
	foo(x);
	printf("Ans: %d, The macro we want is to double x and plus one\n", x);

	x = 1;
	foo1(x);
	printf("Ans: %d, Two separate program lines work well, so far\n", x);

	x = 1;
	if (0)
		foo1(x);
	printf("Ans: %d, Bad expansion in conditional sentance\n", x);

	x = 1;
	if (0)
		foo2(x);
	printf("Ans: %d, The modified version with curly-brackts work well, so far\n", x);

#if 0
	x = 1;
	if (1)
		foo2(x); /* Syntax error here */
	else
		x += 9;
#endif
	x = 1;
	if (1)
		foo(x);
	else
		x += 9;
	printf("Ans: %d, do {...} while(0) ensures it always behaves the same\n", x);

} 

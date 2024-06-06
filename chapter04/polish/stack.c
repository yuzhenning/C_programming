/*	University of Macau -- Zhenning Yu (Justin)	*/

#include<stdio.h>
#include"calc.h"

#define MAXVAL 100

static int sp = 0;
static double stack[MAXVAL];

/*	push : push f onto value stack */
void push(double f)
{
	if(sp < MAXVAL)
		stack[sp++] = f;
	else
		printf("error: stack full, can't push %g\n",f);
}

/*	pop : pop and return top value from stack */
double pop(void)
{
	if(sp > 0)
		return stack[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}


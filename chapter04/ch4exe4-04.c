/*	University of Macau -- Zhenning Yu (Justin)
	Exercise 4-04
	Man: added commands: print stack without poping; clear stack; swap top two elements
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'
#define BUFSIZE 100

/*int getline(char line[], int lim); */

int getop(char[]);
void push(double);
double pop(void);

int getch(void);
void ungetch(int);

int sp = 0;
double stack[MAXVAL];	/* pointer */
char buf[BUFSIZE];	/* memory */
int bufp = 0;

/*	reverse Polish calculator     */
int main()
{
	int type;
	double op2, op1;
	char s[MAXOP];

	while((type = getop(s)) != EOF){
		switch (type){
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();		/*12-,  op2 = 2 */
			push(pop() - op2);	/*    pop() = 1 */
			break;
		case '/':
			op2 = pop();
			if(op2 != 0.0)
				push(pop() /op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if(op2 != 0.0)
				push( fmod(pop() , op2) );
			else
				printf("error: zero divisor\n");
			break;
		case 'p':	/*printf stack without pop */
			op2 = pop();
			printf("\t%0.8g",op2);
			push(op2);
			break;
		case 'd':	/* duplicate top item */
			op2 = pop();
			push(op2);
			push(op2);
			break;
		case 's':	/* swap top two elements */
			op1 = pop();
			op2 = pop();
			push(op1);
			push(op2);
			break;
		case 'c':	/* clear the stack */
			sp = 0;
			break;

		case '\n':
			printf("\t%1.0g\n",pop());	/* a new line */
			break;
		default:
			printf("error: unknown command %s \n",s);
			break;
		}
	}
	return 0;
}

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

/*	getop : get next operator or numeric operand */
int getop(char s[])
{
	int i , c;
	i = 0;
	while((s[0] = c = getch()) == ' ' || c == '\t')
		;	/*pass blank space*/
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')	/* considering negative case */
		return c;

	if (c == '-'){
		/*when c == '-', check next stack is num/point or not  */
		if (isdigit(c = getch()) || c == '.' )
			s[++i] = c;	/*  getch: get a pushed back char*/
		else {
			if (c != EOF)
				ungetch(c);
			return '-';
		}
	}

	if (isdigit(c))		/*collect integer part*/
		while (isdigit(s[++i] = c = getch()));
	if (c == '.')		/*collect fraction part*/
		while (isdigit(s[++i] = c = getch()));

	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

int getch(void)
{
	return(bufp > 0) ? buf[--bufp] : getchar() ;
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters \n");
	else
		buf[bufp++] = c;
}


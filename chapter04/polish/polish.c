/*	University of Macau -- Zhenning Yu (Justin)	*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'
#define BUFSIZE 100

/* subfunction definition */
int getop(char[]);

void push(double);
double pop(void);

int getch(void);
void ungetch(int);

/* define variables */
int sp = 0;
double stack[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

/*	reverse Polish calculator */
int main()
{
	int type;
	double op2;
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
				push( fmod(pop(), op2) );
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n",pop());	/* a new line */
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

/* Print stack without pop */
/*
void printstack(void)
{
	printf("%s",stack());
}
*/

/* Copy  stack without pop */
/* Duplicate stack */
/* Swap two elements */
/* clear stack */

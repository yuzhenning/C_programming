/*	University of Macau -- Zhenning Yu (Justin)
	Exercise 4-07
	Man: use getline function
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXOP 100
#define MAXVAL 100
#define MAXLINE 100
#define NUMBER '0'
#define CAL 'n'
#define BUFSIZE 100

void ungets(char s[]);
void mathfunc(char s[]);
int getline(char line[], int lim);

int getop(char[]);
void push(double);
double pop(void);

int sp = 0;
double stack[MAXVAL];	/* pointer */
char buf[BUFSIZE];	/* memory */
int bufp = 0;

int li = 0;		/* input line index */
char line [MAXLINE];	/* one input line */

/*	reverse Polish calculator     */
int main()
{
	int type, type_r = 0, i;
	double op2, op1, ans;
	char s[MAXOP];
	double variable[26];

	for( i = 0; i < 26; i++ )
		variable[i] = 0.0;

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
		case '=':	/* give data to variables :3 A = */
			op2 = pop();
			if(type_r >= 'A' && type_r <= 'Z')
			{
/*				printf("%c\n",type);
*/				variable[type_r - 'A'] = pop();  /* save data to relative add : 3*/
				push(variable[type_r - 'A']);
			}
			else
				printf("Unknown variable name\n");
			break;

		case '\n':
			ans = pop();
			printf("\t%.8g\n",ans);	/* a new line, printf result */
			break;
		default:
			/* considering upper letter A to Z as variables*/
			if (type >= 'A' && type <= 'Z')
			{
/*				printf("upper letter: %c\n",type);
*/				push(variable[type - 'A']);
			}
			else
				printf("error: unknown command %s \n",s);
			break;
		}
		type_r = type;
	}
	return 0;
}

/*	push : push f onto value stack */
void push(double f)
{
	if(sp < MAXVAL)
	{
/*		printf("push:%g\n",f);
*/		stack[sp++] = f;
	}
	else
		printf("error: stack full, can't push %g\n",f);
}

/*	pop : pop and return top value from stack */
double pop(void)
{
	if(sp > 0)
	{
/*		printf("pop:%g\n",stack[sp-1]);
*/		return stack[--sp];
	}
	else
	{
/*		printf("error: stack empty\n");
*/		return 0.0;
	}
}

/*	getop : get next operator or numeric operand */
int getop(char s[])
{
	int i , c;
	i = 0;

	if(line[li] == '\0')
	{
		if(getline(line, MAXLINE) == 0)
			return EOF;
		else
			li = 0;
	}
	/* pass blank space*/
	while((s[0] = c = line[li++]) == ' ' || c == '\t')
		;
	s[1] = '\0';

	/* considering negative case */
	if (!isdigit(c) && c != '.' )
		return c;
	i = 0;

	/* collect integer or frac part*/
	if (isdigit(c) )
		while (isdigit(s[++i] = c = line[li++] ));
	if (c == '.')
		while (isdigit(s[++i] = c = line[li++] ));

	s[i] = '\0';
	li--;
	return NUMBER;
}


/* added sin cos exp pow functions */
/*
void mathfunc(char s[])
{
	double op2, pi = 3.14159265;
	if (strcmp(s, "sin" ) == 0)
		push (sin(pop()/180*pi));
	else if (strcmp(s, "cos" ) == 0)
		push (cos(pop()/180*pi));
	else if (strcmp(s, "tan" ) == 0)
		push (tan(pop()/180*pi));
	else if (strcmp(s, "asin" ) == 0)
		push (asin(pop()/180*pi));
	else if (strcmp(s, "acos" ) == 0)
		push (acos(pop()/180*pi));
	else if (strcmp(s, "atan" ) == 0)
		push (atan(pop()/180*pi));
	else if (strcmp(s, "pow" ) == 0)
	{
		op2 = pop();
		push (pow(pop(), op2));
	}
	else if (strcmp(s, "exp" ) == 0)
		push (exp(pop()));
	else if (strcmp(s, "ans" ) == 0)
		push(stack[sp]);
	else
		printf("Not support mathfunc: %s",s);
}
*/

/*	push string back onto the input */
/*
void ungets(char s[])
{
	int len = strlen(s);
	void ungetch(int);

	while (len > 0)
		ungetch(s[--len]);
}
*/

/* getline subfunction */
int getline(char line[], int lim)
{
	int c, i ;
	i = 0;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		stack[i++] = c;
	if(c == '\n')
		stack[i++] = c;
	stack[i] = '\0';
	return i;
}

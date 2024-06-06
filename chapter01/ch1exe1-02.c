/* 	This is an exercise of c programming language book chapter1 	*/
/* 	Author Justin Yu --- University of Macau	*/

#include <stdio.h>

int main()
{
	printf("character \\a as following-->\a<--end!\n");
	printf("character \\b as following-->\b<--end!\n");
	printf("character \\f as following-->\f<--end!\n");
	printf("character \\n as following-->\n<--end!\n");
	printf("character \\r as following-->\r<--end!\n");
	printf("character \\t as following-->\t<--end!\n");
	printf("character \\v as following-->\v<--end!\n");
	printf("character \\\\ as following-->\\<--end!\n");
	printf("character \\? as following-->\?<--end!\n");
	printf("character \\' as following-->\'<--end!\n");
	printf("character \\\" as following-->\"<--end!\n");
	printf("character \\012 as following-->%d<--end!\n",'\012');
	printf("character \\xab as following-->%d<--end!\n",'\xab');

	printf("\n---Program End!---\n");
	return 0;
}

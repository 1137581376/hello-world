#include<stdarg.h>

int add(int c, ...)
{
	va_list ap;
	va_start(ap, c);
	int sum = 0;
	for(int i = 0; i < c; ++i) sum += va_arg(ap, int);
	return sum;
}	

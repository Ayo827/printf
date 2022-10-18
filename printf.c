#include<stdio.h>
#include<stdarg.h>
#include <limits.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>
/**
* _printf - check code
* @format: This is character to be printed to stdout
* Description: This function is to perform functions of printf
* Return: integer
**/
int _printf(const char *format, ...)
{
if (format == NULL)
return 0;
va_list valist;
va_start(valist, format);
int num = 0;
char *token = NULL;
int i = 0;
int len = strlen(format);
int nprinted = 0;
int found = 0;
while ( i < len )
{
num = 0;
found = 0;
token = NULL;
if ((format[i] == '%') && ((i + 1) < len))
{
switch (format[i+1])
{
case 'd':
{
found = 1;
int str[40];
int j = 0;
num = va_arg(valist, int);
int temp = num;
if (num < 0)
num = -num;
while (num != 0)
{
str[j++] = (num % 10);
num /= 10;
}
if (temp < 0)
str[j++] = '-';
nprinted += j;
j--;
while (j >= 0)
{
if (str[j] != '-')
putchar(str[j--] + '0');
else
putchar(str[j--]);
}
}
break;
case 's':
{
found = 1;
token = va_arg(valist, char *);
if ( token != NULL )
{
int j = 0;
while (token[j] != NULL)
{
nprinted++;
putchar(token[j]);
j++;
}
}
}
break;
}
if (found != 0)
{
i += 2;
continue;
}
}
putchar(format[i]);
nprinted++;
i++;
}
va_end(valist);
return nprinted;
}

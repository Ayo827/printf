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
int num;
char *token;
int i;
int len;
int nprinted;
int found;
va_list ap;
int str[40];
int temp;
int j = 0;
if (format == NULL)
return 0;
va_start(ap, format);
num = 0;
token = "";
i = 0;
len = strlen(format);
nprinted = 0;
found = 0;
while ( i < len )
{
num = 0;
found = 0;
token = "";
if ((format[i] == '%') && ((i + 1) < len))
{
switch (format[i+1])
{
case 'd':
{
found = 1;
j = 0;
num = va_arg(ap, int);
temp = num;
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
token = va_arg(ap, char *);
if ( token != "" )
{
int j;
int tokenLength;
tokenLength = strlen(token);
j = 0;
while (j < tokenLength)
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
va_end(ap);
return nprinted;
}

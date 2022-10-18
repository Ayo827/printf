#include<stdio.h>

#include<stdarg.h>

#include <limits.h>

#include <string.h>

#include "main.h"

int _printf(const char* format,...)

{

char *character;

int i;

char *s;

int length;

va_list ap;

va_start(ap, format);

for(character = format; *character != 0; character++)

{

while(*character != %)

{

putchar(*character);

character++;

}

character++;

switch(*character)

{

case c : i = va_arg(ap,int);

putchar(i);

length = strlen(i);

return (length);

break;

case s: s = va_arg(ap,char *);

puts(s);

length = strlen(s);

return length;

break;

case d: i = va_arg(ap,int);

if (i<0)

{

i = -i;

putchar(-);

puts(convert(i,10));

return convert(i,10);

}

else

{

puts(convert(i,10));

return  puts(convert(i,10));

}

break;

}

}

va_end(ap);

}

char *convert(unsigned int num, int base)

{

static char Representation[]= "0123456789ABCDEF";

static char buffer[50];

char *ptr;

ptr = &buffer[49];

*ptr = 0;

do

{

*--ptr = Representation[num%base];

num /= base;

}

while(num != 0);

return(ptr);

}



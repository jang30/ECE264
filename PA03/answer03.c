#include "answer03.h"
#include <string.h>

char * strcat_ex(char * * dest, int * n, const char * src)
{
  char new ;
  new = strcat( * dest, * src);
  
  return (char) new;
}

char * * explode(const char * str, const char * delims, int * arrLen)
{
  char * ret = str;
  for(ret = str; *str != '\0';++str)
    {
      if(*str == delims)
	{
	  *str = '\001';
	}
    }
  return ret;
}

char * implode(char * * strArr, int len, const char * glue)
{
  return 0;
}

void sortStringArray(char * * arrString, int len)
{
}

void sortStringCharacters(char * str)
{
}

void destroyStringArray(char * * strArr, int len)
{
}

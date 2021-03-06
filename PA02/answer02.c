#include "answer02.h"

size_t my_strlen(const char * str)
{
   size_t count = 0;
   while (str[count] != '\0')
   {
     count ++;
   }           
   return count;
}

int my_countchar(const char * str, char ch)
{
  int count = 0;
  while (*str)
    {
      if(*str == ch) count ++;
      str++;
    }
  return count;
}

char * my_strchr(const char * str, int ch)
{
  if(*str == ch) return (char*) str;
   while (*str++)
    {
      if(*str == ch) return (char*) str;
    }
   return NULL;
}

char * my_strrchr(const char * str, int ch)
{
  char *save;
  char c;
  int len;
  len = (int) my_strlen(str);
  
  for (save = 0; (c = *str); str++)
    {
      if (c == ch)
	save = (char *) str;
    }
  
  if (ch == '\0')
    {
      return (char*) str;
    }
      return save;
}

char * my_strstr(const char * haystack, const char * needle)
{
  if (*needle == 0) return (char*) haystack;
  while (*haystack++)
    {
      if(*haystack == *needle) return (char*) haystack;
    }
   return NULL;
}

char * my_strcpy(char * dest, const char * src)
{ 
  char * new = dest;
  while ((* new++ = * src++) !=0);
  return (dest);
}

char * my_strcat(char * dest, const char * src)
{
  size_t i,j;
  for (i=0; dest[i] != '\0'; i++);
  for (j=0; src[j] != '\0'; j++)
       dest[i+j] = src[j];
  dest[i+j] = '\0';
  return dest;
}

int my_isspace(int ch)
{
  int num = 0;
  char asc = (char) ch;
  if ((asc == '\t')||(asc == '\n')||(asc == '\v')||(asc == '\f')||(asc == '\r')||(asc == ' ')) num = 1;
   return num;
}

int my_atoi(const char * str)
{
  int i,ret = 0,sign = 1;
  for(i=0;str[i];i++)
    {
      if(my_isspace(str[i]) == 1)
	continue;
      else if(str[i]=='-') sign=-1;
      else break;
    }
       
  for(;str[i] && str[i]>='0' && str[i]<='9';i++)
    ret=ret*10 + str[i]-'0';
  
  if (sign == -1) return -ret;
  else return ret  ;
}

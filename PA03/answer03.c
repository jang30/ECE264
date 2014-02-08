#include "answer03.h"
#include <string.h>

char * strcat_ex(char * * dest, int * n, const char * src)
{
  size_t src_len = strlen(src);
  size_t dest_len = *dest == NULL ? 0 : strlen(*dest);
  if (* dest == NULL || src_len + dest_len + 1 >= *n) {
    *n = 1+2 * (src_len + dest_len);
    char * buffer = malloc(*n * sizeof(char));
    * buffer = '\0';
    if (*dest != NULL) strcpy(buffer, *dest);
    free(*dest);
    *dest = buffer;
  }
  strcat(*dest, src);
  return *dest;
}

char * * explode(const char * str, const char * delims, int * arrLen)
{
  *arrLen = 1;
  const char *pos = str;
  pos = str;
  while (*pos != '\0') {
    if (strchr(delims, *pos)) (*arrLen)++;
  }
  char **string_list = malloc(*arrLen * sizeof(char *))
  int index = 0;
  const char *start = str;
  pos = str;
  while (*pos != '\0') {
    if (strchr(delims, *pos)) {
      int len = pos - start;
      string_list[index] = malloc((len + 1) * sizeof(char));
      memcpy(string_list[index], start, len * sizeof(char));
      string_list[index][len] = '\0';
      index++;
      start = pos +1;
    }
    pos++;
  }
  int len = pos - start;
  string_list[index] = malloc((len + 1) * sizeof(char));
  memcpy(string_list[index], start, len * sizeof(char));
  string_list[index][len] = '\0';
  
  return string_list;
}

char * implode(char * * strArr, int len, const char * glue)
{
  const char * dest;
  
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

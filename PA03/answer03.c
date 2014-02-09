#include "answer03.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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
    pos ++;
  }
  char **string_list = malloc(*arrLen * sizeof(char *));
  int ind = 0;
  const char *start = str;
  pos = str;
  while (*pos != '\0') {
    if (strchr(delims, *pos)) {
      int len = pos - start;
      string_list[ind] = malloc((len + 1) * sizeof(char));
      memcpy(string_list[ind], start, len * sizeof(char));
      string_list[ind][len] = '\0';
      ind++;
      start = pos +1;
    }
    pos++;
  }
  int len = pos - start;
  string_list[ind] = malloc((len + 1) * sizeof(char));
  memcpy(string_list[ind], start, len * sizeof(char));
  string_list[ind][len] = '\0';

  return string_list;
}

char * implode(char * * strArr, int len, const char * glue)
{
  int i;
  char * str = NULL;
  int leng = len;
  size_t tot_len = 0;
  
  for (i = 0; i < len; i++) {
    tot_len += strlen(strArr[i]);
    tot_len++;
    tot_len += strlen(glue) * (len -1);
  }
  str = (char*)malloc(tot_len);
  str[0] = '\0';
  
  for (i = 0; i < len; i++) {
    str = strcat_ex(&str, &leng, strArr[i]);
    if (i< (len-1)) {
      str = strcat_ex(&str, &leng, glue);
    }
  }
  return (char*) str;
}

int strcmpvoid(const void *a, const void *b)
{
  return strcmp(*(char * const *) a, * (char * const *) b);
}

void sortStringArray(char * * arrString, int len)
{
  qsort(arrString, len, sizeof(char*), strcmpvoid);
}

void sortStringCharacters(char * str)
{
  int i, j, len;
  char tmp;
  len = strlen(str);
  for(i=0; i<len-1;i++) {
    for(j=i+1; j<len;j++) {
      if (str[i] > str[j]) {
	tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
      }
    }
  }
}

void destroyStringArray(char * * strArr, int len)
{
  int i;
  if (strArr != NULL){
    for(i = 0; i<len; i++){
      free(strArr[i]);
    }
    free(strArr);
  }
}

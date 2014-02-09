#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
  printf("Check if functions work.\n"
	 "\n");
  printf("Explode function checking....\n"
  	 "\n");
  int len;
  char ** strArr = explode("Michin\nSibal Gae jotgatne", " \n\t\v\r\f", &len);
  int i;
  for (i=0;i<len; i++){
    printf("strArr[%d] = %s\n",i,strArr[i]);
  }

  printf("\nImplode function checking....\n"
  	 "\n");
  char *str = implode(strArr, len, ", ");
  printf("%s\n",str);

  printf("\nsortStringArray function checking....\n"
  	 "\n");
  int len2;
  char * * strArr2 = explode("lady beatle brew", " ", &len2);
  sortStringArray(strArr2, len2);
  char * str2 = implode(strArr2, len2, " ");
  printf("%s\n",str2);

  printf("\nsortStringCharacters function checking....\n"
  	 "\n");

  char * s1 = strdup("How did it get so late so soon?");
  sortStringCharacters(s1);
  printf("%s\n",s1);

  printf("\ndestroyStringArray function checking....\n"
  	 "\n");
  int len3;
  const char * abe = "Give me six hours to chop down a tree and I will spend\n"
    "the first four sharpening the axe.";
  char * * strArr3 = explode(abe, "\n ");
  destroyStringArray(strArr3, len3); // cleans memory -- no memory leaks
  destroyStringArray(NULL, 0);
  
  return EXIT_SUCCESS;
}
  

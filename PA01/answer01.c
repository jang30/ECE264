#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
  int i, sum = 0;

    for (i=0; i < len; i++)
    {
      sum = sum + array[i];
    }
 
    return(sum);
}

int arrayCountNegative(int * array, int len)
{
  int i, count = 0;

    for (i=0; i < len; i++)
    {
      if (array[i]<0)
	{
	  count++;
	}
    }

    return(count) ;
}

int arrayIsIncreasing(int * array, int len)
{       
  int i, result = 1;
  for (i = 1; i < len; i++)
    {
      if ((len == 0 || array[i-1] <= array[i]) && result !=0) 
	{
	  result = 1;
	}
      else
	{
	  result = 0;
	}
    }  
    return(result);
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
  int i, index = -1;
  for (i = 0; i < len; i++)
    {
      if(haystack[i] == needle)
	{
	  index = i;
	}
    }
  return(index);  
}

int arrayFindSmallest(int * array, int len)
{
  int i;
  int value = array[0];
  int index = 0;
  for (i = 1; i < len; i++)
     {
       if (array[i] < value)
	 {
	   value = array[i];
	   index = i;
	 }
     }
  return (index);
}

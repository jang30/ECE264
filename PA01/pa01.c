 
#include <stdio.h>
#include <stdlib.h>

// This includes the /definitions/ of the functions that you write
// in this assignment. Including the definitions allows you to use
// the functions in this file.
#include "answer01.h"

void printArray(int * array, int len)
{
    printf("{");
    int ind;
    for(ind = 0; ind < len; ++ind) 
    {
	printf("%d", array[ind]);
	if(ind != len - 1) 
	{
	    printf(", ");
	}
    }
    printf("}");
    // If we don't include a '\n' character, then we need to 
    // include this line to ensure that our output is immediately
    // printed out output.
    fflush(stdout); 
}

void test_arraySum(int * array, int len, int expected)
{
    printArray(array, len);
    int sum = arraySum(array, len);
    printf(". result = %d, expected = %d.", sum, expected);
    if(sum != expected)
	printf(" FAIL");
    printf("\n");
}

void test_00_arraySum()
{
    printf("Testing arraySum(...)\n");

    // Here we use "static initialization" to create an array
    int array1[] = { -4, -1, 0, 1, 5, 10, 20, 21 };
    int len1 = 8;
    int expected1 = 52;
    test_arraySum(array1, len1, expected1);

    // Our functions must always work... even on empty arrays
    int array2[] = {};
    int len2 = 0;
    int expected2 = 0;
    test_arraySum(array2, len2, expected2);

    int array3[] = { -12, -11, -10};
    int len3 = 3;
    int expected3 = -33;
    test_arraySum(array3, len3, expected3);

    int array4[] = { -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    int len4 = 11;
    int expected4 = 0;
    test_arraySum(array4, len4, expected4);


    printf("\n"); // Tidy output is easier to use
}

void test_arrayCountNegative(int * array, int len, int expected)
{
    printArray(array, len);
    int count = arrayCountNegative(array,len); 
    printf(". result = %d, expected = %d.", count, expected);
    if(count != expected)
	printf(" FAIL");
    printf("\n");
}

void test_01_arrayCountNegative()
{
    printf("Testing arrayCountNegative(...)\n");

    int array1[] = { 1, 4, -5, 4 };
    int len1 = 4;
    test_arrayCountNegative(array1, len1, 1);

    int array2[] = {};
    int len2 = 0;
    test_arrayCountNegative(array2, len2, 0);

    int array3[] = { 0, 1, 2, 3, 4 };
    int len3 = 5;
    test_arrayCountNegative(array3, len3, 0);

    int array4[] = { -1, -2, -3, -4 };
    int len4 = 4;
    test_arrayCountNegative(array4, len4, 4);

    // You can add more test-cases here
    // ...

    printf("\n");
}

void test_arrayIsIncreasing(int * array, int len, int expected)
{
    printArray(array, len);
    int result = arrayIsIncreasing(array, len);
    printf(". result = %d, expected = %d.", result, expected);
    if(result != expected)
	printf(" FAIL");
    printf("\n");
}

void test_02_arrayIsIncreasing()
{
    printf("Testing arrayIsIncreasing(...)\n");

    int array1[] = { 0, 1, 2, 3, 4 };
    int len1 = 5;
    test_arrayIsIncreasing(array1, len1, 1);

    int array2[] = {};
    int len2 = 0;
    test_arrayIsIncreasing(array2, len2, 1);

    int array3[] = { -19, 10, 2, 5, -20, 10, 23, 1999 };
    int len3 = 8;
    test_arrayIsIncreasing(array3, len3, 0);

    int array4[] = { -10, 0, 10};
    int len4 = 3;
    test_arrayIsIncreasing(array4, len4, 1);

    int array5[] = { -9, -5, -1, 9, 10, 1 };
    int len5 = 6;
    test_arrayIsIncreasing(array5, len5, 0);

    printf("\n");
}

void test_arrayIndexRFind(int needle, int * array, int len, int expected)
{
    printArray(array, len);
    int index = arrayIndexRFind(needle, array, len);
    printf(". result = %d, expected = %d.", index, expected);
    if(index != expected)
	printf(" FAIL");
    printf("\n");
}

void test_03_arrayIndexRFind()
{
    printf("Testing arrayIndexRFind(...)\n");

    int array1[] = { 0, 1, 2, 3, 4 };
    int len1 = 5;
    int needle1 = 8;
    test_arrayIndexRFind(needle1, array1, len1, -1);

    int array2[] = {};
    int len2 = 0;
    int needle2 = 9;
    test_arrayIndexRFind(needle2, array2, len2, -1);

    int array3[] = { 0, 1, 2, 3, 4 };
    int len3 = 5;
    int needle3 = 2;
    test_arrayIndexRFind(needle3, array3, len3, 2);

    int array4[] = { -10, 10, 0, 10, -10 };
    int len4 = 5;
    int needle4 = 10;
    test_arrayIndexRFind(needle4, array4, len4, 3);

    int array5[] = { 9, 8, 1, 5, 7, 10};
    int len5 = 6;
    int needle5 = 9;
    test_arrayIndexRFind(needle5, array5, len5, 0);

    printf("\n");
}

void test_arrayFindSmallest(int * array, int len, int expected)
{
    printArray(array, len);
    int smallest = arrayFindSmallest(array, len);
    printf(". result = %d, expected = %d.", smallest, expected);
    if(smallest != expected)
	printf(" FAIL");
    printf("\n");
}

void test_04_arrayFindSmallest()
{
    printf("Testing arrayFindSmallest(...)\n");

    int array1[] = { 1, 4, -5, 4 };
    int len1 = 4;
    test_arrayFindSmallest(array1, len1, 2);

    int array2[] = {};
    int len2 = 0;
    test_arrayFindSmallest(array2, len2, 0);

    int array3[] = { -1, 0, 1  };
    int len3 = 3;
    test_arrayFindSmallest(array3, len3, 0);

    int array4[] = { 1, -5, 2, 4, -5, 2 };
    int len4 = 6;
    test_arrayFindSmallest(array4, len4, 1);

    int array5[] = { -10, -20, -30, -40, -50 };
    int len5 = 5;
    test_arrayFindSmallest(array5, len5, 4);

    printf("\n");
}

int main(int argc, char * * argv)
{
    printf("Welcome to ECE264, we are working on PA01.\n\n");

    // Uncomment to run two example (incomplete) testcases.
    test_00_arraySum();
    test_01_arrayCountNegative();
    test_02_arrayIsIncreasing();
    test_03_arrayIndexRFind();
    test_04_arrayFindSmallest();
    return EXIT_SUCCESS;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * * argv)
{
    int ind;
	
    for(ind = 0; ind < argc; ++ind) {
      if (ind !=0){
	printf("%s ", argv[ind]);
      }
      if (ind == (argc-1)) {
	printf("\n");
      }
    }

    return EXIT_SUCCESS;
}

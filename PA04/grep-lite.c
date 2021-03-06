#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define ERROR 2
#define BUFFER_SIZE 2048

void printHelp ()
{
  printf("Usage: grep-lite [OPTION]... PATTERN\n"
	 "Search for PATTERN in standard input. PATTERN is a\n"
	 "string. grep-lite will search standard input line by\n"
	 "line, and (by default) print out those lines which\n"
	 "contain pattern as a substring.\n\n"

	 "-v, --invert-match     print non-matching lines\n"
	 "-n, --line-number      print line number with output\n"
	 "-q, --quiet            suppress all output\n\n"

	 "Exit status is 0 if any line is selected, 1 otherwise;\n"
	 "if any error occurs, then the exit status is 2.\n");
}

int main(int argc, char **argv)
{
	int i;
	int showHelp = FALSE;
	int invertMatch = FALSE;
	int lineNumber = FALSE;
	int quiet = FALSE;
	const char * pattern = argv[argc-1];

#define ARGMP(s) (strcmp(argv[i],s) == 0)
	for(i=1; i<argc-1 ; i++) {
	  if (ARGMP("--help")) showHelp = TRUE;
	  else if (ARGMP("--invert-match")) invertMatch = TRUE;
	  else if (ARGMP("-v")) invertMatch = TRUE;
	  else if (ARGMP("--line-number")) lineNumber = TRUE;
	  else if (ARGMP("-n")) lineNumber = TRUE;
	  else if (ARGMP("--quiet")) quiet= TRUE;
	  else if (ARGMP("-q")) quiet = TRUE;
	  else {
	    fprintf(stderr, "error!\n");
	    return ERROR;
	  }
#undef ARGMP	
	}
	
	if (showHelp || strcmp(pattern, "--help") == 0) {
	  printHelp ();
	  return EXIT_SUCCESS;
	}
	
	if (argc == 1) {
	  fprintf(stderr, "error!\n");
	  return ERROR;
	}
	
	char buffer[BUFFER_SIZE];
	int found = FALSE;
	int currLine = 0;
	
	while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
	  currLine++;
	  int matches = strstr(buffer, pattern) != NULL;
	  if ((matches && !invertMatch) || 
	      (!matches && invertMatch)) {
	    found = TRUE;
	    if (!quiet) {
	      if (lineNumber) printf("%d:", currLine);
	      printf("%s",buffer);
	    }
	  }
	}
	return found ? 0 : 1;
}

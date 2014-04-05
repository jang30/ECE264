#include <stdio.h>
#include <stdlib.h>

#include "answer09.h"
#include "treefun.h"

int main(int argc, char **argv)
{
  if (argc != 2) return EXIT_FAILURE;
  FILE *f = fopen(argv[1], "r");
  HuffNode *tree = HuffTree_readTextHeader (f);
  HuffNode_print(stdout, tree);
  size_t length;
  unsigned char *s = Huffman_applyTree(f,tree, &length);
  printf("%s\n",s);
  free(s);
  HuffNode_destroy(tree);
  fclose(f);
  return EXIT_SUCCESS;
}

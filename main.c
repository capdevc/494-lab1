#include <stdio.h>
#include <stdlib.h>
 
void strassen(int** a, int** b, int** c, int tam);
int** allocate_real_matrix(int tam, int random);

int THRESHOLD;

void print_matrix(int** matrix, int size)
{
  int i, j;

  for (i=0; i<size; i++)
  {
    for (j=0; j<size; j++)
      printf("%d\t", matrix[i][j]);
    printf("\n");
  }
  printf("\n");

}


int main(int argc, char** argv)
{
  if (argc < 4 || argc > 5) 
  {
    printf("usage: strassen <matrix size> <rng seed> <threshold>\n\n");
    printf("matrix size: the number of rows/columns of the matrix (must be a power of two)\n");
    printf("rng seed: and integer seed to the pseudo-random number generator\n");
    printf("threshold: the matrix size at which the algorithm reverts to ordinary matrix\n");
    printf("           multiplication (must be a power of two)\n");
    exit(0);
  }

  int size = atoi(argv[1]);
  int seed = atoi(argv[2]);
  THRESHOLD = atoi(argv[3]);
  srand(seed);                    //seed the rng

  int** matrix1 = allocate_real_matrix(size, 1);
  int** matrix2 = allocate_real_matrix(size, 1);
  int** matrix3 = allocate_real_matrix(size, 0);
  
  strassen(matrix1, matrix2, matrix3, size);

  if (argc == 5 && !strcmp(argv[4], "-p"))
  {
    print_matrix(matrix1, size);
    print_matrix(matrix2, size);
    print_matrix(matrix3, size);
  }

  return 0;
}



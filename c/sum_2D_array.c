
#include	<stdio.h>
#include	<stdlib.h>

#define ROW 2
#define LEN 3

int **matrixPtr, **array1, **array2, m, n;
void allocMatrix(int ***arryPtr, int rows, int cols);
void print_array(int **p, int rows, int cols);


int main (int argc, char *argv[] )
{
	allocMatrix( &array1 , ROW, LEN);
	allocMatrix( &array2 , ROW, LEN);

	for(m=0;m<ROW;m++)
		for(n=0;n<LEN;n++)
		{
			array1[m][n] = 1;
			array2[m][n] = 2;
		}
	print_array( array1, ROW, LEN);
	print_array( array2, ROW, LEN);
	allocMatrix( &matrixPtr, ROW, LEN);

	puts("\n\nmatrixPtr\n");

	print_array( matrixPtr, ROW, LEN);

	return 0;
}

void allocMatrix(int ***arryPtr, int rows, int cols)
{
	int i;  //counter variable 

	//assigns array name to pointers to each row
	*arryPtr = (int**)calloc(rows,sizeof(int*));
	
	//check for null pointer
	if( arryPtr ==NULL){
		puts("Memory allocation failed, terminating prgm...\n");
		exit(EXIT_FAILURE);
	}

	//initializes each row pointer to a row of integers
	for(i = 0; i<rows ; i++)
		(*arryPtr)[i] = calloc(cols,sizeof(int));
		
}


void print_array(int **p, int rows, int cols) 
{
	int i,j;
	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
			printf("%5d", *(*(p+i)+j) );
	puts("\n");

}

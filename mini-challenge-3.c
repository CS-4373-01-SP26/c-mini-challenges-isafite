/* 3. Implement matrix – vector multiplication. Read in the following text file (mv.txt)
 which contains the matrix and vector to be multiplied. Print your answer to the screen 
 and time the computation. The format of mv.txt is: line 1 contains numrows, numcols. The 
 next numrows contains the rows of the matrix, each with numcols integer values. The next 
 line contains the length of the vector. The next line contains the vector of that length. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
	char *next_line;
	char *next_token;
	char buffer[32];
	clock_t start, end;
	double time_to_run;
		
	start = clock();

	FILE *file = fopen("mv.txt", "r");
	if (file == NULL) {
        printf("File could not be opened \n.");
        return 1;
    }

	// Read in the size of the matrix
	next_line = fgets(buffer, sizeof(buffer), file);
	int numrows = atoi(strtok(next_line, " "));
	int numcols = atoi(strtok(next_line, " "));
	
	// Allocate memory for matrix, read in matrix
	int i, j;
	int matrix[numrows][numcols];
	for (i = 0; i < numrows; i++) {
		next_line = fgets(buffer, sizeof(buffer), file);
		next_token = strtok(next_line, " ");
		for (j = 0; j < numcols; j++) {
			matrix[i][j] = atoi(next_token);
			next_token = strtok(NULL, " ");
		}
	}

	// Read in the size of the vector
	next_line = fgets(buffer, sizeof(buffer), file);
	int vec_length = atoi(strtok(next_line, " "));
	
	// Allocate memory for vector, read in vector
	int k;
	int vector[vec_length];
	next_line = fgets(buffer, sizeof(buffer), file);
	next_token = strtok(next_line, " ");
	for (k = 0; k < vec_length; k++) {
		vector[k] = atoi(next_token);
		next_token = strtok(NULL, " ");
	}

	// Calculate matrix multiplication
	int m, n;
	int res[vec_length];
	for (m = 0; m < numrows; m++) {
		// For each row, calculate dot product with vector.
		// This transposes the vector to make a meaningful matrix multiplication. 
		res[m] = 0;
		for (n = 0; n < numcols; n++) {
			res[m] += vector[n]*matrix[m][n];
		}
	}

	// Print results
	end = clock();
	time_to_run = 1000*(double)(end - start)/CLOCKS_PER_SEC; // In milleseconds
	printf("Time to run: %.3f ms\n", time_to_run);
	printf("Resulting vector: ");
	for (int l = 0; l < vec_length; l++) {
        printf("%d ", res[l]);
    }
	
	fclose(file);
	return 0;
}
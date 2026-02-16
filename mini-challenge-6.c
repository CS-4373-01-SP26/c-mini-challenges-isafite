/* 6. Write a program that accepts a string input from stdio and sends it 
to a function that transforms it according a transposition function passed
in to it as an argument. The function will print out the string, transform 
it, and then print out the result. The transposition function, you can assume, 
simply shuffles the existing characters in the string. Build a transposition 
function that reverses the string and apply it. Where appropriate and possible, 
use dynamic allocation and pointer arithmetic to get the job done. */
/* In this problem (not in the others) I used Claude to find and fix errors, mostly in pointers 
and memory allocation, after I had gotten a buggy solution to the problem. It took 
several iterations to get the code to actually have the correct output.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* shuffle_str(char* input_str, char* get_shuffled_ptr(char*, int)) {
	int str_len = strlen(input_str);
	char* output_str;
	output_str = (char*) malloc(str_len + 1);
	memset(output_str, 0, str_len + 1); // Initialize to zero

	printf("Input string: %s\n", input_str);

	for (int i = 0; i < str_len; i++) {
		// Set the ith output char to the char at the correspondingshuffled input position.
		char* shuffled_ptr = get_shuffled_ptr(input_str, i);
		output_str[i] = *shuffled_ptr;
	}
	output_str[str_len] = '\0'; // Make the string end with a null terminator
	
	printf("Output string: %s\n", output_str);

	return output_str;
}

char* transpose_func(char* input_str, int index) {
	// Given an index, return a pointer to the index position reflected across the middle of the string.
	int new_index = strlen(input_str) - 1 - index;
	char* new_char_ptr = &input_str[0] + new_index;
	return new_char_ptr;
}

char* identity_func(char* input_str, int index) {
	// For testing: given an index, do nothing to the index and return a pointer to the same position.
	char* input_char_ptr = &input_str[0] + index;
	return input_char_ptr;
}

int main() {	
	// Allocate memory dynamically for the input buffer.
    char *buffer;
    size_t bufsize = 32;
    buffer = (char*) malloc(bufsize * sizeof(char));
    if( buffer == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    printf("Enter a string: ");
    getline(&buffer, &bufsize, stdin);

    // Remove the newline that getline includes
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len-1] = '\0';
    }
    printf("You entered: '%s'\n",buffer);

	// Use shuffle_str to transpose the string
	shuffle_str(buffer, transpose_func);

	// Clean up memory
	free(buffer);
	return 0;
}
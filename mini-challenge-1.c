/* 1. Print “Hello, NAME” where NAME is input from the keyboard. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char *str;
    str = (char *)malloc((strlen(argv[1]) + 1) * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    strcpy(str, argv[1]);

    printf("Hello, %s! \n", str);

    free(str);
	str = NULL;
    return 0;
}
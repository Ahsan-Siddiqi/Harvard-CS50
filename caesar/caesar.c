#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv) {

    char input[99999];

    // grab arg input
    if (argc != 2 || argv[2]) {
        printf("Usage: ./caesar key");
        exit(1);
    }

    // grab input text
    printf("plaintext: ");
    fgets(input, sizeof(input), stdin);

    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n')
    {
        input[length - 1] = '\0';
    }

    // manipulate input text

    for (int i = 0; i < length; i++) {
        input[i] = (input[i] + argv[2]) % 26;
    }

    // print result
    printf("ciphertext: %s", input);

    return 0;
}

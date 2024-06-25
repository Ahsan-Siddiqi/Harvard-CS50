#include <stdio.h>

int main (int argc, char** argv) {

    char input[99999];

    // grab arg input
    if (argc != 2 || !isdigit(argv[2])) {
        prtinf("Usage: ./caesar key");
        break;
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
        input[i] += argv[2];
    }

    // print result
    printf("ciphertext: %s", input);

    return 0;
}

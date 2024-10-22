#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

    char input[99999];
    int key;

    // grab arg input
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }

    // Validate that the key is a digit
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    key = atoi(argv[1]);

    // grab input text
    printf("plaintext: ");
    fgets(input, sizeof(input), stdin);

    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n')
    {
        input[length - 1] = '\0';
        length--;
    }

    // manipulate input text
    for (int i = 0; i < length; i++)
    {
        if (isalpha(input[i]))
        {
            char offset = isupper(input[i]) ? 'A' : 'a';
            input[i] = (input[i] - offset + key) % 26 + offset;
        }
    }

    // print result
    printf("ciphertext: %s\n", input);

    return 0;
}

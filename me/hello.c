#include <stdio.h>
#include <string.h>

int main() {
    char name[100];

    printf("What's your name? ");
    fgets(name, sizeof(name), stdin);

    size_t length = strlen(name);
    if (length > 0 && name[length - 1] == '\n') {
        name[length - 1] = '\0';
    }

    printf("Hello, %s!\n", name);

    return 0;
}

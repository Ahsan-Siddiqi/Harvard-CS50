#include <stdio.h>
#include <string.h>

int main() {
    //array for name
    char name[100];

    //get name
    printf("What's your name? ");
    fgets(name, sizeof(name), stdin);

    //remove newline
    size_t length = strlen(name);
    if (length > 0 && name[length - 1] == '\n') {
        name[length - 1] = '\0';
    }

    //print name
    printf("hello, %s\n", name);

    return 0;
}

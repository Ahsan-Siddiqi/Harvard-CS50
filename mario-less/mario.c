#include <stdio.h>

int main() {
    int height;
    char tag = '#';

    printf("Height: ");
    scanf("%d", &height);

    for (int i= 0; i<height; i++) {
        printf("%10c\n", tag);
    }
    return 0;
}

#include <stdio.h>

int main() {
    int height;
    char tag = '#';

    printf("Height: ");
    scanf("%d", &height);

    for (int i= 0; i<height; i++) {
        for (int j=1; j<=i; j++) {
            printf("%c", tag);
        }
        printf("\n");
    }
    return 0;
}

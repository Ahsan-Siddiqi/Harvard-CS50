#include <stdio.h>

int main() {
    int height;
    char tag = '#';

    printf("Height: ");
    scanf("%d", &height);

    for (int i= 0; i<height; i++) {
        for (int j=0; j<i; j++) {
            if(j<height) {
                printf(" ");
            } else {
                printf("%c", tag);
            }
        }
        printf("\n");
    }
    return 0;
}

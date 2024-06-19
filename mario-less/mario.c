#include <stdio.h>

int main() {
    int height;

    printf("Height: ");
    scanf("%d", &height);

    for (int i= 0; i<height; i++) {
        printf("%10d\n", i);
    }
    return 0;
}

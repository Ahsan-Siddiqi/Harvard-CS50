#include <stdio.h>
#include <ctype.h>

int main() {
    int height;
    int temp;
    char tag = '#';

    //ask for (correct) input
    do {
        printf("Height: ");
        temp = scanf("%d", &height);

        //clear input buffer on failure
        while (getchar() != '\n');

    } while (height < 1 || temp != 1);


    //print pyramid
    for (int i= 0; i<height; i++) {
        for (int j=1; j<=height; j++) {
            if (j<height-i) {
                printf(" ");
            } else {
                printf("%c", tag);
            }
        }
        printf("\n");
    }

    return 0;
}

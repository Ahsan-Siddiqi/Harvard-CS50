#include <stdio.h>

int main() {
    int penny, dime, nickel, quarter;
    int temp, owed;

    // grab (correct) input
    do
    {
        printf("Cash owed: ");
        temp = scanf("%d", &owed);

        // clear input buffer on failure
        while (getchar() != '\n');
    }
    while (height < 1 || temp != 1);


    while(owed != 0) {
        if (owed - 25 >= 0) {
            owed -= 25;
            quarter++;
        } else if (owed - 10 >= 0) {
            owed -= 10;
            nickel++;
        } else if (owed - 5 >= 0) {
            owed -= 5;
            dime++;
        } else {
            owed -= 1;
            penny++;
        }
    }

    printf()
}

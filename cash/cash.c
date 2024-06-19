#include <stdio.h>

int main()
{

    int coins = 0, temp, owed;

    // grab (correct) input
    do
    {
        printf("Cash owed: ");
        temp = scanf("%d", &owed);

        // clear input buffer on failure
        while (getchar() != '\n')
            ;
    }
    while (owed < 1 || temp != 1);

    // count coins
    while (owed != 0)
    {
        if (owed - 25 >= 0)
        {
            owed -= 25;
            coins++;
        }
        else if (owed - 10 >= 0)
        {
            owed -= 10;
            coins++;
        }
        else if (owed - 5 >= 0)
        {
            owed -= 5;
            coins++;
        }
        else
        {
            owed -= 1;
            coins++;
        }
    }

    printf("%d\n", coins);
}

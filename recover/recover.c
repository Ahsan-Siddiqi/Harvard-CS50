#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc != 2) {
        printf("Usage: ./recover [imagename]");
        exit(1)
    }

    // look through the raw for the jpeg pattern (0xff 0xd8 0xff)

        // iterate over chunks of 512 bytes or 1 block

            // when pattern match, open file to write to
    return 0;
}

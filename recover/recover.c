#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc != 2) {
        printf("Usage: ./recover [imagename]");
        exit(1)
    }

    FILE* forensic = fopen(argv[1], "r");

    if (forensic == NULL) {
        printf("Input file cannot be opened");
        exit(1)
    }


    // look through the raw for the jpeg pattern (0xff 0xd8 0xff)

        // iterate over chunks of 512 bytes or 1 block
    for (int i = )

            // when pattern match, open file to write to

            // copy contents until another pattern found
    return 0;
}

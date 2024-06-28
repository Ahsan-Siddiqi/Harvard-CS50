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
    char buffer[512];
    size_t bytesRead;
    char pattern[] = {0xff, 0xd8, 0xff, }

    while(bytesRead = fread(&buffer, 1, sizeof(buffer), forensic)) {

        // when pattern match, open file to write to
        if (bytesRead >= 4 && memcmp(buffer, ))
        // copy contents until another pattern found

    }

    return 0;
}

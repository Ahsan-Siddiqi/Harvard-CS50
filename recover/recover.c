#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc != 2) {
        printf("Usage: ./recover [imagename]");
        exit(1)
    }

    // look through the raw for the jpeg pattern (0xff 0xd8 0xff)

    return 0;
}

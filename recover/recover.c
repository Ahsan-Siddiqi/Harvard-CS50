#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    if (argc != 2) {
        printf("Usage: ./recover [imagename]\n");
        exit(1);
    }

    FILE* forensic = fopen(argv[1], "r");

    if (forensic == NULL) {
        printf("Input file cannot be opened\n");
        exit(1);
    }

    // look through the raw for the jpeg pattern (0xff 0xd8 0xff)

        // iterate over chunks of 512 bytes or 1 block
    char buffer[512];
    size_t bytesRead;
    char pattern[] = {0xff, 0xd8, 0xff};
    int nPics = 0;
    char picName[8];
    FILE* output = NULL;

    while((bytesRead = fread(&buffer, sizeof(buffer), 1, forensic)) > 0) {

        // when pattern match, open file to write to
        if (!memcmp(buffer, pattern, 3)) {
            if(output != NULL) {
                fclose(output);
            }

            sprintf(picName, "%3d.jpg", nPics);
            output = fopen(picName, "w");

            fwrite(&buffer, sizeof(buffer), 1, output);

            nPics++;
        }
        // copy contents until another pattern found

    }

    fclose(output);
    fclose(forensic);

    return 0;
}

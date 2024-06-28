#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover [imagename]\n");
        exit(1);
    }

    FILE *forensic = fopen(argv[1], "r");

    if (forensic == NULL)
    {
        printf("Input file cannot be opened\n");
        exit(1);
    }

    // look through the raw for the jpeg pattern (0xff 0xd8 0xff)

    // iterate over chunks of 512 bytes or 1 block
    unsigned char buffer[512];
    size_t bytesRead;
    int nPics = 0;
    char picName[8];
    FILE *output = NULL;

    while ((bytesRead = fread(buffer, sizeof(unsigned char), sizeof(buffer), forensic)) > 0)
    {

        // when pattern match, open file to write to
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (output != NULL)
            {
                fclose(output);
            }

            sprintf(picName, "%03d.jpg", nPics);
            output = fopen(picName, "w");

            fwrite(buffer, sizeof(unsigned char), bytesRead, output);

            nPics++;
        }
        else if (output != NULL)
        {

            fwrite(buffer, sizeof(unsigned char), bytesRead, output);
        }
    }

    if (output != NULL)
    {
        fclose(output);
    }
    fclose(forensic);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //opening "memory card" (input file)
    FILE *f = fopen(argv[1], "r");

    //returns error if the file is not valid
    if (f == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    //declaring byte type
    typedef uint8_t BYTE;

    //declaring buffer to write pixels into
    BYTE buffer[512];
    int counter = 0;
    char filename[8];

    //initialising output file
    FILE *img = NULL;

    //loop to keep the program going until the end of the file is reached
    while (fread(buffer, 1, sizeof(buffer), f) == 512)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            //IF the first jpeg is detected
            if (counter == 0)
            {
                //000.jpg is created
                sprintf(filename, "%03i.jpg", counter);
                counter++;
                img = fopen(filename, "w");
            }
            //ELSE IF the jpeg is another one that comes after the first one
            else
            {

                //close the last file I was writing to
                fclose(img);
                //creating that jpg
                sprintf(filename, "%03i.jpg", counter);
                counter++;
                img = fopen(filename, "w");
            }
        }

        //IF jpg has been started and new one has not began, continue writing to the last one
        if (img != NULL)
        {
            fwrite(buffer, 1, sizeof(buffer), img);
        }
    }
    //closing the "memory card" and whichever out-file is open at that moment
    fclose(img);
    fclose(f);
    return 0;
}
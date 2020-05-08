#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//an 8 bit unsigned integer
typedef uint8_t BYTE;

//Acc. to FAT file system block size is 512 bytes for digital camera's JPEG
const int block_size = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    //Pointer to store the data we're reading
    BYTE arr[block_size];

    //Open the memory card
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Cannot read the file. Do check again");
        return 2;
    }

    int image_count = 0;
    //length of filename + 1 for \0
    char file_name[8];
    FILE *img = NULL;
    while (fread(arr, block_size, sizeof(BYTE), file))
    {
        //Start of a new jpeg
        if (arr[0] == 0xff && arr[1] == 0xd8 && arr[2] == 0xff && (arr[3] & 0xf0) == 0xe0)
        {
            //Close any existing jpg file if open
            if (image_count > 0)
            {
                fclose(img);
            }

            //Create filename
            sprintf(file_name, "%03i.jpg", image_count);
            //Open a new jpg file
            img = fopen(file_name, "w");

            if (img == NULL)
            {
                fclose(file);
                fclose(img);
                printf("Failed to open image for writing\n");
                return 3;
            }
            image_count++;
        }
        //Write on the existing currently opened jpeg
        if (image_count > 0)
        {
            fwrite(arr, block_size, sizeof(BYTE), img);
        }
    }
    fclose(img);
    fclose(file);
    return 0;
}

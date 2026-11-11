
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd, fsize;
    char buffer[1000], fname[100];

    printf("Enter the filename to be read: ");
    scanf("%99s", fname);

    // Open the file in read-only mode
    fd = open(fname, O_RDONLY);

    if (fd == -1)
    {
        printf("Open error!\n");
        return 1;
    }
    else
    {
        // Read the contents of the file
        fsize = read(fd, buffer, sizeof(buffer) - 1);

        if (fsize == -1)
        {
            printf("Read error!\n");
            close(fd);
            return 1;
        }
        else
        {
            buffer[fsize] = '\0';

            printf("The file contains:\n%s\n", buffer);
        }

        close(fd);
    }

    return 0;
}

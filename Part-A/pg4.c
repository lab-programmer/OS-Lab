#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd, n;
    char buffer[100];

    printf("Enter the filename: ");
    scanf("%99s", buffer);

    fd = open(buffer, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("Open Error");
        return 1;
    }

    printf("Enter contents to be written (Press Ctrl+D to stop):\n");

    while ((n = read(0, buffer, sizeof(buffer))) > 0)
    {
        if (write(fd, buffer, n) != n)
        {
            perror("Write Error");
            close(fd);
            return 1;
        }
    }

    if (n == -1)
    {
        perror("Read Error");
    }

    close(fd);

    return 0;
}
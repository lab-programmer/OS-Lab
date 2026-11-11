#include <stdio.h>
#include <unistd.h>

int main()
{
    char sname[100];

    printf("Enter the script name: ");
    scanf("%99s", sname);

    if (execl("/bin/sh", "sh", sname, (char *)NULL) == -1)
    {
        perror("Error: Script not found or cannot be executed");
        return 1;
    }

    return 0;
}


// #!/bin/bash

// echo "Enter any three numbers:"
// read a b c

// if [ $a -ge $b ] && [ $a -ge $c ]; then
//     echo "$a is greatest"
// elif [ $b -ge $c ] && [ $b -ge $a ]; then
//     echo "$b is greatest"
// else
//     echo "$c is greatest"
// fi
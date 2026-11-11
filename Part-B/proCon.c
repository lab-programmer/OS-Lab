
#include <stdio.h>

int main()
{
    int size = 5, in = 0, out = 0, count = 0;
    int buffer[size], choice, item;

    while (1)
    {
        printf("\n1. Producer\n2. Consumer\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the item to produce: ");
                scanf("%d", &item);

                if (count == size)
                {
                    printf("Cannot produce! Buffer is full.\n");
                }
                else
                {
                    buffer[in] = item;
                    in = (in + 1) % size;
                    count++;

                    printf("Item produced successfully.\n");
                }
                break;

            case 2:
                if (count == 0)
                {
                    printf("Buffer is empty!\n");
                }
                else
                {
                    item = buffer[out];
                    out = (out + 1) % size;
                    count--;

                    printf("Item consumed: %d\n", item);
                }
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

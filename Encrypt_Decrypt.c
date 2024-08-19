#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ceaser_Encrypt(char *str, int shift)
{
    for (int i = 0; i < strlen(str); i++)
    {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z')
        {
            str[i] = (ch - 'a' + shift) % 26 + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            str[i] = (ch - 'A' + shift) % 26 + 'A';
        }
    }
}

void ceaser_Decrypt(char *str, int shift)
{
    for (int i = 0; i < strlen(str); i++)
    {
        char ch = str[i];

        if (ch >= 'a' && ch <= 'z')
        {
            str[i] = (ch - 'a' - shift + 26) % 26 + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            str[i] = (ch - 'A' - shift + 26) % 26 + 'A';
        }
    }
}

int main()
{
    char str[100];
    int shift, choice;

    do
    {
        printf("Choose an option:\n1. Encrypt\n2. Decrypt\n3. Exit\n");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            printf("Enter the character you want to encrypt: \n");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            printf("Enter the shift value: \n");
            scanf("%d", &shift);
            ceaser_Encrypt(str, shift);
            printf("The Encrypted word is : %s\n", str);
            break;

        case 2:
            printf("Enter the encrypted character: \n");
            fgets(str, sizeof(str), stdin);
            str[strcspn(str, "\n")] = '\0';
            printf("Enter the shift value: \n");
            scanf("%d", &shift);
            ceaser_Decrypt(str, shift);
            printf("The Result is: %s\n", str);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid Input\n");
            break;
        }
    } while (choice != 3);

    return 0;
}

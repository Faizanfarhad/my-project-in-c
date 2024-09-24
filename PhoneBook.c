#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
    //Have to fix load from file(); function
#define RESETT "\x1B[0m"
#define MAGENTA "\x1B[35m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

struct Node
{
    char name[10000];
    char phoneNumber[15000];
    struct Node *prev;
    struct Node *next;
};
void trimWhitespace(char *str)
{
    char *end;

    while (isspace((unsigned char)*str))
        str++;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end))
        end--;

    *(end + 1) = '\0';
}
struct Node *createNode(const char *name, const char *phonenumber)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf(GREEN"Dynamic Memory Allocation failed!"RESET);
        return NULL;
    }
    strcpy(newNode->name, name);
    strcpy(newNode->phoneNumber, phonenumber);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void addName(struct Node **head,struct Node **tail,const char *name,const char *phone)
{
    struct Node * newNode = createNode(name,phone);

            
            if (*head == NULL)
            {
                *head = newNode;
                *tail = newNode;
            }
            else
            {
                (*tail)->next = newNode;
                newNode->prev = *tail;
                *tail = newNode;
            }
    printf(GREEN"Entries added successfully!..\n"RESET);
}

int isValidPhoneNumber(const char *phoneNumber)
{
    if (strlen(phoneNumber) != 10)
    {
        return 0;
    }
    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(phoneNumber[i]))
        {
            return 0;
        }
    }
    return 1;
}
void SearchEntry(struct Node *head)
{
    if (head == NULL)
    {
        printf(RED"Error\n"RESET);
        return;
    }
    char searchname[100];
    char searchPhone[15];

    printf(YELLOW"Enter the Name that you want to search: "RESET);
    fgets(searchname, sizeof(searchname), stdin);
    trimWhitespace(searchname);

    printf(YELLOW"Enter the Phone Number that  you want to search : "RESETT);
    fgets(searchPhone, sizeof(searchPhone), stdin);
    trimWhitespace(searchPhone);

    struct Node *current = head;

    while (current != NULL)
    {
        if (strcmp(current->name, searchname) == 0 && strcmp(current->phoneNumber, searchPhone) == 0)
        {
            printf(GREEN"Entries Found! Details are...\n"RESETT);
            printf(YELLOW"Name = %s\nPhone Number = %s\n"RESETT, current->name, current->phoneNumber);
            return;
        }
        current = current->next;
    }

    printf(RED"\nEntry is Not Found!\n"RESETT);
}
void update(struct Node *head, const char *oldname, const char *oldPhone)
{

    if (head == NULL)
    {
        printf(RED"Error! Lis is empty\n"RESET);
        return;
    }
    struct Node *current = head;
    while (current != NULL)
    {
        if (strcmp(current->name, oldname) == 0 && strcmp(current->phoneNumber, oldPhone) == 0)
        {
            printf(MAGENTA"Enter the New name  : "RESETT);
            fgets(current->name, sizeof(current->name), stdin);
            trimWhitespace(current->name);

            printf(MAGENTA"Enter the New phone Number : "RESET);
            fgets(current->phoneNumber, sizeof(current->phoneNumber), stdin);
            trimWhitespace(current->phoneNumber);

            printf(GREEN"details uodate successfully!\n"RESETT);
            return;
        }
        current = current->next;
    }

    printf(RED"Details are Not Founded!"RESET);
}
void Delete(struct Node **head, const char *name, const char *phoneNumber)
{
    if (head == NULL)
    {
        printf(RED "Empty,There is Nothing to Delete!" RESETT);
        return;
    }

    struct Node *current = *head;
    struct Node *previous = NULL;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0 && strcmp(current->phoneNumber, phoneNumber) == 0)
        {
            if (current == *head)
            {
                *head = current->next;
            if (head != NULL)
            {
                (*head)->prev = NULL;
            }
            }else
            {
                previous->next = current->next;
                if (current->next != NULL)
                {
                    current->next->prev = previous;
                }
                
            }
            free(current);
            printf(GREEN"Deleted Successfully!..\n"RESET);
            return;
            
            
        }
        previous = current;
        current = current->next;
    }
    printf(RED"Entries Not Found!...\n"RESET);
}
void Display(struct Node *head)
{
    if (head == NULL)
    {
        printf("Entries are empty! There is nothing to display..\n");
        return;
    }

    struct Node *current = head;

    while (current != NULL)
    {
        printf(MAGENTA "Name = %s\nPhone Number = %s\n" RESET, current->name, current->phoneNumber);
        current = current->next;
    }
}
void saveInputINFiles(struct Node * head,const char *filename)
{

    FILE *file = fopen(filename, "a");

    if (file == NULL)
    {
        printf(RED"!Error,Not anle to open file\n"RESET);
        return;
    }
    struct Node * current = head;
    while (current != NULL)
    {
        fprintf(file,"name = %s\tPhone Number = %s\n",current->name,current->phoneNumber);
        current = current->next;
    }
    fclose(file);
    printf(GREEN"Saving Entries In Files is Completed!.."RESET);

}
void loadFromFile(struct Node **head, struct Node **tail, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf(RED "Error! Could not open file: %s\n" RESET, filename);
        return;
    }

    char name[10000];
    char phoneNumber[15000];
    
    while (fscanf(file, "name = %9999s\tPhone Number = %14999s\n", name, phoneNumber) == 2) {
        addName(head, tail, name, phoneNumber);
    }

    fclose(file);
    printf(GREEN "Loading entries from file is completed!\n" RESET);
}
void printMenu()
{
    printf(GREEN"Menu\n\n"RESETT);
    printf(YELLOW "1. Add Names\n"RESET);
    printf(YELLOW "2. Search Names\n"RESET);
    printf(YELLOW "3. Update\n"RESET);
    printf(YELLOW "4. Delete Previous Entry\n"RESET);
    printf(YELLOW "5. Display The Entries\n"RESET);
    printf(YELLOW "6. Save Enteries to files\n"RESET);
    printf(YELLOW "7. Load Frome File\n"RESET);
    printf(YELLOW "8. Exit\n"RESET);
}
int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int choose;
    char phone[15];
    char name[100];

    while (1)
    {
        printMenu();
        char choice[10];
        printf(GREEN"\nEnter your choice: "RESET);
        fgets(choice, sizeof(choice), stdin);
        trimWhitespace(choice);
        choose = atoi(choice);

        switch (choose)
        {
        case 1:
            
            printf(MAGENTA"Enter the Name : "RESETT);
            fgets(name, sizeof(name), stdin);
            trimWhitespace(name);

            printf(MAGENTA"Enter the Phone Number :"RESETT);
            fgets(phone, sizeof(phone), stdin);
            trimWhitespace(phone);


            if (isValidPhoneNumber(phone))
            {
                printf(RED"Invalid phone NUmber! please enter a 10 digit phone Number.\n"RESET);
                break;
                
            }
            addName(&head,&tail,name,phone);
            break;
        case 2:
            SearchEntry(head);
            break;
        case 3:
        {
            char oldname[100];
            char oldPhone[15];
            printf(BLUE"Enetr the  previous name : "RESET);
            fgets(oldname, sizeof(oldname), stdin);
            trimWhitespace(oldname);

            printf(BLUE"Enter the  previous Phone Number  : "RESET);
            fgets(oldPhone, sizeof(oldPhone), stdin);
            trimWhitespace(oldPhone);

            update(head, oldname, oldPhone);
        }
        break;
        case 4:
            printf(MAGENTA"Enter the Name That You want to delete : "RESETT);
            fgets(name, sizeof(name), stdin);
            trimWhitespace(name);

            printf(MAGENTA"Enter the Phone Number for Deletion : "RESETT);
            fgets(phone, sizeof(phone), stdin);
            trimWhitespace(phone);

            Delete(&head, name, phone);
            break;
        case 5:
            Display(head);
            break;
        case 6:
        if(head == NULL){
            printf("Errro! Entries Are Empty...\n");
        }else{
            saveInputINFiles(head,"ContactDeatils.txt");
        }
            break;
            case 7:
            loadFromFile(&head, &tail, "ContactDetails.txt");
            break;
        case 8:
            printf(CYAN"Exiting... Thank You for using me!\n"RESETT);
            while (head != NULL)
            {
                struct Node * temp = head;
                head = head->next;
                free(temp);
            }
            return 0;
            break;
        default:
            printf(RED"Invalid choice. Please try again.\n"RESETT);
            break;
        }
    }
    return 0;
}

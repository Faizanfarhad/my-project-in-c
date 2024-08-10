/*
    School Management maintained by the school is the way they are able to find data about every single student. Using a basic C application we can manage the data of the school.

The functionality of the School Management System Application is mentioned below:

1.Add Student Details
2.Find the student by the given roll number
3. Find the student by the given first name
4. Find the students registered in a course
5. Count of Students
6. Delete a student
7. Update Student

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0;

struct student_Detail
{
    char First_Name[15];
    char Last_Name[15];
    int Roll_NO;
    float cgpa;
    int course_ID[5];
} sd[55];

void load_student(){
    FILE *file = fopen("Student.txt", "r");
    if (file == NULL)
    {
        printf("Could NOt open file\n");
        return;
    }
    while (fscanf(file, "%s %s %d %f %d %d %d %d %d",sd[i].First_Name,sd[i].Last_Name,sd[i].Roll_NO,sd[i].cgpa,sd[i].course_ID[0],sd[i].course_ID[1],sd[i].course_ID[2],sd[i].course_ID[3],sd[i].course_ID[4]));
    {
        i++;
    }
    fclose(file);
    
}

void save_student(){
    FILE *file = fopen("Student.txt", "w");
    if (file == NULL)
    {
        printf("Could NOt open file ti save data\n");
        return;
    }
    for (int j = 0; j < i; j++)
    {
        fscanf(file, "%s %s %d %.2f %d %d %d %d %d",sd[i].First_Name,sd[i].Last_Name,sd[i].Roll_NO,sd[i].cgpa,sd[i].course_ID[0],sd[i].course_ID[1],sd[i].course_ID[2],sd[i].course_ID[3],sd[i].course_ID[4]);
    }
    
fclose(file);

}

// for adding the student details
void add_student()
{
    
    printf("Enter the First Name\n");
    scanf("%s", sd[i].First_Name);
    printf("Enter the Last Name\n");
    scanf("%s", sd[i].Last_Name);
    printf("Enter the Roll NO\n");
    scanf("%d", &sd[i].Roll_NO);
    printf("Enter the CGPA\nYou Obtained\n");
    scanf("%f", &sd[i].cgpa);
    printf("Enter The course ID of All of the subject\n");
    for (int j = 0; j < 5; j++)
    {
        scanf("%d", &sd[i].course_ID[j]);
    }
    i = i + 1;
    save_student();
    printf("Save student Successfully!\n");
}

void finding_Roll_No()
{
    int x;
    printf("Enter the Student Roll no for Details :");
    scanf("%d", &x);
    for (int j = 0; j < i; j++)
    {
        if (x == sd[j].Roll_NO)
        {
            printf("The student First name is %s\n", sd[j].First_Name);
            printf("The student Last Name is  %s\n", sd[j].Last_Name);
            printf("The student  CGPA is %f\n", sd[j].cgpa);
            for (int k = 0; k < 5; k++)
            {
                printf("The course ID is %d\n", sd[j].course_ID[k]);
            }
            return;
        }
    }
    printf("Student Roll No %d is Not Found\n", x);
}

void finding_BY_fname()
{
    char name[50];
    printf("Enter the first Name of Student :");
    scanf("%s", name);
    for (int j = 0; j < i; j++)
    {
        if (!strcmp(sd[j].First_Name, name))
        {
            printf("The Student Roll NO is %d\n", sd[j].Roll_NO);
            printf("The student CGPA is %f\n", sd[j].cgpa);
            printf("The student course ID of each subject is\n");
            for (int k = 0; k < 5; k++)
            {
                printf("The course ID are %d\n", sd[j].course_ID[k]);
            }
            return;
        }
    }
    printf("Student with First Name %s not found\n", name);
}

void find_by_couse_id()
{
    int id;
    printf("Enter Student course id \n For finding :");
    scanf("%d", &id);
    int found = 0;
    for (int j = 0; j < i; j++)
    {
        for (int d = 0; d < 5; d++)
        {
            if (id == sd[j].course_ID[d])
            {
                printf("The student Details are :\n");
                printf("The student First Name is %s\n", sd[j].First_Name);
                printf("The student Last Name is %s\n", sd[j].Last_Name);
                printf("The student Roll no is %d\n", sd[j].Roll_NO);
                printf("The student CGPA is %f\n", sd[j].cgpa);
                found = 1;
                break;
            }
        }
    }
    if (!found)
    {
        printf("The course id is Invalid\n");
    }
}

void t_student()
{
    printf("The total Numbers of Students is %d\n", i);
    printf("You can have Max student is 50\n");
    printf("You can add %d more students\n", 50 - i);
}

void del_student()
{
    int a;
    printf("Enter the roll number which you want to Delete :");
    scanf("%d", &a);
    for (int j = 0; j < i; j++)
    {
        if (a == sd[j].Roll_NO)
        {
            for (int k = j; k < i - 1; k++)
            {
                sd[k] = sd[k + 1];
            }
            i--;
            printf("The Roll No %d is removed Successfully\n", a);
            return;
        }
    }
    printf("Roll No %d not found\n", a);
}

void update_student()
{
    int b;
    printf("Enter the Roll No for update Entry :");
    scanf("%d", &b);
    for (int j = 0; j < i; j++)
    {
        if (sd[j].Roll_NO == b)
        {
            printf("1. The First Name\n");
            printf("2. The Last Name\n");
            printf("3. The CGPA\n");
            printf("4. The Roll No\n");
            printf("5. The Course Id\n");

            int a;
            scanf("%d", &a);
            switch (a)
            {
            case 1:
                printf("Enter the new first name\n");
                scanf("%s", sd[j].First_Name);
                break;
            case 2:
                printf("Enter the new last name\n");
                scanf("%s", sd[j].Last_Name);
                break;
            case 3:
                printf("Enter the new CGPA of the student\n");
                scanf("%f", &sd[j].cgpa);
                break;
            case 4:
                printf("Enter the new Roll No\n");
                scanf("%d", &sd[j].Roll_NO);
                break;
            case 5:
                printf("Enter the new Course Ids\n");
                for (int k = 0; k < 5; k++)
                {
                    scanf("%d", &sd[j].course_ID[k]);
                }
                break;
            default:
                printf("Invalid choice\n");
                break;
            }
        }
    }
            save_student();
            printf("Update successfully\n");
            return;
    printf("Roll No %d not found\n", b);
}

int main()
{
    while (1)
    {
        printf("Select an option between\n");
        printf("1. Add Student Details\n");
        printf("2. Find the student by the given roll number\n");
        printf("3. Find the student by the given first name\n");
        printf("4. Find the students registered Course Id\n");
        printf("5. Count of Students\n");
        printf("6. Delete a student\n");
        printf("7. Update Student\n");
        printf("8. Exit\n");

        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            finding_Roll_No();
            break;
        case 3:
            finding_BY_fname();
            break;
        case 4:
            find_by_couse_id();
            break;
        case 5:
            t_student();
            break;
        case 6:
            del_student();
            break;
        case 7:
            update_student();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
            
        }
    }
    return 0;
}

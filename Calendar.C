#include <stdio.h>

int main()
{
    int year, month, daysInmonths, startingDay, daysOfWeek;

    printf("Enter Year: ");
    scanf("%d", &year);
    printf("Enter the Month (1-12): ");
    scanf("%d", &month);

    // Determine number of days in the month
    if (month == 2)
    {
        // February: Check for leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            daysInmonths = 29; // Leap year
        }
        else
        {
            daysInmonths = 28; // Non-leap year
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        // April, June, September, November have 30 days
        daysInmonths = 30;
    }
    else
    {
        // January, March, May, July, August, October, December have 31 days
        daysInmonths = 31;
    }

    // Calculate starting day (Zeller's Congruence or simpler approximation)
    startingDay = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;

    for (int i = 1; i < month; i++)
    {
        if (i == 2)
        {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            {
                startingDay += 29;
            }
            else
            {
                startingDay += 28;
            }
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11)
        {
            startingDay += 30;
        }
        else
        {
            startingDay += 31;
        }
    }
    
    // Determine the day of the week for the 1st of the month
    daysOfWeek = (startingDay + 1) % 7;

    printf("\n===============================\n");
    printf("           %d-%02d  \n", year, month);
    printf("===============================\n");
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    // Print initial spaces for the first week
    for (int i = 0; i < daysOfWeek; i++)
    {
        printf("    ");
    }

    // Print the days of the month
    for (int day = 1; day <= daysInmonths; ++day)
    {
        printf("%4d", day);
        if ((day + daysOfWeek) % 7 == 0)
        {
            printf("\n");
        }
    }

    printf("\n");

    return 0;
}

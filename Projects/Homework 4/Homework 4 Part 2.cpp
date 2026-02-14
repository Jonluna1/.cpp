#include <iostream>
#include <iomanip>

using namespace std;

// Check if leap year
bool isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    return true;
    else
    return false;
}

// Get number of days in month
int getDays(int month, int year)
{
    switch (month)
    {
        case 1: return 31;
        case 2: return isLeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 30;
    }
}

// Zeller's formula to find first weekday
int getStartDay(int year)
{
    int d = 1;     // First day of month
    int m = 13;     // January treated as month 13
    int y = year - 1;

    int k = y % 100;
    int j = y / 100;

    int h = (d + (13*(m+1))/5 + k + (k/4) + (j/4) + (5*j)) % 7;

    // Convert to Monday=0 format
    return (h + 5) % 7;
}

int main()
{
    int year;
    cout << "Enter a year: ";
    cin >> year;

    cout << "\nCalendar for " << year << "\n";

    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int startDay = getStartDay(year);

    for (int month = 1; month <= 12; month++)
    {
        int days = getDays(month, year);

        cout << "\n-- " << months[month - 1] << " " << year << " --\n";
        cout << "   Mon  Tue  Wed  Thu  Fri  Sat  Sun\n";

        // Print initial spaces
        for (int i = 0; i < startDay; i++)
        cout << setw(5) << " ";

        for (int day = 1; day <= days; day++)
        {
            cout << setw(5) << day;

            if ((startDay + day) % 7 == 0)
            cout << endl;
        }

        cout << endl;

        startDay = (startDay + days) % 7;
    }

    return 0;
}




# include <iostream>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <conio.h>
# include <bits/stdc++.h>
# include <dos.h>
# include <time.h>
# include <ctime>
using namespace std;
time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
struct date{
    int day;
    int month;
    int year;
};
date dot = {local_time->tm_mday, 1 + local_time->tm_mon, 1900 + local_time->tm_year};
date dob;
inline void print(int d, int m, int y)
{
    if(m == 0 && y == 0)
    {
        cout << "You are " << d;
        d == 1?cout << " day old.\n":cout << " days old.\n";
    }
    else if(y == 0)
    {
        cout << "You are " << d;
        d == 1?cout << " day ":cout << " days ";
        cout << m;
        m == 1?cout << " month old.\n": cout << " months old.\n";
    }
    else if(m == 0)
    {
        cout << "You are " << d;
        d == 1?cout << " day ":cout << " days ";
        cout << y;
        y == 1?cout << " year old.\n":cout << " years old.\n";
    }
    else
    {
        cout << "You are " << y;
        y == 1?cout << " year ":cout << " years ";
        cout << m;
        m == 1?cout << " month ": cout << " months ";
        cout << d;
        d == 1?cout << " day old.\n":cout << " days old.\n";
    }
}
inline void cnver(int d, int m, int y)
{
    int d1, m1;
    float newd1, newd2;
    float w;
    m1 = (y*12)+m;
    d1 = (m1*30.4368499)+d;
    w = (m1*4.348125)+(d*0.142857);
    newd1 = d1 - (int(w)*7);
    cout << "In months: " << m1 << " months " << d << " days." << endl;
    cout << "In weeks: " << int(w) << " weeks " << int(newd1) << " days." << endl;
    cout << "In Days: " << d1 << endl;
    cout << "In hours: " << d1*24 << endl;
    cout << "In minutes: " << d1*24*60 << endl;
    cout << "In seconds: " << d1*24*60*60 << endl;
    cout << "You have taken breaths of air around: " << double(d1*24*60) << endl;
    cout << "You have spent time for eating and drinking around: " << double(d1*1.12) << " hours." << endl;
    cout << "Your heart has beaten around: " << double(d1*24*60*72) << endl;
    cout << "You have eaten around: " << double(d1*1.81437) << " kilogram." << endl;
    cout << "You have slept around: " << double(d1*6) << " hours." << endl;
}
inline void calculate()
{
    int d, m, y;
    if(dob.year <= 2020 && dob.year >= 1920 && dob.month <= 12)
        {
                if(((dob.month == 1 || dob.month == 3 || dob.month == 5 || dob.month == 7 || dob.month == 8 || dob.month == 10 || dob.month == 12)&& dob.day <= 31) || ((dob.month == 4 || dob.month == 6 || dob.month == 9 || dob.month == 11) && dob.day <= 30) || ((dob.year % 4 == 0 && dob.year % 400 && dob.month == 2) && dob.day <= 29) || (dob.month == 2 && dob.day <= 28))
                {
                    if(dot.day < dob.day)
                    {
                            dot.day = dot.day + 30;
                            dot.month = dot.month - 1;
                    }
                    if(dot.month < dob.month)
                    {
                        dot.month = dot.month + 12;
                        dot.year = dot.year - 1;
                    }
                    if(dot.year >= dob.year)
                    {
                        d = dot.day - dob.day;
                        m = dot.month - dob.month;
                        y = dot.year - dob.year;
                    }
                }
                print(d, m, y);
                y:
                cout << "c to explore more, q to quit.... ";
                char ch2;
                ch2 = getche();
                if(ch2 == 'c')
                {
                    cout << endl << endl;
                    cnver(d, m, y);
                    getch();
                }
                else if(ch2 == 'q')
                {
                    exit(1);
                }
                else
                {
                    cout << endl << "Invalid entry." << endl;
                    goto y;
                }
        }
        else
            cout << "Seriously, Do you exist? :D\n";
}
int main()
{
    x:
    cout << "Enter your DOB <DD/MM/YYYY>: ";
    scanf("%d/%d/%d", &dob.day, &dob.month, &dob.year);
    cout << "You have entered " << dob.day << "/" << dob.month << "/" << dob.year << " <y/n>: ";
    register char ch;
    cin >> ch;
    if(ch == 'y' || ch == 'Y')
    {
        cout << "\nCalculating .... \n";
        calculate();
        getch();
    }
    else if(ch == 'n' || ch == 'N')
    {
        system("cls");
        cout << "Press enter to enter again.";
        getch();
        system("cls");
        goto x;
    }
    else
    {
        cout << "Invalid entry.\n";
        getch();
    }
    return 0;
}

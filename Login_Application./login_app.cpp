#include <iostream>
#include <array>
#include <fstream>
#include<sstream>
#include <vector>
#include <string>
#include <cctype>
#include <winsock2.h>
#include <windows.h>
#include <algorithm>
#include<regex>
#include<conio.h>
#include<cstring>
#include "LoginAPP.h";
using namespace std;
int choice = 0;


int main()
{
    int user_choice = 0;
    cout << "\nwelcome YA user YA Habibi !!\n\n";
    dataFile.open("Informations.txt", ios::app);
    while (user_choice != 4)
    {
        user_choice = getUserChoice();
        clearScreen();
        execute_choice(user_choice);
        if (user_choice != '0')
        {
            clearScreen();
        }
    }
    dataFile.close();
    cout << "\n!Thank you for chooing our Login APP program! \n\n";
    return 0;
}


void ignoreLine()
{
    cin.clear();
    cin.ignore(100, '\n');
}

void clearScreen()
{
    system("CLS");
    cout << flush;
    system("CLS");
}

int getUserChoice()
{
    int choice = 0;
    cout << "Plz select from the follownig choices: \n  " << endl;
    cout << "1. Registeration.\n\n" << endl;
    cout << "2. Login.\n\n" << endl;
    cout << "3. Change password.\n\n" << endl;
    cout << "4. Exit \n\n" << endl;
    while (!isValidChoice(choice))
    {
        cout << "Enter Your Choice: ";
        cin >> choice;
        while (cin.fail())
        {
            ignoreLine();
            cout << "please Enter a integer Not a letter: ";
            cin >> choice;

        }
        cin.clear();
        if (!isValidChoice(choice))
        {
            cout << "Please enter a valid choice from the options above." << endl;
        }
    }
    return choice;

}
bool isValidChoice(int choice)
{
    if (choice < 1 || choice > 5)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void execute_choice(int user_choice)
{

    if (user_choice == 1)
    {
        Registeration();
    }
    else if (user_choice == 2)
    {
        login();
    }
    else if (user_choice == 3) {
        change_password();
    }
}








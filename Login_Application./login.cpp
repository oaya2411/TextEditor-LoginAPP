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
using namespace std;

void passDecryption(string& password)
{
    for (int i = 0; i < password.size();i++)
    {
        if (password[i] == '{')
        {
            password[i] = password[i] - 2;
        }
        else
        {
            password[i] = password[i] - 1;
        }

    }

}


void login()
{
    compare();
    dataFile.open("Informations.txt", ios::app);
    bool validusername = false;
    int tries = 2;
    string name;
    string loginpassword, actually_password;
    cout << "Enter your username plz :" << endl;
    cin >> name;
    for (int j = 0; j < splitedData.size(); j += 4)
    {
        if (name == splitedData[j])
        {
            cout << "\nUsername found\n\n";
            validusername = true;
            cout << "Enter your password: \n";
            maskingpassword(loginpassword);
            actually_password = splitedData[j + 1];
            passDecryption(actually_password);
            while (loginpassword != actually_password)
            {
                tries--;
                cout << "Invaild password try again: \n";
                maskingpassword(loginpassword);
                if (tries == 0 && loginpassword != actually_password)
                {
                    cout << "\nYou are Denied for entering the System\n";
                    Sleep(1000);
                    break;
                }
            }
            if (loginpassword == actually_password)
            {
                cout << "##Successfully login welcom Ya ("<<name<< ") Ya Habibi##";
                cout << "\n\npress enter return the main menu: ";
                cin.ignore();
                char temp = 'x';
                while (temp != '\n')
                    temp = cin.get();
                break;
            }
            break;
        }
        if (name != splitedData[j] && j == splitedData.size() - 4)
        {
            cout << "Invalid User \n";
            cout << "Enter Username: \n";
            cin >> name;
            j = -4;
        }

    }




}
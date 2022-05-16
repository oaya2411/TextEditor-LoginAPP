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
// fstream dataFile;
ofstream outFile;
// vector<string> splitedData;
string newfilefull = "";
// int choice = 0;
void save()
{
    outFile.close();
    outFile.open("Informations.txt", ofstream::out | ios::trunc);
    outFile << newfilefull << endl;
    outFile.close();
}


void change_password()
{

    array <userInformation, 1> users;
    compare();
    bool  validusername = false, denied = false;
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
                    denied = true;
                    break;

                }
            }
            if (loginpassword == actually_password)
            {
                cout << "## Successfully login Welcome "<<name<<" ##" << endl;
                break;
            }
            break;
        }
    }
    if (!denied && validusername)
    {
        int format = 3;
        string oldpass;
        string newpass;
        string confirmpass;
        cout << "Enter the old password:\n";
        maskingpassword(oldpass);
        while (oldpass != actually_password)
        {
            cout << "Old password doesn't match try again: \n";
            cout << "Enter the old password:\n";
            maskingpassword(oldpass);
        }

        cout << "Enter the new password:\n";
        maskingpassword(newpass);
        while (newpass == oldpass)
        {
            cout << "The new password must not be the same old password: \n";
            cout << "Enter the new password:\n";
            maskingpassword(newpass);
        }
        while (!validpassword(newpass))
        {
            newpass = "";
            cout << "Plz Enter a password at least contain one digit & one letter: \n";
            maskingpassword(newpass);
        }

        cout << "Confirm the password:\n";
        maskingpassword(confirmpass);
        while (confirmpass != newpass)
        {
            confirmpass = "";
            cout << "Confirm password doesn't match the password\n";
            cout << "Confirm the password: \n";
            maskingpassword(confirmpass);
        }
        passEncryption(confirmpass);
        passEncryption(oldpass);
        for (int j = 0;j < splitedData.size();j += 4)
        {
            if (name == splitedData[j])
            {
                if (oldpass == splitedData[j + 1])
                {
                    splitedData[j + 1] = "";
                    splitedData[j + 1] = confirmpass;
                }
            }
        }

        cout << "Password changed successfully";
        newfilefull = "";
        for (int i = 0;i < splitedData.size();i++)
        {
            newfilefull += splitedData[i];
            newfilefull += '|';
            if (i == format && i != 0)
            {
                newfilefull += '\n';
                format += 4;
            }
        }
        newfilefull.pop_back();
        save();
        cout << "\n\npress enter return the main menu: ";
        cin.ignore();
        char temp = 'x';
        while (temp != '\n')
            temp = cin.get();

    }
    else
    {
        cout<<"Invalid username.";
        Sleep(799);
    }
}


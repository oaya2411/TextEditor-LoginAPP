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
fstream dataFile;
// ofstream outFile;
vector<string> splitedData;
// string newfilefull = "";
// int choice = 0;
struct userInformation
{
    string name, password, phone_number, email;
};
ostream& operator << (ostream& out, userInformation user)
{
    out << user.name << '|';
    out << user.password << '|';
    out << user.phone_number << '|';
    out << user.email << '|' << endl;

    return out;
}



bool validName(string name)
{
    regex standardName("[a-zA-Z-_.]+");
    return regex_match(name, standardName);
}

bool validpassword(string password)
{
    regex standardPassword("^(?=.*[0-9])(?=.*[a-zA-Z]).{3,16}$");
    return regex_match(password, standardPassword);
}
bool validphonenumber(string phone_number)
{
    regex standardPhone_number("^01[0125][0-9]{8}$");
    return regex_match(phone_number, standardPhone_number);
}
bool validEmail(string email)
{
    regex standardEmail("^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$");
    return regex_match(email, standardEmail);
}

void maskingpassword(string& password)
{
    password = "";
    char ch = ' ';
    while (ch != '\r')
    {
        ch = _getch();
        while (ch == '\b')
        {
            // Process a destructive backspace
            if (password.size() > 0)
            {
                password.erase(password.size() - 1, 1);
                cout << "\b \b";
            }
            ch = _getch();
        }                                //
        password += ch;
        cout << '*';
    }
    password.pop_back();
    cout << endl;
}

void passEncryption(string& password)
{
    for (int i = 0; i < password.size();i++)
    {
        if (password[i] == '{')
        {
            password[i] = password[i] + 2;
        }
        else
        {
            password[i] = password[i] + 1;
        }

    }

}
void split(string str, vector<string>& splitedData)
{
    splitedData.clear();
    stringstream data;
    string line;
    data << str;
    while (getline(data, line, '|'))
    {
        splitedData.push_back(line);
    }

}
void compare()
{
    dataFile.close();
    dataFile.open("Informations.txt", ios::in);
    stringstream strstream;
    string str = "";
    strstream << dataFile.rdbuf();
    str = strstream.str();
    str.erase(remove(str.begin(), str.end(), '\n'), str.end());
    split(str, splitedData);
}

void Registeration()
{
    dataFile.open("Informations.txt", ios::app);
    array <userInformation, 1> users;
    compare();
    for (int i = 0;i < users.size();i++)
    {
        cout << "Enter username: \n";
        cout << "Note: username must not contain digits\n";
        cin >> users[i].name;
        while (!validName(users[i].name))
        {
            cout << "Plz Enter a valid name no digit or special characters in it: \n";
            cin >> users[i].name;
        }

        for (int j = 0;j < splitedData.size();j += 4)
        {
            while (users[i].name == splitedData[j])
            {
                cout << "Username is already Taken! Choose another username: \n";
                cin >> users[i].name;
                while (!validName(users[i].name))
                {
                    users[i].name = "";
                    cout << "Plz Enter a valid name no digit or special characters in it: \n";
                    cout << "Enter username: \n";
                    cin >> users[i].name;
                }
                j = 0;
            }
        }
        cout << "Enter email: \n";
        cin >> users[i].email;
        while (!validEmail(users[i].email))
        {
            users[i].email = "";
            cout << "Invalid Email plz enter a email follows an Email proper format: \n";
            cout << "Enter email: \n";
            cin >> users[i].email;
        }
        //compare();
        for (int j = 3;j < splitedData.size();j += 4)
        {
            while (users[i].email == splitedData[j])
            {
                cout << "Email is already Taken! Choose another Email: \n";
                cin >> users[i].email;
                while (!validEmail(users[i].email))
                {
                    users[i].email = "";
                    cout << "Invalid Email plz enter a email follows an Email proper format: \n";
                    cout << "Enter email: \n";
                    cin >> users[i].email;
                }
                j = 3;
            }
        }
        dataFile.close();
        dataFile.open("Informations.txt", ios::app);
        cout << "Enter password: \n";
        cout << "note: the password must contain digits: \n";
        maskingpassword(users[i].password);
        while (!validpassword(users[i].password))
        {
            cout << "Plz Enter a password at least contain one digit & one letter: \n";
            users[i].password = "";
            maskingpassword(users[i].password);
        }
        string confirm = "";
        cout << "Confirm the password: \n";

        maskingpassword(confirm);
        while (confirm != users[i].password)
        {
            confirm = "";
            cout << "Confirm password doesn't match the password\n";
            cout << "Confirm the password: \n";
            maskingpassword(confirm);
        }
        passEncryption(confirm);
        users[i].password = confirm;
        cout << "Enter phone_number: \n";
        cout << "The phone number must be in 01xxxxxxxxx: \n";
        cin >> users[i].phone_number;
        while (!validphonenumber(users[i].phone_number))
        {
            users[i].phone_number = "";
            cout << "Invaild number!\n";
            cout << "Enter the a phone nubmer in Egyptian format: \n";
            cin >> users[i].phone_number;
        }
        for (int j = 2;j < splitedData.size();j += 4)
        {
            while (users[i].phone_number == splitedData[j])
            {
                cout << "Number  is already Taken! Choose another Number: \n";
                cin >> users[i].phone_number;
                while (!validphonenumber(users[i].phone_number))
                {
                    users[i].phone_number = "";
                    cout << "Invaild number!\n";
                    cout << "Enter the a phone nubmer in Egyptian format: \n";
                    cin >> users[i].phone_number;
                }
                j = 2;
            }
        }
    }
    dataFile << users[0];
    dataFile.close();
    cout << "##Data saved##";
    cout << "\n\npress Enter to continue: ";
    cin.ignore();
    char temp = 'x';
    while (temp != '\n')
        temp = cin.get();
}
// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: TextEditor.cpp
// Last Modification Date: 16/5/2022
// Author1 and ID and Group: Yousef Alaa s17
// Author2 and ID and Group: Ali Hegazy  s17
// Author3 and ID and Group: Aya Osama   s17
// Teaching Assistant: Hager Ali
// Purpose: Making TextEditor Application
#include <iostream>
#include <fstream>
#include <winsock2.h>
#include <windows.h>
#include <sstream>
#include <algorithm>
#include <string>
#include <conio.h>
#include "textEditor.h"


using namespace std;
fstream dataFile, newfile;
char name[81];
ofstream outFile;
ostringstream strstream;
string str;

void execute(int user);
void loadText();
bool isValidChoice(int user);
void ignoreLine();
int getUserChoice();
void save();




int main()
{
    int user = 0;
    cout << "Pls Enter the file name to deal with (filename.extension): ";
    cin >> name;
    dataFile.open(name, ios::in);
    if (dataFile.fail())
    {
        cf = true;
        dataFile << name;
        dataFile.open(name, ios::out);
        dataFile.close();
        dataFile.open(name, ios::in);
        cout << "This is a new file. I created it for you !";
        Sleep(1000);
        clearScreen();
        loadText();
        while (user != 16)
        {
            user = getUserChoice();
            execute(user);
            if (user != '0')
            {
                clearScreen();
            }
        }
        dataFile.close();
    }
    else
    {
        dataFile.open(name, ios::in);
        cout << "This File Already Exists\n";
        Sleep(1000);
        clearScreen();
        loadText();
        while (user != 16)
        {
            user = getUserChoice();
            execute(user);
            if (user != '0')
            {
                clearScreen();
            }
        }
        dataFile.close();
        cout << "\n!Thank you for chooing our Text Editor program! \n\n";
        return 0;

    }
}
bool isValidChoice(int user)
{
    if (user < 1 || user > 16)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void ignoreLine()
{
    cin.clear();
    cin.ignore(100, '\n');
}
int getUserChoice()
{
    int user = 0;
    cout << "Plz select an option to apply or 16 to exit: \n";
    cout << "1. Add new text to the end of the file." << endl;
    cout << "2. Display the content of the file." << endl;
    cout << "3. Empty the file." << endl;
    cout << "4. Encrypt the file content." << endl;
    cout << "5. Decrypt the file content" << endl;
    cout << "6. Merge another file" << endl;
    cout << "7. Count the number of words in the file." << endl;
    cout << "8. Count the number of characters in the file." << endl;
    cout << "9. Count the number of lines in the file." << endl;
    cout << "10. Search for a word in the file." << endl;
    cout << "11. Count the number of times a word exists in the file." << endl;
    cout << "12. Turn the file content to upper case." << endl;
    cout << "13. Turn the file content to lower case." << endl;
    cout << "14. Turn file content to 1st caps." << endl;
    cout << "15. Save." << endl;
    cout << "16. Exit." << endl;

    while (!isValidChoice(user))
    {
        cout << "Enter Your Choice: ";
        cin >> user;
        while (cin.fail())
        {
            ignoreLine();
            cout << "please Enter a integer Not a letter: ";
            cin >> user;

        }
        cin.clear();
        if (!isValidChoice(user))
        {
            cout << "Please enter a valid choice from the options above." << endl;
        }
    }
    return user;


}


void loadText()
{
    strstream << dataFile.rdbuf();
    str = strstream.str();
}



void execute(int user)
{
    if (user == 1)
    {
        function1();        
    }
    else if (user == 2)
    {
        function2();
    }
    else if (user == 3)
    {
        function3();
    }
    else if (user == 4) 
    {
        function4();
    }
    else if (user == 5) 
    {
        function5();
    }
    else if (user == 6)
    {
        function6();
    }
    else if (user == 7)
    {
        function7();
    }
    else if (user == 8)
    {
        function8();
    }
    else if (user == 9)
    {
        function9();
    }
    else if (user == 10)
    {
        function10();
    }
    else if (user == 11)
    {
        function_11();
    }
    else if (user == 12)
    {
        function_12();
    }
    else if (user == 13)
    {
        function_13();
    }
    else if (user == 14)
    {
        function_14();
    }
    else if (user == 15)
    {
        save_file();
    }
}


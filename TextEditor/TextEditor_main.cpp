// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: TextEditor.cpp
// Last Modification Date: xx/xx/xxxx
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
#include "20210478.h"

using namespace std;

void execute(int user);
void loadText();
void clearScreen();
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
void clearScreen()
{
    system("CLS");
    cout << flush;
    system("CLS");
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
        str = "";
    }
    else if (user == 4) 
    {
        string encrypt;
        encrypt = str;
        cout << "\n";
        char n;
        str = "";
        for (int i = 0; i < encrypt.size(); i++) 
        {
            if ((char)encrypt.at(i) != 10 || (char)encrypt.at(i) != 13) 
            {
                n = char(encrypt.at(i) + 1);
                dataFile << n;
                str +=n;
            }
            else
                dataFile << "/n";
        }
    }
    else if (user == 5) 
    {
        string decrypt;
        decrypt = str;
        cout << "\n";
        str = "";
        char n;
        for (int i = 0; i < decrypt.size(); i++) 
        {
            if ((char)decrypt.at(i) != 10 || (char)decrypt.at(i) != 13) {
                n = char(decrypt.at(i) - 1);
                dataFile << n;
                str +=n;
            }
            else
                dataFile << "/n";
        }
        dataFile.close();
    }


    else if (user == 6)
    {
        fstream mergefile;
        ostringstream mergestream;
        string merged, anotherfile;
        cout << "Enter the merged file: ";
        cin >> anotherfile;
        mergefile.open(anotherfile, ios::in);
        mergestream << mergefile.rdbuf();
        merged = mergestream.str();
        str += '\n';
        str += merged;


    }
    else if (user == 7)
    {
        string word;
        int count = 0;
        dataFile.clear();
        dataFile.seekg(0, dataFile.beg);
        while (!dataFile.eof())
        {
            dataFile >> word;
            count += 1;
        }

        cout << count - 1 << endl;
        cout << "\n\npress enter to continue: ";
        cin.ignore();
        char temp = 'x';
        while (temp != '\n')
            temp = cin.get();
    }
    else if (user == 8)
    {

        char word;
        int count = 0;
        dataFile.clear();
        dataFile.seekg(0, dataFile.beg);
        while (!dataFile.eof())
        {
            dataFile >> word;
            count += 1;
        }
        cout << count - 1 << endl;
        cout << "\n\npress Enter to continue: ";
        cin.ignore();
        char temp = 'x';
        while (temp != '\n')
            temp = cin.get();
    }

    else if (user == 9)
    {

        string line;
        int count = 0;
        dataFile.clear();
        dataFile.seekg(0, dataFile.beg);
        while (getline(dataFile, line))
        {
            count += 1;
        }
        cout << count;
        cout << "\n\npress Enter to continue: ";
        cin.ignore();
        char temp = 'x';
        while (temp != '\n')
            temp = cin.get();
    }

    else if (user == 10)
    {
        string word;
        int count=0;
        string word_in_file;
        cout<<"enter the word to search for: ";
        cin>>word;
        dataFile.clear();
        dataFile.seekg(0, dataFile.beg);
        for (int i = 0;i <  word.length();i++)
        {
            word[i] = tolower(word[i]);
        }
        while(!dataFile.eof())
        {
            dataFile>>word_in_file;
            for (int i = 0;i <  word.length();i++)
            {
                word_in_file[i] = tolower(word_in_file[i]);
            }
            if(word==word_in_file)
                count+=1;
        }
            if(count>=1)
                cout<<"word was found :)"<<endl;
            else
                cout<<"word wasn't found :(\n";

            cout << "\n\npress Enter to continue: ";
            cin.ignore();
            char temp = 'x';
            while (temp != '\n')
                temp = cin.get();
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



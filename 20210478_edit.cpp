#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <algorithm>
using namespace std;
fstream dataFile, newfile;	char name[81];
ofstream outFile;
stringstream strstream;
string str;
bool tries = true;
void execute(int user);
void clearScreen()
{
    system("CLS");
    cout << flush;
    system("CLS");
}
//bool isvalidint(int user)
//{
//
//}
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
        cin.clear();
        if (!isValidChoice(user))
        {
            cout << "Please enter a valid choice from the options above." << endl;
        }
    }
    return user;


}
int main()
{
    int user = 0;
    cout << "Pls Enter the file name to deal with (filename.extension): ";
    cin >> name;
    dataFile.open(name, ios::in);
    if (dataFile.fail())
    {
        dataFile << name;
        dataFile.open(name, ios::out);
        cout << "This is a new file. I created it for you !";
        Sleep(1000);
        clearScreen();
        while (user != 16)
        {
            user = getUserChoice();
            execute(user);
            if (user != '0')
            {
                clearScreen();
            }
        }
    }
    else
    {
        cout << "This File Already Exists\n";
        Sleep(1300);
        clearScreen();
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
        cout << "Thank you for chooing our Text Editor program ";
        return 0;

    }
}
void execute(int user)
{
    
    if (user == 2)
    {
        cout << "\n";
        
        while (tries)
        {
            strstream << dataFile.rdbuf();
            str = strstream.str();
            tries = false;
        }
        cout << str;
        Sleep(2000);
    }
    else if (user == 11)
    {
        int m = 0;
        int drop, coun(0);
        string upp, true_repeat;
        string repeat, line,without;
        cout << "Enter the word to count: ";
        cin >> repeat;
        for (int i = 0;i < repeat.length();i++)
        {
            true_repeat += tolower(repeat[i]);
        }
        without = str;
        for (int i = 0;i < without.length();i++)
        {
            if (without[i] == '\n')
            {
                without[i] = ' ';
            }
        }
        for (int i = 0;i < without.length();i++)
        {
            upp += tolower(without[i]);
        }
        for (int i = 0;i<upp.length();++i)
        {
            if (i == upp.length() - 1)
            {
                for (m; m <= i; m++)
                {
                    line += upp[m];
                }
            }
            if (upp[i] == ' ' &&upp[i+1]!=' ')
            {
                for (m; m < i; m++)
                {
                    line += upp[m];
                }
                if (line == true_repeat)
                {
                    coun++;
                }
                m = i + 1;
                line = "";
            }
            else
            {
                continue;
            }
        }
        if (coun > 0)
        {
            cout << "The word " << repeat << " found " << coun << " times.";
            Sleep(2000);
        }
        else
        {
            cout << "\nThe word " << repeat << " was not found in the file.";
            Sleep(2000);
        }

    }
    else if (user == 12)
    {
        string upp;


        for (int i = 0;i < str.length();i++)
        {
            upp += toupper(str[i]);
        }
        outFile.open(name, ofstream::out | ios::trunc);
        outFile << upp << endl;
        cout << "\nDone!";
        Sleep(2000);
        str = upp;
        upp = "";
    }
    else if (user == 13)
    {
        string upp;
        for (int i = 0;i < str.length();i++)
        {
            upp += tolower(str[i]);
        }
        outFile.open(name, ofstream::out | ios::trunc);
        outFile << upp << endl;
        cout << "\nDone!";
        Sleep(3000);
        str = upp;
        upp = "";
    }
}
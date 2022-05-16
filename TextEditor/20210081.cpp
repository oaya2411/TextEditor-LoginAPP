#include <iostream>
#include <fstream>
#include <winsock2.h>
#include <windows.h>
#include <sstream>
#include <algorithm>
#include <string>
#include <conio.h>

using namespace std;
extern fstream dataFile, newfile;
extern char name[81];
extern ofstream outFile;
extern ostringstream strstream;
extern string str;
bool cf = false;


void clearScreen()
{
    system("CLS");
    cout << flush;
    system("CLS");
}

void function1()//this function to add more texts to the main txt file.
{
string newtext;
        cout << "Enter the new string to add: ";
        cin.ignore();//to ignore any input into the buffer.
        getline(cin, newtext);
        if (cf)//if the main file has a text on it.
        {
            str += newtext;//add the new elements to the main file, So str is the string into the main file and the newtext is the string which on the old one. 
            save(name);//save all the commits.
            cf = false;
        }
        else //else that the main file is empty.
        {
            str += '\n';//to start with anewline
            str += newtext;//add the other content into it.
        }
        save(name);
}
void function2()//to show the text into the file.
{
  cout << "\n";
        clearScreen();
        cout << "The Text is:\n";
        cout << "-----------------------------------------------------------------|\n";
        cout << str;//str is all text into the file as it shown on the function of load screen.
        cout << "\n\npress enter to continue: ";
        cin.ignore();
        char temp = 'x';
        while (temp != '\n')
            temp = cin.get();
}
void function3()//delete all things into the file.
{
    str = "";//replace all the content with empty content.
}

void function4(){//encrypt the file
    string encrypt;
        encrypt = str;
        cout << "\n";
        char n;//to load the encrypted text into a text but character by character.
        str = "";//empty the string to full the file with new encrypted text.
        for (int i = 0; i < encrypt.size(); i++) //loop to check all the content of the file.
        {
            if ((char)encrypt.at(i) != 10 || (char)encrypt.at(i) != 13) //check to ignore the newline.
            {
                n = char(encrypt.at(i) + 1);//if it is a char we replace the old char with new one.
                dataFile << n;
                str +=n;//add the encrypted char to str.
            }
            else
                dataFile << "/n";
        }
}
void function5(){//decrypt all data
    string decrypt;
        decrypt = str;
        cout << "\n";
        str = "";
        char n;
        for (int i = 0; i < decrypt.size(); i++) 
        {
            if ((char)decrypt.at(i) != 10 || (char)decrypt.at(i) != 13) {
                n = char(decrypt.at(i) - 1);//here we shifted one to back so if the char is d it will be (d--> c).
                dataFile << n;
                str +=n;
            }
            else
                dataFile << "/n";
        }
        dataFile.close();//close file to force flush.
}



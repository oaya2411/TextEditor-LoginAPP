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
// void save(const  char* filename)
// {
//     outFile.open(filename, ofstream::out | ios::trunc);
//     outFile << str << endl;
//     outFile.close();
// }
void clearScreen()
{
    system("CLS");
    cout << flush;
    system("CLS");
}

void function1()
{
string newtext;
        cout << "Enter the new string to add: ";
        cin.ignore();
        getline(cin, newtext);
        if (cf)
        {
            str += newtext;
            save(name);
            cf = false;
        }
        else 
        {
            str += '\n';
            str += newtext;
        }
        save(name);
}
void function2()
{
  cout << "\n";
        clearScreen();
        cout << "The Text is:\n";
        cout << "-----------------------------------------------------------------|\n";
        cout << str;
        cout << "\n\npress enter to continue: ";
        cin.ignore();
        char temp = 'x';
        while (temp != '\n')
            temp = cin.get();
}
void function3()
{
    str = "";
}

void function4(){
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
void function5(){
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



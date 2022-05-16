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

void function6()
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
void function7()
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
void function8()
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

void function9()
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
void function10()
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

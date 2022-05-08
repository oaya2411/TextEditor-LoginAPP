using namespace std;

fstream dataFile, newfile;
char name[81];
ofstream outFile;
ostringstream strstream;
string str;
bool cf = false;

void save(const  char* filename)
{
    outFile.open(filename, ofstream::out | ios::trunc);
    outFile << str << endl;
    outFile.close();
}



void function_11()
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
        cout<<"word was found "<<count<<" Times"<<endl;
    else
        cout<<"word wasn't found :(\n";

    cout << "\n\npress Enter to continue: ";
    cin.ignore();
    char temp = 'x';
    while (temp != '\n')
        temp = cin.get();    
}

void function_12()
{
    string upp;
    for (int i = 0;i < str.length();i++)
    {
        upp += toupper(str[i]);
    }
    str = upp;
    str.erase(remove(str.end() - 1, str.end(), '\n'), str.end());
    cout << "\nDone!";
    Sleep(1000);
}


void function_13()
{
    string upp;
    for (int i = 0;i < str.length();i++)
    {
        upp += tolower(str[i]);
    }
    str = upp;
    cout << "\nDone!";
    Sleep(1000);
}


void function_14()
{
    int m = 0;
        int drop, coun(0);
        string upp = "", line = "", without = "";
        without = str;
        for (int i = 0;i < without.length();i++)
        {
            upp += tolower(without[i]);
        }
        for (int x = 0; x < upp.length(); x++)
        {
            if (x == 0)
            {
                upp[x] = toupper(upp[x]);
            }
            else if (upp[x - 1] == ' ')
            {
                upp[x] = toupper(upp[x]);
            }
            else if (upp[x - 1] == '\n' && isalpha(upp[x]))
            {
                upp[x] = toupper(upp[x]);
            }
        }
        str = upp;
}

void save_file()
{
        cout<<"Enter a new file name or press enter to save on the same file:";
        cin.ignore();
        char temp = 'x';
        string filename;
        while (true)
        {
            temp = cin.get();
            if (temp == '\n')
                break;
            filename.push_back(temp);
        }
        if (filename == "")
        {
            cout<<"Text saved in the same file.";
            save((name));
            Sleep(700);
        }
        else
        {
            cout<<"Text saved in the new file.";
            save(filename.c_str());   
            Sleep(700);
        } 
}


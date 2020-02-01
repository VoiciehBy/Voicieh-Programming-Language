#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

void pause_n_clear()
{
#ifdef _WIN32
    system("ECHO Aby przejsc dalej nacisnij dowolny klawisz . . .");
    system("ECHO Przyciski typu zasilanie nie wchodza w gre,hehe . . .");
    system("PAUSE >NUL");
    system("CLS");
#elif __unix__
    system("echo Aby przejsc dalej nacisnij dowolny klawisz . . .");
    system("echo Przyciski typu zasilanie nie wchodza w gre,hehe . . .");
    system("read -p ... .");
    system("clear");
#elif __APPLE__
    cout << "JABKO..." << endl;
    system("echo Aby przejsc dalej nacisnij dowolny klawisz . . .");
    system("echo Przyciski typu zasilanie nie wchodza w gre,hehe . . .");
    system("read -p ... .");
    system("clear");
#else
    cout << "OS not supported!" << endl;
#endif
}

void clear_window()
{
#ifdef _WIN32
    system("CLS");
#elif __unix__
    system("clear");
#elif __APPLE__
    cout << "APPLE..." << endl;
    system("clear");
#else
    cout << "OS not supported!" << endl;
#endif
}

void open_file(string &filename)
{
#ifdef _WIN32
    filename = '"' + filename;
    filename += '"';
    string win = "TYPE " + filename;
    cout << win << endl;
    char* temp = new char [win.length()+1];
    for(int i = 0; i < win.length(); i++)
        temp[i] = win[i];
    temp[win.length()] = 0;
    system(temp);
#elif __unix__
    string linux = "cat " + filename;
    char* temp = new char [linux.length()];
    for(int i = 0; i < linux.length(); i++)
        temp[i] = linux[i];
    temp[linux.length()] = 0;
    system(temp);
#elif __APPLE__
    cout << "APPLE..." << endl;
    string apple = "cat" + filename;
    char* temp = new char [apple.length()];
    for(int i = 0; i < linux.length(); i++)
        temp[i] = apple[i];
    temp[apple.length()] = 0;
    system(temp);
#else
    cout << "OS not supported!" << endl;
#endif
}

void convert_to_lower_case(string &s)
{
    for(int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i] );
}

void print_opening()
{
    cout << " VV         VV OOOO IIIII" << endl
         << "  VV       VV O    O  I" << endl
         << "   V       V  O    O  I" << endl
         << "    V     V   O    O  I" << endl
         << "     V   V    O    O  I" << endl
         << "      V V     O    O  I" << endl
         << "       V       OOOO IIIII" << endl
         << "Copyright (C) 2019 - 2020 Wojcieh Bia³ek" << endl
         << "This program comes with ABSOLUTELY NO WARRANTY." << endl
         << "This is free software, and you are welcome to redistribute it." << endl
         << "under certain conditions for details read LICENSE." << endl;
}

void print_help(string* keywords,string* description)
{
    cout << "Lista slovek kluczowych:" << endl;
    for(int i=0; i<22; i++)
        cout << "-";
    cout << endl;
    for (int i=0; i<15; i++)
        cout << "<" << keywords[i] << ">" << "::=" << description[i] << endl;
}

void get_from_file_to_array(string filename,string* array_a,int s_i_z_e,char delimiter)
{
    string s;
    ifstream fptr (filename);
    for(int i = 0; i < s_i_z_e; i++)
    {
        getline(fptr,s,delimiter);
        array_a[i] = s;
    }
    fptr.close();
}

void show_interpreter_in_console()
{
    print_opening();

    pause_n_clear();

    int a=0;
    string input;
    string* keywords = new string[17];
    string* descriptions = new string[15];

    get_from_file_to_array("keywords.voi",keywords,17,' ');
    get_from_file_to_array("descriptions.voi",descriptions,15,',');

    while(3!=5)
    {
        cout << "VOI" << endl;
        cin >> input;
        convert_to_lower_case(input);

        if( input == keywords[0] )
            cout << "Witaj kmiocie!" << endl;
        else if( input == keywords[1] )
        {
            cout << "Podaj zawartosc pojemnika 'a'." << endl
                 << "a:";
            cin >> a;
        }
        else if( input == keywords[2] )
            cout << "Zawartosc pojemnika 'a':" << a << endl;
        else if( input == keywords[3] || input == keywords[5] )
        {
            int bucket = 0;
            cout << "Podaj wartosc,ktora zostanie dodana do pojemnika 'a':" << endl;
            cin >> bucket;
            a+=bucket;
            bucket=0;
        }
        else if( input == keywords[4] || input == keywords[6] )
        {
            int bucket = 0;
            cout << "Podaj wartosc,ktora zostanie odjeta od pojemnika 'a':" << endl;
            cin >> bucket;
            a-=bucket;
        }
        else if( input == keywords[7] )
        {
            int bucket = 0;
            cout << "Podaj wartosc,przez ktora zostanie pomnozona zawartosc pojemnika 'a':" << endl;
            cin >> bucket;
            a*=bucket;
        }
        else if( input == keywords[8] )
        {
            int bucket;
            while(bucket == 0)
            {
                cout << "Podaj wartosc,przez ktora zostanie podzielona zawartosc pojemnika 'a':" << endl;
                cin >> bucket;
            }
            a/=bucket;
        }
        else if( input == keywords[9] )
            clear_window();
        else if( input == keywords[10] )
            return;
        else if( input == keywords[11] )
        {
            string s,filename;
            ofstream file;
            cout << "Podaj nazwe pliku:";
            cin >> filename;
            filename += ".voi";
            file.open(filename);
            file << "Plik zostal utworzony za pomocom jenzyka VOICIEH."<< "\n"<< "-------------------------------------------------";
            cout << "Podaj wyraz do dopisania:";
            cin >> s;
            file << "\n" << s ;
            file.close();
        }
        else if( input == keywords[12] )
        {
            string s,filename;
            ofstream file;
            cout << "Podaj nazwe pliku:";
            cin >> filename;
            filename += ".voi";
            file.open(filename,ios::app);
            cout << "Podaj wyraz nadpisujoncy:";
            cin >> s;
            file << "\n" << s ;
            file.close();
        }
        else if( input == keywords[13] )
        {
            string s;
            cin >> s;
            cout << "Witaj kmiocie!" << endl
                 << s << "?" << endl;
        }
        else if( input == keywords[14] )
        {
            string filename;
            cout << "Podaj nazwe pliku:";
            cin >> filename;
            filename += ".voi";
            open_file(filename);
            cout << endl
                 << "KONIEC PLIKU" << endl;
        }
        else if( input == keywords[15] || input == keywords[16] )
            print_help(keywords,descriptions);
        else
            cout << "Brak takiego slovka w slovnika" << endl;
    }
}

int main()
{
    show_interpreter_in_console();
    return 0;
}

//    Program is an interpreter of my own programming language called 'Voicieh' in short 'VPL'.
//    Copyright (C) 2019 - 2020 Wojcieh Bia³ek
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.

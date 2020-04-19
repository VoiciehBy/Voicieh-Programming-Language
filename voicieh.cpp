#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

std::string filename()
{
    std::string filename;
    std::cout << "Podaj nazwe pliku:";
    std::cin >> filename;
    filename += ".voi";
    return filename;
}

void pause_n_clear()
{
    std::cout << "Aby przejsc dalej nacisnij dowolny klawisz . . ." << std::endl
              << "Przyciski typu zasilanie nie wchodza w gre,hehe . . ." << std::endl
              << "...";
    std::cin.get();

#ifdef _WIN32
    system("CLS");
#elif __unix__
    system("clear");
#elif __APPLE__
    std::cout << "JABKO..." << std::endl;
    system("clear");
#else
    std::cout << "OS not supported!" << std::endl;
#endif
}

void clear_window()
{
#ifdef _WIN32
    system("CLS");
#elif __unix__
    system("clear");
#elif __APPLE__
    std::cout << "APPLE..." << std::endl;
    system("clear");
#else
    std::cout << "OS not supported!" << std::endl;
#endif
}

void open_file(std::string &filename)
{
#ifdef _WIN32
    filename = '"' + filename;
    filename += '"';
    std::string win = "TYPE " + filename;
    std::cout << win << std::endl;
    char* temp = new char [win.length()+1];
    for(int i = 0; i < win.length(); i++)
        temp[i] = win[i];
    temp[win.length()] = 0;
    system(temp);
#elif __unix__
    std::string linux = "cat " + filename;
    char* temp = new char [linux.length()];
    for(int i = 0; i < linux.length(); i++)
        temp[i] = linux[i];
    temp[linux.length()] = 0;
    system(temp);
#elif __APPLE__
    std::cout << "APPLE..." << std::endl;
    std::string apple = "cat" + filename;
    char* temp = new char [apple.length()];
    for(int i = 0; i < linux.length(); i++)
        temp[i] = apple[i];
    temp[apple.length()] = 0;
    system(temp);
#else
    std::cout << "OS not supported!" << std::endl;
#endif
}

void convert_to_lower_case(std::string &s)
{
    for(int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i] );
}

void nadpisz()
{
    std::string s,fname = filename();
    std::ofstream file;
    file.open(fname);
    file << "Plik zostal utworzony za pomocom jenzyka VOICIEH."<< "\n"<< "-------------------------------------------------";
    std::cout << "Podaj wyraz do dopisania:";
    std::cin >> s;
    file << "\n" << s ;
    file.close();
}

void dopisz()
{
    std::string s,fname = filename();
    std::ofstream file;
    file.open(fname,std::ios::app);
    std::cout << "Podaj wyraz nadpisujoncy:";
    std::cin >> s;
    file << "\n" << s ;
    file.close();
}

void powiedz()
{
    std::string s;
    std::cin >> s;
    std::cout << "Witaj kmiocie!" << std::endl
              << s << "?" << std::endl;
}

void otworz()
{
    std::string fname = filename();
    open_file(fname);
    std::cout << std::endl
              << "KONIEC PLIKU" << std::endl;
}

void print_help(std::string* keywords,std::string* description)
{
    std::cout << "Lista slovek kluczowych:" << std::endl;
    for(int i=0; i<22; i++)
        std::cout << "-";
    std::cout << std::endl;
    for (int i=0; i<15; i++)
        std::cout << "<" << keywords[i] << ">" << "::=" << description[i] << std::endl;
}

void get_from_file_to_array(std::string filename,std::string* array_a,int s_i_z_e,char delimiter)
{
    std::string s;
    std::ifstream fptr (filename);
    for(int i = 0; i < s_i_z_e; i++)
    {
        getline(fptr,s,delimiter);
        array_a[i] = s;
    }
    fptr.close();
}

void show_interpreter_in_console()
{
    std::string opening = " VV         VV OOOO IIIII\n  VV       VV O    O  I\n   V       V  O    O  I\n    V     V   O    O  I\n     V   V    O    O  I\n      V V     O    O  I\n       V       OOOO IIIII\nCopyright (C) 2019 - 2020 Wojcieh Bia³ek\nThis program comes with ABSOLUTELY NO WARRANTY.\nThis is free software, and you are welcome to redistribute it.\nunder certain conditions for details read LICENSE.\n";
    std::cout << opening;
    pause_n_clear();

    int a=0;
    std::string input;
    std::string* keywords = new std::string[17];
    std::string* descriptions = new std::string[15];
    get_from_file_to_array("keywords.voi",keywords,17,' ');
    get_from_file_to_array("descriptions.voi",descriptions,15,',');

    while(3!=5)
    {
        std::cout << "VOI" << std::endl;
        std::cin >> input;
        convert_to_lower_case(input);

        if( input == keywords[0] )
            std::cout << "Witaj kmiocie!" << std::endl;
        else if( input == keywords[1] )
        {
            std::cout << "Podaj zawartosc pojemnika 'a'." << std::endl
                      << "a:";
            std::cin >> a;
        }
        else if( input == keywords[2] )
            std::cout << "Zawartosc pojemnika 'a':" << a << std::endl;
        else if( input == keywords[3] || input == keywords[5] )
        {
            int bucket = 0;
            std::cout << "Podaj wartosc,ktora zostanie dodana do pojemnika 'a':" << std::endl;
            std::cin >> bucket;
            a+=bucket;
            bucket=0;
        }
        else if( input == keywords[4] || input == keywords[6] )
        {
            int bucket = 0;
            std::cout << "Podaj wartosc,ktora zostanie odjeta od pojemnika 'a':" << std::endl;
            std::cin >> bucket;
            a-=bucket;
        }
        else if( input == keywords[7] )
        {
            int bucket = 0;
            std::cout << "Podaj wartosc,przez ktora zostanie pomnozona zawartosc pojemnika 'a':" << std::endl;
            std::cin >> bucket;
            a*=bucket;
        }
        else if( input == keywords[8] )
        {
            int bucket;
            while(bucket == 0)
            {
                std::cout << "Podaj wartosc,przez ktora zostanie podzielona zawartosc pojemnika 'a':" << std::endl;
                std::cin >> bucket;
            }
            a/=bucket;
        }
        else if( input == keywords[9] )
            clear_window();
        else if( input == keywords[10] )
            return;
        else if( input == keywords[11] )
            nadpisz();
        else if( input == keywords[12] )
            dopisz();
        else if( input == keywords[13] )
            powiedz();
        else if( input == keywords[14] )
            otworz();
        else if( input == keywords[15] || input == keywords[16] )
            print_help(keywords,descriptions);
        else
            std::cout << "Brak takiego slovka w slovnika" << std::endl;
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

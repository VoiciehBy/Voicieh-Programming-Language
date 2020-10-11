#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
#include "Bucket.h"

std::string filename() {
    std::string filename;
    std::cout << "Podaj nazwe pliku:";
    std::cin >> filename;
    filename += ".voi";
    return filename;
}

void pause_n_clear() {
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

void clear_window() {
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

void open_file(std::string &filename) {
    char* fn = new char[filename.size()];
    int j = filename.size();
    for(int i = 0; i < j; i++)
        fn[i] = filename[i];
    FILE* fptr = fopen(fn,"r");

    if(!fptr) {
        std::cout << "NIE MOZNA OTWORZYC PLIKU" << std::endl;
    } else {
        char ch;
        while(!feof(fptr)) {
            ch = getc(fptr);
            putchar(ch);
        }
    }

    fclose(fptr);
}

void convert_to_lower_case(std::string &s) {
    for(unsigned int i = 0; i < s.length(); i++)
        s[i] = tolower(s[i] );
}

void nadpisz() {
    std::string s,fname = filename();
    std::ofstream file;
    file.open(fname);
    file << "Plik zostal utworzony za pomocom jenzyka VOICIEH."<< "\n"<< "-------------------------------------------------";
    std::cout << "Podaj wyraz nadpisujoncy:";
    std::cin >> s;
    file << "\n" << s ;
    file.close();
}

void dopisz() {
    std::string s,fname = filename();
    std::ofstream file;
    std::cout << "Podaj wyraz do dopisania:";
    file.open(fname,std::ios::app);
    std::cin >> s;
    file << "\n" << s ;
    file.close();
}

void powiedz() {
    std::string s;
    std::cin >> s;
    std::cout << "Witaj kmiocie!" << std::endl
              << s << "?" << std::endl;
}

void otworz() {
    std::string fname = filename();
    open_file(fname);
    std::cout << std::endl
              << "KONIEC PLIKU" << std::endl;
}

void print_help(std::string* keywords,std::string* description) {
    std::cout << "Lista slovek kluczowych:" << std::endl;
    for(int i=0; i<22; i++)
        std::cout << "-";
    std::cout << std::endl;
    for (int i=0; i<15; i++)
        std::cout << "<" << keywords[i] << ">" << "::=" << description[i] << std::endl;
}

void get_from_file_to_array(std::string filename,std::string* array_a,int s_i_z_e,char delimiter) {
    std::string s;
    std::ifstream fptr (filename);
    for(int i = 0; i < s_i_z_e; i++) {
        getline(fptr,s,delimiter);
        array_a[i] = s;
    }
    fptr.close();
}

int getInputInt() {
    int i;
    std::cin >> i;
    return i;
}

void show_interpreter_in_console() {
    std::string opening = " VV         VV OOOO IIIII\n  VV       VV O    O  I\n   V       V  O    O  I\n    V     V   O    O  I\n     V   V    O    O  I\n      V V     O    O  I\n       V       OOOO IIIII\nCopyright (C) 2019 - 2020 Wojcieh Bia³ek\nThis program comes with ABSOLUTELY NO WARRANTY.\nThis is free software, and you are welcome to redistribute it.\nunder certain conditions for details read LICENSE.\n";
    std::cout << opening;
    pause_n_clear();

    std::string input;
    Bucket* a = new Bucket("a");
    Bucket* b = new Bucket("b");
    std::string* keywords = new std::string[17];
    std::string* descriptions = new std::string[15];
    get_from_file_to_array("keywords.voi",keywords,17,' ');
    get_from_file_to_array("descriptions.voi",descriptions,15,',');

    while(3!=5) {
        std::cout << "VOI" << std::endl;
        std::cin >> input;
        int inputId =- 1;
        for(unsigned int i = 0; i < 17; i++)
            if(input == keywords[i])
                inputId = i;

        convert_to_lower_case(input);

        if(inputId == 0)
            std::cout << "Witaj kmiocie!" << std::endl;
        else if( inputId == 1) {
            std::cout << "Podaj zawartosc pojemnika 'a'." << std::endl
                      << "a:";
            a->setValue(getInputInt());
        } else if (inputId == 2)
            std::cout << "Zawartosc pojemnika 'a':" << a->getValue() << std::endl;
        else if (inputId ==  3 || inputId ==  4) {
            std::cout << "Podaj wartosc,ktora zostanie dodana do pojemnika 'a':" << std::endl;
            a->setValue(a->getValue()+getInputInt());
        } else if (inputId == 5 || inputId == 6) {
            std::cout << "Podaj wartosc,ktora zostanie odjeta od pojemnika 'a':" << std::endl;
            a->setValue(a->getValue()-getInputInt());
        } else if (inputId == 7) {
            std::cout << "Podaj wartosc,przez ktora zostanie pomnozona zawartosc pojemnika 'a':" << std::endl;
            a->setValue(a->getValue()*getInputInt());
        } else if (inputId == 8) {
            int bucket;
            while(bucket == 0) {
                std::cout << "Podaj wartosc,przez ktora zostanie podzielona zawartosc pojemnika 'a':" << std::endl;
                std::cin >> bucket;
            }
            a->setValue(a->getValue()/bucket);
        } else if (inputId == 9)
            clear_window();
        else if (inputId == 10)
            return;
        else if (inputId == 11)
            nadpisz();
        else if (inputId == 12)
            dopisz();
        else if (inputId == 13)
            powiedz();
        else if (inputId == 14)
            otworz();
        else if (inputId == 15 || inputId == 16)
            print_help(keywords,descriptions);
        else
            std::cout << "Brak takiego slovka w slovnika" << std::endl;
    }
}
delete keywords;
delete descriptions;
delete a;
delete b;
}

int main() {
    show_interpreter_in_console();
    return 0;
}

//    Program is an interpreter of my own programming language called 'Voicieh' in short 'VPL'.
//    Copyright (C) 2019 - 2020 Wojcieh Białek
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

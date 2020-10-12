#include "voicieh.h"

void czysc() {
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
    std::cout << "Witaj kmiocie!" << std::endl << s << "?" << std::endl;
}

void otworz() {
    std::string fname = filename();
    open_file(fname);
    std::cout << std::endl << "KONIEC PLIKU" << std::endl;
}

void drukuj_pomoc(std::string* keywords,std::string* description) {
    std::cout << "Lista slovek kluczowych:" << std::endl;
    for(int i=0; i<22; i++)
        std::cout << "-";
    std::cout << std::endl;

    for (int i=0; i<15; i++) std::cout << "<" << keywords[i] << ">" << "::=" << description[i] << std::endl;
}

void interpret_given_keyword(std::string kword) {
    Bucket* a = new Bucket("a");
    std::string* keywords = new std::string[17];
    std::string* descriptions = new std::string[15];

    loadKeywords(keywords,descriptions);

    int inputId =- 1;
    for(unsigned int i = 0; i < 17; i++)
        if(kword == keywords[i])
            inputId = i;
    if(inputId == 0)  std::cout << "Witaj kmiocie!" << std::endl;
    else if( inputId == 1) {
        std::cout << "Podaj zawartosc pojemnika 'a'." << std::endl << "a:";
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
    } else if (inputId == 9) czysc();
    else if (inputId == 10) return;
    else if (inputId == 11) nadpisz();
    else if (inputId == 12) dopisz();
    else if (inputId == 13) powiedz();
    else if (inputId == 14) otworz();
    else if (inputId == 15 || inputId == 16) drukuj_pomoc(keywords,descriptions);
    else std::cout << "Brak takiego slovka w slovnika" << std::endl;

    delete a;
}

void spawn_interpreter_in_console() {
    std::string opening = " VV         VV OOOO IIIII\n  VV       VV O    O  I\n   V       V  O    O  I\n    V     V   O    O  I\n     V   V    O    O  I\n      V V     O    O  I\n       V       OOOO IIIII\nCopyright (C) 2019 - 2020 Wojcieh Białek\nThis program comes with ABSOLUTELY NO WARRANTY.\nThis is free software, and you are welcome to redistribute it.\nunder certain conditions for details read LICENSE.\n";
    std::cout << opening;
    pause_n_clear();

    std::string input;
    std::string* keywords = new std::string[17];
    std::string* descriptions = new std::string[15];

    while(3!=5) {
        std::cout << "VOI" << std::endl;
        std::cin >> input;
        convert_to_lower_case(input);

        interpret_given_keyword(input);
    }

    delete keywords;
    delete descriptions;
}

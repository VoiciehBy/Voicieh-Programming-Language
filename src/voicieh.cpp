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

std::string keywordInC(std::string keywordInVPL) {
    if(keywordInVPL == "publiczna")
        return "public";
    else if(keywordInVPL == "prywatna")
        return "private";
   /*
   else if(keywordInVPL == "logiczna")
        return "bool";
    */
    else if(keywordInVPL == "calkowita")
        return "int";
    else if(keywordInVPL == "klasa")
        return "class";
    else if(keywordInVPL == "jesli")
        return "if";
    else if(keywordInVPL == "jesliNie")
        return "else";
    else if(keywordInVPL == "funkcja")
        return "";
    else if(keywordInVPL == "zwroc")
        return "return";
    /*
    else if(keywordInVPL == "prawda")
        return "true";
    else if(keywordInVPL == "falsz")
        return "false";
        */
    else
        return keywordInVPL;
}

void tlumacz() {
    std::string fname = filename();
    char* fn = new char[fname.size()];
    for(unsigned int i = 0; i < fname.size(); i++) fn[i] = fname[i];

    std::ifstream voiSrc;
    std::ofstream cSrc;
    voiSrc.open(fn);
    cSrc.open("out.cpp");
    if(!voiSrc) {
        std::cout << "NIE MOZNA OTWORZYC PLIKU" << std::endl;
    } else {
        int lineNumber = 1;
        std::string line;
        while(std::getline(voiSrc, line,' ')) {
            std::cout << "line" << lineNumber << ":" <<keywordInC(line) << std::endl;
            if(line == "-1") break;
            else cSrc << keywordInC(line) << " ";
            lineNumber++;
        }
    }
    voiSrc.close();
    cSrc.close();
}

void drukuj_pomoc(std::vector<Keyword> keywords) {
    std::cout << "Lista slovek kluczowych:" << std::endl;
    for(int i=0; i<22; i++)
        std::cout << "-";
    std::cout << std::endl;

    for (unsigned int i=0; i<keywords.size(); i++) keywords[i].show();
}

void interpret_given_keyword_based_on_its_id(int keywordId,std::vector<Keyword> keywords) {
    Bucket* a = new Bucket("a");

    if(keywordId == 0)  std::cout << "Witaj kmiocie!" << std::endl;
    else if( keywordId == 1) {
        std::cout << "Podaj zawartosc pojemnika 'a'." << std::endl << "a:";
        a->setValue(getInputInt());
    } else if (keywordId == 2)
        std::cout << "Zawartosc pojemnika 'a':" << a->getValue() << std::endl;
    else if (keywordId ==  3 || keywordId ==  4) {
        std::cout << "Podaj wartosc,ktora zostanie dodana do pojemnika 'a':" << std::endl;
        a->setValue(a->getValue()+getInputInt());
    } else if (keywordId == 5 || keywordId == 6) {
        std::cout << "Podaj wartosc,ktora zostanie odjeta od pojemnika 'a':" << std::endl;
        a->setValue(a->getValue()-getInputInt());
    } else if (keywordId == 7) {
        std::cout << "Podaj wartosc,przez ktora zostanie pomnozona zawartosc pojemnika 'a':" << std::endl;
        a->setValue(a->getValue()*getInputInt());
    } else if (keywordId == 8) {
        int bucket;
        while(bucket == 0) {
            std::cout << "Podaj wartosc,przez ktora zostanie podzielona zawartosc pojemnika 'a':" << std::endl;
            std::cin >> bucket;
        }
        a->setValue(a->getValue()/bucket);
    } else if (keywordId == 9) czysc();
    else if (keywordId == 10) return;
    else if (keywordId == 11) nadpisz();
    else if (keywordId == 12) dopisz();
    else if (keywordId == 13) powiedz();
    else if (keywordId == 14) otworz();
    else if (keywordId == 15 || keywordId == 16) drukuj_pomoc(keywords);
    else if (keywordId == 17) tlumacz();
    else std::cout << "Brak takiego slovka w slovnika" << std::endl;

    delete a;
}

void spawn_interpreter_in_console() {
    std::string opening = " VV         VV OOOO IIIII\n  VV       VV O    O  I\n   V       V  O    O  I\n    V     V   O    O  I\n     V   V    O    O  I\n      V V     O    O  I\n       V       OOOO IIIII\nCopyright (C) 2019 - 2021 Wojcieh Białek\nThis program comes with ABSOLUTELY NO WARRANTY.\nThis is free software, and you are welcome to redistribute it.\nunder certain conditions for details read LICENSE.\n";
    std::cout << opening;
    pause_n_clear();

    std::string input;
    std::vector<Keyword> KeyWords;
    loadKeywords(KeyWords);

    while(3!=5) {
        std::cout << "VOI" << std::endl;
        std::cin >> input;
        convert_to_lower_case(input);
        interpret_given_keyword_based_on_its_id(keywordId(input,KeyWords),KeyWords);
    }
}

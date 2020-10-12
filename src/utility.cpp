#include "utility.h"

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

void get_from_file_to_array(std::string filename,std::string* array_a,int s_i_z_e,char delimiter) {
    std::string s;
    std::ifstream fptr (filename);
    for(int i = 0; i < s_i_z_e; i++) {
        getline(fptr,s,delimiter);
        array_a[i] = s;
    }
    fptr.close();
}

void loadKeywords(std::string* keywords, std::string* descriptions) {
    get_from_file_to_array("keywords.voi",keywords,17,' ');
    get_from_file_to_array("descriptions.voi",descriptions,15,',');
}

int getInputInt() {
    int i;
    std::cin >> i;
    return i;
}

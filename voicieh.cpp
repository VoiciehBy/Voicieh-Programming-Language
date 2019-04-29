#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
int main()
{

    cout << " VV         VV OOOO IIIII" << endl;
    cout << "  VV       VV O    O  I" << endl;
    cout << "   V       V  O    O  I" << endl;
    cout << "    V     V   O    O  I" << endl;
    cout << "     V   V    O    O  I" << endl;
    cout << "      V V     O    O  I" << endl;
    cout << "       V       OOOO IIIII" << endl;
    cout << "Copyright (C) 2019  Wojcieh Białek" << endl;
    cout << "This program comes with ABSOLUTELY NO WARRANTY." << endl;
    cout << "This is free software, and you are welcome to redistribute it." << endl;
    cout << "under certain conditions for details read LICENSE." << endl;
    system("CLS");
    int a=0,b;
    string input;
    string keywords[]
    {
        "siema","dawaj","muvta","dolejta","dodaj","siuraj","odejmij",
        "mnoga","dziel","czysc","kruci","nadpisz","dopisz","powiedz","pomoc"
    };
    string description[]
    {
        "wysvietla 'Witaj kmiocie!'","otviera pojemnik 'a'.",
        "vysvietla zawartoscz pojemnika 'a'.",
        "dodaje do pojemnika 'a'.","odejmuje od pojemnika 'a'.",
        "dodaje do pojemnika 'a'.","odejmuje od pojemnika 'a'.",
        "mnozy zawartoscz pojemnika 'a'.","dzieli zawartoscz pojemnika 'a'.",
        "czysci.","opuszcza interpretator.","nadpisuje slovo do pliku.","dopisuje slovo do pliku.",
        "vysvietla ciong znakuv podanych przez uszydkovnika."
    };
    while(3!=5)
    {
        cout << "VOI" << endl;
        cin >> input;
        if(input==keywords[0])
            cout << "Witaj kmiocie!" << endl;
        else if(input==keywords[1])
            cin >> a;
        else if(input==keywords[2])
            cout << a << endl;
        else if(input==keywords[3])
        {
            cin >> b;
            a+=b;
            b=0;
        }
        else if(input==keywords[4])
        {
            cin >> b;
            a-=b;
            b=0;
        }
        else if(input==keywords[5])
        {
            cin >> b;
            a+=b;
            b=0;
        }
        else if(input==keywords[6])
        {
            cin >> b;
            a-=b;
            b=0;
        }
        else if(input==keywords[7])
        {
            cin >> b;
            a*=b;
            b=0;
        }
        else if(input==keywords[8])
        {
            cin >> b;
            a/=b;
            b=0;
        }
        else if(input==keywords[9])
            system("CLS");
        else if(input==keywords[10])
            return 0;
        else if(input==keywords[11])
        {
            string s;
            ofstream file;
            file.open("plik.voi");
            file << "Plik zostal utworzony za pomocom jenzyka VOICIEH."<< "\n"<< "-------------------------------------------------";
            cin >> s;
            file << "\n" << s ;
            file.close();
        }
        else if(input==keywords[12])
        {
            string s;
            ofstream file;
            file.open("plik.voi",ios::app);
            cin >>s;
            file << "\n" << s ;
            file.close();
        }
        else if(input==keywords[13])
        {
            string s;
            cin >> s;
            cout << "Witaj kmiocie!" << endl;
            cout << s << "?" << endl;
        }
        else if(input==keywords[14])
        {
            cout << "Lista slovek kluczowych:" << endl;
            for(int i=0; i<22; i++)
                cout << "-";
            for (int i=0; i<14; i++)
            {
                cout << "<" << keywords[i] << ">" << "::=" << description[i] << endl;
            }
        }
        else
            cout << "Brak takiego slovka w slovnika" << endl;
    }
}
//    Program is an interpreter of my own programming language called 'Voicieh' in short 'VPL'.
//    Copyright (C) 2019  Wojcieh Białek
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

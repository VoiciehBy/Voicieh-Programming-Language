#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Keyword.h"

extern std::string filename();

extern void pause_n_clear();

extern void open_file(std::string &filename);

extern void convert_to_lower_case(std::string &s);

extern void get_from_file_to_array(std::string filename,std::string* array_a,int s_i_z_e,char delimiter);

extern void loadKeywords(std::vector<Keyword> KeyWords);

extern int getInputInt();

extern int keywordId(std::string input,std::vector<Keyword> keywords);
#endif // UTILITY_H

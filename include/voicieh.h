#ifndef VOICIEH_H
#define VOICIEH_H

#include <iostream>
#include <vector>
#include "Bucket.h"
#include "Keyword.h"
#include "utility.h"

extern void czysc();

extern void nadpisz();

extern void dopisz();

extern void powiedz();

extern void otworz();

extern void drukuj_pomoc(std::vector<Keyword> keywords);

extern void interpret_given_keyword(std::string kword);

extern void spawn_interpreter_in_console();
#endif // VOICIEH_H

//    Program is an interpreter of my own programming language called 'Voicieh Programming Language' in short 'VPL'.
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


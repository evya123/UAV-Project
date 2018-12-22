//
// Created by lidor115 on 12/20/18.
//
#include <vector>
#include <map>
#include <regex>
#include <iostream>
#include <string>
#include <list>
#include "Maps/Data.h"
#include "Maps/MapStringCommand.h"
#include "Commends/Command.h"
using namespace std;

#ifndef UAV_PROJECT_LEXER_H
#define UAV_PROJECT_LEXER_H

void LexerS(string line);

void FinalLexer(vector<string> &result, vector<string> &final);

void Parser(vector<string> &lexer);

void test();
#endif //UAV_PROJECT_LEXER_H

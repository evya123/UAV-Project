//
// Created by lidor115 on 12/20/18.
//
#include <vector>
#include <map>
#include <regex>
#include <iostream>
#include <string>
#include <list>

using namespace std;

#ifndef UAV_PROJECT_LEXER_H
#define UAV_PROJECT_LEXER_H

vector<string> LexerS(string line);
void FinalLexer(vector<string> &result, vector<string> &final);

#endif //UAV_PROJECT_LEXER_H

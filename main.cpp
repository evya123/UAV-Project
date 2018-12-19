//
// Created by evya on 12/14/18.
//

#include <stdio.h>
#include "ShuntingYard.h"
#include <string>
#include <iostream>

using namespace std;

int main(){
    string str = " ( -2 * - 3 ) + - 5  * - 5";
    ShuntingYard s(str);
    cout << s.evaluate () << "\n";


return 0;
}
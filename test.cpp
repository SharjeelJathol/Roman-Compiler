#include <iostream>
#include "parser.h"
#include <fstream>
using namespace std;

int main(){
    ifstream fin("grammar.txt");
    if (!fin) //if file not found
    {
        cout << "file not found" << endl;
    }
}
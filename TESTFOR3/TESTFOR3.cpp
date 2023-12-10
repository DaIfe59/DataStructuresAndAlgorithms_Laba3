#include <iostream>
#include <stdexcept>
#include <string>
#include "OneList.h"

using namespace std;

int main(int argc, char const* argv[])
{
    int k = 0;
    OneList<char> mass;
    Element<char> a;
    char c;
    printf("Vvedite stroku ");
    c = getchar();
    while (c != '\n') {
        mass.push_back(c);
        c = getchar();
        k++;
    }
   
    for (int i = 0; i < mass.size(); i++) {
        if (mass[i] == '+')
        {
            mass.insert(i+1, '+');
            mass.insert(i + 2, '+');
            i=i + 3;
        }
        
    }
    for (int i = 0; i < mass.size(); i++) {
        printf("%c", mass[i]);
    }
}

#include "dmmath.h"
#include "dmfix_win_utf8.h"
#include <iostream>
int main() {

    auto math =  dmmathGetModule();
    if(math)
    {
        std::cout << "hello world # " << math->Add(2000, 25) << std::endl;
    }

    return 0;
}
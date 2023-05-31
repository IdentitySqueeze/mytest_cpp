#include <iostream>
#include "myUtils.h"
//#include "primes.h"

int main(){
    Utils myUtils = Utils();
    int ofo = myUtils.mytest_ri(250,300);
    std::cout << myUtils.mytest_ri(250,300);
    char c;
    std::cin >> c;
    std::cout << "the value of '"<< c << "' is " << int(c) << '\n';
}
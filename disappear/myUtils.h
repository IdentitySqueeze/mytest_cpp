#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdarg.h>

#include <iostream>
#include <string>
#include <vector>

//#include "primes.h"
//#include "gjlib_arrays.h"

class Utils {
public:
    int max_prime;
    int primes_count; //100008
    int mytest_GetR(int x, int y);
    int mytest_ri(int x, int y);
    double mytest_rd(int x, int y, int z);
    int* mytest_rfr(int numWidth, int denomWidth);
    int mytest_is_prime(int x);
    void mytest_prime_factors(int x, std::vector<int> &ptr);
    long long mytest_lcm(int* set);
    int mytest_hcf(int* set);
    int mytest_otherhcf(int* set);
    int mytest_get_max_prime();
    std::string mytest_boolOut(int b, std::string rtn);
    void mytest_swap(int* x, int* y);
    int mytest_strlen_int(int x);
    int mytest_strlen_double(double x);
    int gjlib_sq(int x, int y);
    int gjlib_notSq(int x, int y);
    int gjlib_isInt(double x);
    int gjlib_isSquare(int x);
    int gjlib_int_choose(int* rtn);
    double gjlib_shrink(double x, int power);
    int gjlib_int_not(int notMe, int x, int y, int (*func)(int, int));
    double gjlib_significant_figures(double num, int figures);
    void mytest_to_super(std::string str, std::string &rtn);
    void mytest_to_sub(std::string str, std::string &rtn);
    void mytest_to_standard_form(double num, std::string &rtn);
private:

};


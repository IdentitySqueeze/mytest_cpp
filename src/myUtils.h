#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdarg.h>
#include <iostream>
#include <string>
#include <vector>

class Utils {
public:
    Utils(){std::cout << "workyt" << std::endl;}
    int max_prime;
    int primes_count; //100008
    void set_primes();
    int mytest_GetR(int x, int y);
    int mytest_ri(int x, int y);
    double mytest_rd(int x, int y, int z);
    std::vector<int> mytest_rfr(int numWidth, int denomWidth);
    bool mytest_is_prime(int x);
    void mytest_prime_factors(int x, std::vector<int> &ptr);
    long long mytest_lcm(std::vector<int> set);
    int mytest_hcf(std::vector<int> set);
    int mytest_get_max_prime();
    std::string mytest_boolOut(int b, std::string rtn);
    void mytest_swap(int* x, int* y);
    int mytest_strlen_int(int x);
    int mytest_strlen_double(double x);
    int gjlib_sq(int x, int y);
    int gjlib_notSq(int x, int y);
    bool gjlib_isInt(double x);
    bool gjlib_isSquare(int x);
    int gjlib_int_choose(std::vector<int> fromset);
    double gjlib_shrink(double x, int power);
    int gjlib_int_not(std::vector<int> notUs, int x, int y, int maxTries, int (Utils::*func)(int, int));
    double gjlib_significant_figures(double num, int figures);
    void mytest_to_super(std::string str, std::string &rtn);
    void mytest_to_sub(std::string str, std::string &rtn);
    void mytest_to_standard_form(double num, std::string &rtn);
private:

};


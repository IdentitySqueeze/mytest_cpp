#include <iostream>
#include "myUtils.h"
#include <algorithm>
#include <numeric>
#include <iterator>

void standard_form_output(double x);
void significant_figures_output(double x, int figures);
void not_output(std::vector<int> notUs, int x, int y, int maxTries, int (Utils::*func)(int, int));
void shrink_output(double d, int shrinkage);
void choose_output(std::vector<int> fromset);
void isInt_output(double x);
void isSquare_output(int x);
void notsq_output(int x, int y);
void sq_output(int x, int y);
void hcf_output(std::vector<int> inputset);
void lcm_output(std::vector<int> inputset);
void rfr_output(int num, int denom);
void prime_factors_output(int x);
void ri_output(int x, int y);
void rd_output(int x, int y, int z);
void is_prime_output(int x);

Utils myUtils{};

int main(){
    int test_ri                  = 1;
    int test_rd                  = 1;
    int test_rfr                 = 1;
    int test_is_prime            = 1;
    int test_prime_factors       = 1;
    int test_lcm                 = 1;
    int test_hcf                 = 1;
    int test_sq                  = 1;
    int test_notSq               = 1;
    int test_isSquare            = 1;
    int test_int_choose          = 1;
    int test_shrink              = 1;
    int test_int_not             = 1;
    int test_significant_figures = 1;
    int test_to_sub              = 1;
    int test_to_super            = 1;
    int test_to_standard_form    = 1;
    int test_isInt               = 1;

    using namespace std;

    myUtils.set_primes();

    if( test_is_prime ==1){
        is_prime_output(1);
        is_prime_output(-1);
        is_prime_output(0);
        is_prime_output(1);
        is_prime_output(2);
        is_prime_output(3);
        is_prime_output(4);
        is_prime_output(5);
        is_prime_output(6);
        is_prime_output(7);
        is_prime_output(8);
        is_prime_output(9);
        is_prime_output(10);
        is_prime_output(11);
        is_prime_output(12);
        is_prime_output(13);
        is_prime_output(14);
        is_prime_output(15);
        is_prime_output(16);
        is_prime_output(17);
        is_prime_output(18);
        is_prime_output(19);
        is_prime_output(20);
        is_prime_output(21);
        is_prime_output(22);
        is_prime_output(23);
        is_prime_output(31);
        is_prime_output(33);
        is_prime_output(37);
        is_prime_output(41);
        is_prime_output(43);
        is_prime_output(47);
        is_prime_output(51);
        is_prime_output(53);
        is_prime_output(57);
        is_prime_output(61);
        is_prime_output(63);
        is_prime_output(67);
        is_prime_output(71);
        is_prime_output(73);
        is_prime_output(77);
        is_prime_output(81);
        is_prime_output(83);
        is_prime_output(87);
        is_prime_output(91);
        is_prime_output(93);
        is_prime_output(97);
        is_prime_output(101);
        is_prime_output(103);
        is_prime_output(107);
        is_prime_output(151);
        is_prime_output(153);
        is_prime_output(157);
        is_prime_output(501);
        is_prime_output(503);
        is_prime_output(507);
        is_prime_output(1001);
        is_prime_output(1003);
        is_prime_output(1007);
        is_prime_output(10001);
        is_prime_output(10003);
        is_prime_output(10007);
        is_prime_output(100001);
        is_prime_output(100003);
        is_prime_output(100007);
        is_prime_output(1000001);
        is_prime_output(1000003);
        is_prime_output(1000007);
        is_prime_output(INT_MAX);
        is_prime_output(INT_MIN);
    }
    if( test_rfr==1){
        //rfr_output( 0, 0);
        //rfr_output( 0, 1 );
        //rfr_output(-1, 0 );
        //rfr_output( 0,-1 );
        //rfr_output( 1,-1 );
        //rfr_output(-1, 1 );
        rfr_output( 1, 1 );
        rfr_output( 1, 2 );
        rfr_output( 1, 3 );
        rfr_output( 1, 4 );
        rfr_output( 1, 5 );
        rfr_output( 2, 1 );
        rfr_output( 3, 1 );
        rfr_output( 4, 1 );
        rfr_output( 5, 1 );
        rfr_output( 2, 3 );
        rfr_output( 2, 4 );
        rfr_output( 2, 5 );
        rfr_output( 2, 6 );
        rfr_output( 3, 2 );
        rfr_output( 4, 2 );
        rfr_output( 5, 2 );
        rfr_output( 6, 2 );
        rfr_output( 5, 6 );
        rfr_output( 5, 7 );
        rfr_output( 5, 8 );
        rfr_output( 5, 9 );
        rfr_output( 6, 5 );
        rfr_output( 7, 5 );
        rfr_output( 8, 5 );
        rfr_output( 9, 5 );
        //rfr_output( 10, 5 );
        //rfr_output( 7, 10 );
        //rfr_output( -8, -5 );
        //rfr_output( INT_MAX, INT_MAX );
        //rfr_output( INT_MAX, INT_MIN );
        //rfr_output( INT_MIN, INT_MAX );
        //rfr_output( INT_MIN, INT_MIN );
    }
    if( test_ri==1){
        ri_output( 1, 1);
        ri_output(-1, 1);
        ri_output( 1,-1);
        ri_output(-1,-1);
        ri_output( 0, 0);
        ri_output( 1, 0);
        ri_output(-1, 0);
        ri_output( 0, 1);
        ri_output( 0,-1);
        ri_output( 5, 5);
        ri_output(-5, 5);
        ri_output( 5,-5);
        ri_output(-5,-5);
        ri_output( 5, 0 );
        ri_output(-5, 0 );
        ri_output( 0, 5);
        ri_output( 0,-5);
        ri_output( 6, 3);
        ri_output(-6, 3);
        ri_output( 6,-3);
        ri_output(-6,-3);
        ri_output( 3, 6);
        ri_output(-3, 6);
        ri_output( 3,-6);
        ri_output(-3,-6);
        ri_output(10,1);
        ri_output(100,10);
        ri_output(1000,100);
        ri_output(10000,1000);
        ri_output(100000,10000);
        ri_output(1000000,100000);
        ri_output(-10,10);
        ri_output(-100,100);
        ri_output(-1000,1000);
        ri_output(-10000,10000);
        ri_output(-100000,100000);
        ri_output(-1000000,1000000);
        ri_output(10,-10);
        ri_output(100,-100);
        ri_output(1000,-1000);
        ri_output(10000,-10000);
        ri_output(100000,-100000);
        ri_output(1000000,-1000000);
        ri_output(-1,-10);
        ri_output(-10,-100);
        ri_output(-100,-1000);
        ri_output(-1000,-10000);
        ri_output(-10000,-100000);
        ri_output(-100000,-1000000);
        ri_output(INT_MAX, INT_MIN);
        ri_output(INT_MIN, INT_MAX);
        ri_output(INT_MIN, INT_MAX);
        ri_output(INT_MIN, INT_MAX);
    }
    if( test_rd==1){
        rd_output( 1, 1, 0);
        rd_output(-1, 1, 0);
        rd_output( 1,-1, 0);
        rd_output(-1,-1, 0);
        rd_output( 0, 0, 0);
        rd_output( 1, 0, 0);
        rd_output(-1, 0, 0);
        rd_output( 0, 1, 0);
        rd_output( 0,-1, 0);
        rd_output( 5, 5, 0);
        rd_output(-5, 5, 0);
        rd_output( 5,-5, 0);
        rd_output(-5,-5, 0);
        rd_output( 5, 0, 0);
        rd_output(-5, 0, 0);
        rd_output( 0, 5, 0);
        rd_output( 0,-5, 0);
        rd_output( 6, 3, 0);
        rd_output(-6, 3, 0);
        rd_output( 6,-3, 0);
        rd_output(-6,-3, 0);
        rd_output( 3, 6, 0);
        rd_output(-3, 6, 0);
        rd_output( 3,-6, 0);
        rd_output(-3,-6, 0);
        rd_output( 1, 1, 1);
        rd_output(-1, 1, 1);
        rd_output( 1,-1, 1);
        rd_output(-1,-1, 1);
        rd_output( 0, 0, 1);
        rd_output( 1, 0, 1);
        rd_output(-1, 0, 1);
        rd_output( 0, 1, 1);
        rd_output( 0,-1, 1);
        rd_output( 5, 5, 1);
        rd_output(-5, 5, 1);
        rd_output( 5,-5, 1);
        rd_output(-5,-5, 1);
        rd_output( 5, 0, 1);
        rd_output(-5, 0, 1);
        rd_output( 0, 5, 1);
        rd_output( 0,-5, 1);
        rd_output( 6, 3, 1);
        rd_output(-6, 3, 1);
        rd_output( 6,-3, 1);
        rd_output(-6,-3, 1);
        rd_output( 3, 6, 1);
        rd_output(-3, 6, 1);
        rd_output( 3,-6, 1);
        rd_output(-3,-6, 1);
        rd_output( 1, 1, 4);
        rd_output(-1, 1, 4);
        rd_output( 1,-1, 4);
        rd_output(-1,-1, 4);
        rd_output( 0, 0, 4);
        rd_output( 1, 0, 4);
        rd_output(-1, 0, 4);
        rd_output( 0, 1, 4);
        rd_output( 0,-1, 4);
        rd_output( 5, 5, 4);
        rd_output(-5, 5, 4);
        rd_output( 5,-5, 4);
        rd_output(-5,-5, 4);
        rd_output( 5, 0, 4);
        rd_output(-5, 0, 4);
        rd_output( 0, 5, 4);
        rd_output( 0,-5, 4);
        rd_output( 6, 3, 4);
        rd_output(-6, 3, 4);
        rd_output( 6,-3, 4);
        rd_output(-6,-3, 4);
        rd_output( 3, 6, 4);
        rd_output(-3, 6, 4);
        rd_output( 3,-6, 4);
        rd_output(-3,-6, 4);
        rd_output( 1, 1, -4);
        rd_output(-1, 1, -4);
        rd_output( 1,-1, -4);
        rd_output(-1,-1, -4);
        rd_output( 0, 0, -4);
        rd_output( 1, 0, -4);
        rd_output(-1, 0, -4);
        rd_output( 0, 1, -4);
        rd_output( 0,-1, -4);
        rd_output( 5, 5, -4);
        rd_output(-5, 5, -4);
        rd_output( 5,-5, -4);
        rd_output(-5,-5, -4);
        rd_output( 5, 0, -4);
        rd_output(-5, 0, -4);
        rd_output( 0, 5, -4);
        rd_output( 0,-5, -4);
        rd_output( 6, 3, -4);
        rd_output(-6, 3, -4);
        rd_output( 6,-3, -4);
        rd_output(-6,-3, -4);
        rd_output( 3, 6, -4);
        rd_output(-3, 6, -4);
        rd_output( 3,-6, -4);
        rd_output(-3,-6, -4);
        rd_output(10,1,0);
        rd_output(100,10,0);
        rd_output(1000,100,0);
        rd_output(10000,1000,0);
        rd_output(100000,10000,0);
        rd_output(1000000,100000,0);
        rd_output(-10,10,0);
        rd_output(-100,100,0);
        rd_output(-1000,1000,0);
        rd_output(-10000,10000,0);
        rd_output(-100000,100000,0);
        rd_output(-1000000,1000000,0);
        rd_output(10,-10,0);
        rd_output(100,-100,0);
        rd_output(1000,-1000,0);
        rd_output(10000,-10000,0);
        rd_output(100000,-100000,0);
        rd_output(1000000,-1000000,0);
        rd_output(-1,-10,0);
        rd_output(-10,-100,0);
        rd_output(-100,-1000,0);
        rd_output(-1000,-10000,0);
        rd_output(-10000,-100000,0);
        rd_output(-100000,-1000000,0);
        rd_output(INT_MAX, INT_MIN, 0);
        rd_output(INT_MIN, INT_MAX, 0);
        rd_output(10,1,1);
        rd_output(100,10,1);
        rd_output(1000,100,1);
        rd_output(10000,1000,1);
        rd_output(100000,10000,1);
        rd_output(1000000,100000,1);
        rd_output(-10,10,1);
        rd_output(-100,100,1);
        rd_output(-1000,1000,1);
        rd_output(-10000,10000,1);
        rd_output(-100000,100000,1);
        rd_output(-1000000,1000000,1);
        rd_output(10,-10,1);
        rd_output(100,-100,1);
        rd_output(1000,-1000,1);
        rd_output(10000,-10000,1);
        rd_output(100000,-100000,1);
        rd_output(1000000,-1000000,1);
        rd_output(-1,-10,1);
        rd_output(-10,-100,1);
        rd_output(-100,-1000,1);
        rd_output(-1000,-10000,1);
        rd_output(-10000,-100000,1);
        rd_output(-100000,-1000000,1);
        rd_output(INT_MAX, INT_MIN, 1);
        rd_output(INT_MIN, INT_MAX, 1);
        rd_output(10,1,4);
        rd_output(100,10,4);
        rd_output(1000,100,4);
        rd_output(10000,1000,4);
        rd_output(100000,10000,4);
        rd_output(1000000,100000,4);
        rd_output(-10,10,4);
        rd_output(-100,100,4);
        rd_output(-1000,1000,4);
        rd_output(-10000,10000,4);
        rd_output(-100000,100000,4);
        rd_output(-1000000,1000000,4);
        rd_output(10,-10,4);
        rd_output(100,-100,4);
        rd_output(1000,-1000,4);
        rd_output(10000,-10000,4);
        rd_output(100000,-100000,4);
        rd_output(1000000,-1000000,4);
        rd_output(-1,-10,4);
        rd_output(-10,-100,4);
        rd_output(-100,-1000,4);
        rd_output(-1000,-10000,4);
        rd_output(-10000,-100000,4);
        rd_output(-100000,-1000000,4);
        rd_output(INT_MAX, INT_MIN, -1);
        rd_output(INT_MIN, INT_MAX, -1);
    }
    if( test_prime_factors==1){
        prime_factors_output(2);
        prime_factors_output(-1);
        prime_factors_output(0);
        prime_factors_output(1);
        prime_factors_output(2);
        prime_factors_output(3);
        prime_factors_output(4);
        prime_factors_output(5);
        prime_factors_output(6);
        prime_factors_output(7);
        prime_factors_output(8);
        prime_factors_output(9);
        prime_factors_output(10);
        prime_factors_output(11);
        prime_factors_output(12);
        prime_factors_output(13);
        prime_factors_output(14);
        prime_factors_output(15);
        prime_factors_output(16);
        prime_factors_output(17);
        prime_factors_output(18);
        prime_factors_output(19);
        prime_factors_output(20);
        prime_factors_output(30);
        prime_factors_output(40);
        prime_factors_output(50);
        prime_factors_output(60);
        prime_factors_output(70);
        prime_factors_output(80);
        prime_factors_output(90);
        prime_factors_output(100);
        prime_factors_output(4);
        prime_factors_output(8);
        prime_factors_output(16);
        prime_factors_output(32);
        prime_factors_output(64);
        prime_factors_output(128);
        prime_factors_output(512);
        prime_factors_output(1024);
        prime_factors_output(2048);
        prime_factors_output(4096);
        prime_factors_output(8192);
        prime_factors_output(16384);
        prime_factors_output(32768);
        prime_factors_output(65536);
        prime_factors_output(131072);
        prime_factors_output(262144);
        prime_factors_output(524288);
        //prime_factors_output(1048577);
        //prime_factors_output(1200000);
    }
    if( test_lcm==1){
        lcm_output(vector<int>{ 2, 3 });
        lcm_output(vector<int>{ 1, 2 });
        lcm_output(vector<int>{ 0 });
        lcm_output(vector<int>{ 1 });
        lcm_output(vector<int>{ 0 });
        lcm_output(vector<int>{ 1 });
        lcm_output(vector<int>{ 1,  2 });
        lcm_output(vector<int>{ 1,  2,  3 });
        lcm_output(vector<int>{ 1,  3,  2 });
        lcm_output(vector<int>{ 3,  1,  2 });
        lcm_output(vector<int>{ 3,  2,  1 });
        lcm_output(vector<int>{ 2,  3,  4 });
        lcm_output(vector<int>{ 2,  3,  4 });
        lcm_output(vector<int>{ 2,  3,  4, 5 });
        lcm_output(vector<int>{ 2,  3,  7 });
        lcm_output(vector<int>{ 2,  4,  8 });
        lcm_output(vector<int>{ 3,  6,  9 });
        lcm_output(vector<int>{ 4, 16, 64 });
        lcm_output(vector<int>{ 7, 49,349 });
        // lcm_output(vector<int>{3, 64, 2048, 1024});
        // lcm_output(vector<int>{3, 2048, 64, 1024});
        // lcm_output(vector<int>{3, 1024, 2048, 64});
        // lcm_output(vector<int>{3, 2048, 1024, 64});
        // lcm_output(vector<int>{2, 1000000, 1000});
        // lcm_output(vector<int>{3, 1000000, 100, 11});
        // lcm_output(vector<int>{2, INT_MAX, INT_MIN});
    }
    if( test_hcf==1){
        hcf_output(vector<int>{  5, 15, 30 });
        hcf_output(vector<int>{  5, 30, 15 });
        hcf_output(vector<int>{  5, 15, 30 });
        hcf_output(vector<int>{  5, 30, 15 });
        hcf_output(vector<int>{ 15,  5, 30 });
        hcf_output(vector<int>{ 15, 30,  5 });
        hcf_output(vector<int>{ 30,  5, 15 });
        hcf_output(vector<int>{ 30, 15,  5 });
        hcf_output(vector<int>{ 21, 35,  7 });
        hcf_output(vector<int>{ 12, 24, 48 });
        hcf_output(vector<int>{  9, 27,126 });
        hcf_output(vector<int>{ INT_MIN+1, INT_MIN+1, INT_MAX-1, INT_MIN+1});
        hcf_output(vector<int>{  -5, 15, 30 });
        hcf_output(vector<int>{   5,-15, 30 });
        hcf_output(vector<int>{   5, 15,-30 });
        hcf_output(vector<int>{  -5, 30, 15 });
        hcf_output(vector<int>{ -15,  5, 30 });
        hcf_output(vector<int>{ -15, 30,  5 });
        hcf_output(vector<int>{ -30,  5, 15 });
        hcf_output(vector<int>{ -30, 15,  5 });
        hcf_output(vector<int>{ -21, 35,  7 });
        hcf_output(vector<int>{ -12, 24, 48 });
        hcf_output(vector<int>{  -9, 27,126 });
        hcf_output(vector<int>{ INT_MAX-1, INT_MIN+1});
    }
    if( test_sq == 1){
        //sq_output( 0,-1);
        //sq_output(-2,-2);
        sq_output( 0, 0);
        sq_output( 0, 1);
        sq_output( 1, 0);
        sq_output(-1, 0);
        sq_output(-1, 1);
        sq_output( 1, 1);
        sq_output(-2, 2);
        sq_output( 2, 2);
        sq_output( 1, 2);
        sq_output( 1, 3);
        sq_output( 2, 5);
        sq_output( 5,10);
        sq_output( 1, sqrt(INT_MAX));
        //sq_output( INT_MIN, sqrt(INT_MAX));
    }
    if( test_notSq == 1){
        notsq_output(1,1);
        notsq_output(0,  1);
        notsq_output(1,  0);
        notsq_output(1,  0);
        notsq_output(1,  1);
        notsq_output(1,  1);
        notsq_output(2,  2);
        notsq_output(2,  2);
        notsq_output(1,  2);
        notsq_output(1,  3);
        notsq_output(2,  5);
        notsq_output(5, 10);
        notsq_output(5,100);
        notsq_output(5,100);
        notsq_output(5,100);
        notsq_output(-50,100);
        notsq_output(-50,100);
        notsq_output(-50,-100);
        notsq_output(-50,-100);
        notsq_output(5,100);
        notsq_output(5,100);
        notsq_output(5,100);
        notsq_output(5,100);
        notsq_output(5,100);
        notsq_output(5,100);
        notsq_output(5,100);
        notsq_output(1, sqrt(INT_MAX));
    }
    if( test_isSquare == 1){
        isSquare_output(-1);
        isSquare_output(0);
        isSquare_output(1);
        isSquare_output(2);
        isSquare_output(3);
        isSquare_output(4);
        isSquare_output(-4);
        isSquare_output(5);
        isSquare_output(6);
        isSquare_output(7);
        isSquare_output(8);
        isSquare_output(9);
        isSquare_output(-9);
        isSquare_output(10);
        isSquare_output(-10);
        isSquare_output(11);
        isSquare_output(12);
        isSquare_output(13);
        isSquare_output(14);
        isSquare_output(15);
        isSquare_output(16);
        isSquare_output(17);
        isSquare_output(18);
        isSquare_output(19);
        isSquare_output(20);
        isSquare_output(25);
        isSquare_output(26);
        isSquare_output(35);
        isSquare_output(36);
        isSquare_output(37);
        isSquare_output(48);
        isSquare_output(49);
        isSquare_output(50);
        isSquare_output(51);
        isSquare_output(53);
        isSquare_output(64);
        isSquare_output(65);
        isSquare_output(168);
        isSquare_output(169);
        isSquare_output(170);
        isSquare_output(INT_MAX);
        isSquare_output(INT_MIN);
    }
    if( test_isInt == 1){
        isInt_output(-1.0);
        isInt_output(-1.1);
        isInt_output(-1);
        isInt_output(0);
        isInt_output(0.0);
        isInt_output(1);
        isInt_output(1.1);
        isInt_output(2);
        isInt_output(2.0);
        isInt_output(2.2);
        isInt_output(10);
        isInt_output(10.1);
        isInt_output(10.01);
        isInt_output(10.001);
        isInt_output(10.0001);
        isInt_output(10.00001);
        isInt_output(10.000001);
        isInt_output(10.0000001);
        isInt_output(10.00000001);
        isInt_output(10.000000001);
        isInt_output(10.0000000001);
        isInt_output(10.00000000001);
        isInt_output(10.000000000001);
        isInt_output(10.0000000000001);
        isInt_output(10.00000000000001);
        isInt_output(10.000000000000001);
        isInt_output(INT_MAX);
        isInt_output(INT_MAX - 0.1);
        isInt_output(INT_MIN);
        isInt_output(INT_MIN + 0.1);
    }
    if( test_int_choose == 1){
        choose_output( vector<int>{1, 1});
        choose_output( vector<int>{2, -1, -1});
        choose_output( vector<int>{2,  1, -1});
        choose_output( vector<int>{2, -1,  1});
        choose_output( vector<int>{2,  1,  1});
        choose_output( vector<int>{2,  0,  0});
        choose_output( vector<int>{2,  0,  1});
        choose_output( vector<int>{2,  0, -1});
        choose_output( vector<int>{2,  1,  0});
        choose_output( vector<int>{2, -1,  0});
        choose_output( vector<int>{2,  INT_MIN, INT_MIN});
        choose_output( vector<int>{2,  INT_MAX, INT_MAX});
        choose_output( vector<int>{2,  INT_MIN, INT_MAX});
        choose_output( vector<int>{2,  INT_MAX, INT_MIN});
        choose_output( vector<int>{5, 10, 11, 12, 13, 14 });
        choose_output( vector<int>{5, 100, 200, 300, 400, 500 });
        choose_output( vector<int>{5, INT_MIN, -1, 0, 1, INT_MAX });
        //choose_output( vector<double>{5, 10, 10.1, 10.2, 10.3, 10.4 });
        choose_output( vector<int>{15, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 8192, 16384, 32768, 65536  });
    }
    if( test_shrink == 1){
        shrink_output( 0,  0);
        shrink_output(-1, -1 );
        shrink_output(-1,  1 );
        shrink_output( 1, -1);
        shrink_output( 1,  1);
        shrink_output( 0, -1 );
        shrink_output( 0,  1 );
        shrink_output(-1,  0 );
        shrink_output( 1,  0 );
        shrink_output( 0.55,  0);
        shrink_output(-1.55, -1 );
        shrink_output(-1.55,  1 );
        shrink_output( 1.55, -1);
        shrink_output( 1.55,  1);
        shrink_output( 0.55, -1 );
        shrink_output( 0.55,  1 );
        shrink_output(-1.55,  0 );
        shrink_output( 1.55,  0 );
        shrink_output( 1.12345, 1  );
        shrink_output( 1.12345, -1  );
        shrink_output( 2.12345, 2  );
        shrink_output( 2.12345, -2  );
        shrink_output( 3.12345, 3  );
        shrink_output( 3.12345, -3  );
        shrink_output( 4.12345, 4  );
        shrink_output( 4.12345, -4  );
        shrink_output( 5.12345, 5  );
        shrink_output( 5.12345, -5  );
        shrink_output( 11.12345, 0  );
        shrink_output( 3.1415927, 5  );
        shrink_output( (double)INT_MAX, 7 );
        shrink_output( (double)INT_MIN, 7 );
    }
    if( test_int_not ==1){
        not_output(vector<int>{5}, 4,6, 250, &Utils::mytest_ri);
        not_output(vector<int>{5}, 4,6, 250, &Utils::mytest_ri);
        not_output(vector<int>{5}, 4,6, 250, &Utils::mytest_ri);
        not_output(vector<int>{0},-1,1, 250, &Utils::mytest_ri);
        not_output(vector<int>{5}, 4,6, 250, &Utils::mytest_ri);
        not_output(vector<int>{5}, 4,6, 250, &Utils::mytest_ri);
        not_output(vector<int>{5}, 4,6, 250, &Utils::mytest_ri);
        not_output(vector<int>{5}, 4,6, 250, &Utils::mytest_ri);
        not_output(vector<int>{5}, 4,6, 250, &Utils::mytest_ri);
        not_output(vector<int>{5}, 4,6, 250, &Utils::mytest_ri);
        not_output(vector<int>{5}, 4,6, 250, &Utils::mytest_ri);
        not_output(vector<int>{5}, 4,6, 250, &Utils::mytest_ri);
        not_output(vector<int>{5}, 4,6, 250, &Utils::mytest_ri);
        not_output(vector<int>{5}, 4,6, 250, &Utils::mytest_ri);
        not_output(vector<int>{5}, 4,6, 250, &Utils::mytest_ri);
        not_output(vector<int>{5}, 4,6, 250, &Utils::mytest_ri);
        not_output(vector<int>{5}, 4,6, 250, &Utils::mytest_ri);
    }
    if( test_significant_figures ==1){
        significant_figures_output( 0.0, 1);
        significant_figures_output( 1.0, 1);
        significant_figures_output(1.1,1);
        significant_figures_output(11.0,1);
        significant_figures_output(111.0,2);
        significant_figures_output(1111.0,3);
        significant_figures_output(11.1,1);
        significant_figures_output(11.11,2);
        significant_figures_output(11.111,3);
        significant_figures_output(11.1111,4);
        significant_figures_output(0.1,1);
        significant_figures_output(0.01,1);
        significant_figures_output(0.001,1);
        significant_figures_output(0.0001,1);
        significant_figures_output(-1.0, 1);
        significant_figures_output(-1.1,1);
        significant_figures_output(-11.0,1);
        significant_figures_output(-111.0,2);
        significant_figures_output(-1111.0,3);
        significant_figures_output(-11.1,1);
        significant_figures_output(-11.11,2);
        significant_figures_output(-11.111,3);
        significant_figures_output(-11.1111,4);
        significant_figures_output(-0.1,1);
        significant_figures_output(-0.01,1);
        significant_figures_output(-0.001,1);
        significant_figures_output(-0.0001,1);
        significant_figures_output(12345.12345,1);
        significant_figures_output(12345.12345,2);
        significant_figures_output(12345.12345,3);
        significant_figures_output(12345.12345,4);
        significant_figures_output(12345.12345,5);
        significant_figures_output(12345.12345,6);
        significant_figures_output(12345.12345,7);
        significant_figures_output(12345.12345,8);
        significant_figures_output(12345.12345,9);
        significant_figures_output(12345.12345,10);
        significant_figures_output(123.123,8);
        significant_figures_output(-12345.12345,1);
        significant_figures_output(-12345.12345,2);
        significant_figures_output(-12345.12345,3);
        significant_figures_output(-12345.12345,4);
        significant_figures_output(-12345.12345,5);
        significant_figures_output(-12345.12345,6);
        significant_figures_output(-12345.12345,7);
        significant_figures_output(-12345.12345,8);
        significant_figures_output(-12345.12345,9);
        significant_figures_output(-12345.12345,10);
        significant_figures_output(-123.123,8);
        significant_figures_output((double)INT_MAX, 7);
        significant_figures_output((double)INT_MIN,7);
    }
    if( test_to_sub==1){
        std::string strInput = "\nabcdefghijklmnopqrstuvwxyzABCDEFDGHIJKLMNOPQRSTUVWXYZ1234567890()=\\/*+-";
        std::string rslt;
        myUtils.mytest_to_sub(strInput, rslt);
        std::cout << "to_sub: " << std::endl << strInput << endl << rslt << endl;
    }
    if( test_to_super==1){
        std::string strInput = "\nabcdefghijklmnopqrstuvwxyzABCDEFDGHIJKLMNOPQRSTUVWXYZ1234567890()=\\/*+-";
        std::string rslt;
        myUtils.mytest_to_super(strInput, rslt);
        std::cout << strInput << endl << rslt << endl;
    }
    if( test_to_standard_form==1){
        standard_form_output(111.11);
        standard_form_output(0.11111);
        standard_form_output(-0.11111);
        standard_form_output(0);
        standard_form_output(1);
        standard_form_output(-1);
        standard_form_output(0.00012345);
        standard_form_output(0.0012345);
        standard_form_output(0.012345);
        standard_form_output(0.12345);
        standard_form_output(1.2345);
        standard_form_output(12.345);
        standard_form_output(123.45);
        standard_form_output(1234.5);
        standard_form_output(12345.0);
        standard_form_output(-111.11);
        standard_form_output(-0.11111);
        standard_form_output(-0.00012345);
        standard_form_output(-0.0012345);
        standard_form_output(-0.012345);
        standard_form_output(-0.12345);
        standard_form_output(-1.2345);
        standard_form_output(-12.345);
        standard_form_output(-123.45);
        standard_form_output(-1234.5);
        standard_form_output(-12345.0);
        standard_form_output((double)INT_MAX);
        standard_form_output((double)INT_MIN);
        standard_form_output(9.9);
        standard_form_output(-9.9);
        standard_form_output(10);
        standard_form_output(10.0);
        standard_form_output(-10);
        standard_form_output(-10.0);
        standard_form_output(10.01);
        standard_form_output(-10.01);
        standard_form_output(11);
        standard_form_output(11.0);
        standard_form_output(-11);
        standard_form_output(-11.0);
        standard_form_output(11.01);
        standard_form_output(-11.01);
        standard_form_output(0.9);
        standard_form_output(0.09);
        standard_form_output(0.009);
        standard_form_output(0.0009);
        standard_form_output(0.00009);
        standard_form_output(-0.9);
        standard_form_output(-0.09);
        standard_form_output(-0.009);
        standard_form_output(-0.0009);
        standard_form_output(-0.00009);
        standard_form_output(5);
        standard_form_output(55);
        standard_form_output(555);
        standard_form_output(5555);
        standard_form_output(55555);
        standard_form_output(555555);
        standard_form_output(5555555);
        standard_form_output(55555555);
        standard_form_output(555555555);
        standard_form_output(-5);
        standard_form_output(-55);
        standard_form_output(-555);
        standard_form_output(-5555);
        standard_form_output(-55555);
        standard_form_output(-555555);
        standard_form_output(-5555555);
        standard_form_output(-55555555);
        standard_form_output(-555555555);
        standard_form_output(0.5);
        standard_form_output(0.55);
        standard_form_output(0.555);
        standard_form_output(0.5555);
        standard_form_output(0.55555);
        standard_form_output(0.555555);
        standard_form_output(0.5555555);
        standard_form_output(0.55555556);
        standard_form_output(0.555555555);
        standard_form_output(-0.5);
        standard_form_output(-0.55);
        standard_form_output(-0.555);
        standard_form_output(-0.5555);
        standard_form_output(-0.55555);
        standard_form_output(-0.555555);
        standard_form_output(-0.5555555);
        standard_form_output(-0.55555555);
        standard_form_output(-0.555555555);
    }
}

void standard_form_output(double x){
    std::string rslt;
    myUtils.mytest_to_standard_form(x, rslt);
    std::cout << "mytest_to_standard_form(" << std::defaultfloat << x << ") = " << rslt << std::endl;
}
void significant_figures_output(double x, int figures){
    using namespace std;
    cout.precision(10);
    double rslt = myUtils.gjlib_significant_figures(x, figures);
    cout << "significant_figures(" << x << "," << figures << ") =" << fixed << rslt << endl;
}
void not_output(std::vector<int> notUs, int x, int y, int maxTries, int (Utils::*func)(int, int)){
    using namespace std;
    int rslt = myUtils.gjlib_int_not(notUs, x, y, maxTries, func);
    cout << "gjlib_int_not( [ ";
    copy(begin(notUs), end(notUs), ostream_iterator<int>(cout, " "));
    cout << "], " << x << ", " << y << ", " << maxTries << ", myTest_ri = " << rslt << endl;
}
void shrink_output(double d, int shrinkage){
    double rslt = myUtils.gjlib_shrink(d, shrinkage);
    std::cout << "gjlib_shrink(" << d << ", " << shrinkage << ") = " << rslt << std::endl;
}
void choose_output(std::vector<int> fromset){
    using namespace std;
    int rslt = myUtils.gjlib_int_choose(fromset);
    cout << "gjlib_choose( ";
    copy(begin(fromset), end(fromset), ostream_iterator<int>(cout, ","));
    cout << " ) = " << rslt << endl;
}
void isInt_output(double x){
    bool rslt = myUtils.gjlib_isInt(x);
    std::cout.precision(15);
    std::cout << std::boolalpha << "gjlib_isInt(" << x << ") = " << std::fixed << rslt << std::endl;
}
void isSquare_output(int x){
    bool rslt = myUtils.gjlib_isSquare(x);
    std::cout << std::boolalpha << "gjlib_isSq(" << x << ") = " << rslt << std::endl;
}
void notsq_output(int x, int y){
    int rslt = myUtils.gjlib_notSq(x,y);
    std::cout << "gjlib_notSq(" << x << "," << y << ") = " << rslt << std::endl;
}
void sq_output(int x, int y){
    int rslt = myUtils.gjlib_sq(x,y);
    std::cout << "mytest_sq(" << x << "," << y << ") = " << rslt << std::endl;
}
void hcf_output(std::vector<int> inputset){
    using namespace std;
    long long rslt = myUtils.mytest_hcf(inputset);
    cout << "mytest_hcf( [ ";
    copy(begin(inputset), end(inputset), ostream_iterator<int>(cout, " "));
    cout << "] ) = " << rslt << endl;
}
void lcm_output(std::vector<int> inputset){
    using namespace std;
    long long rslt = myUtils.mytest_lcm(inputset);
    cout << "mytest_lcm( [ ";
    copy(begin(inputset), end(inputset), ostream_iterator<int>(cout, " "));
    cout << "] ) = " << rslt << endl;
}
void rfr_output(int num, int denom){
    using namespace std;
    std::vector<int> fr= myUtils.mytest_rfr(num,denom);
    cout << "mytest_rfr(" << num << "," << denom << ") = ";
    copy(begin(fr), end(fr), ostream_iterator<int>(std::cout, ","));
    cout << endl;
}
void prime_factors_output(int x){
    using namespace std;
    std::vector<int> factors;
    myUtils.mytest_prime_factors(x, factors);
    cout << "mytest_prime_factors(" << x << ") = ";
    copy(begin(factors), end(factors), ostream_iterator<int>(std::cout, ","));
    cout << endl;
}
void ri_output(int x, int y){
    using namespace std;
    int rslt = myUtils.mytest_ri(x,y);
    cout << "mytest_ri(" << x << "," << y <<") = " << rslt << endl;
}
void rd_output(int x, int y, int z){
    using namespace std;
    cout.precision(z);
    double rslt = myUtils.mytest_rd(x,y,z);
    cout << "mytest_rd(" << x << "," << y << "," << z <<") = " << fixed << rslt << endl;
}
void is_prime_output(int x){
    std::cout << "is_prime(" << x << ") = " << std::boolalpha << myUtils.mytest_is_prime(x) << std::endl;
}


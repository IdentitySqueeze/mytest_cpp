#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdarg.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

#include "primes.h"

// static int mytest_riWithNonZero(int x, int y, int nonZero);
// static int* mytest_rfrWithProper(int numWidth, int denomWidth, int proper);
// static int mytest_widthDouble(double x);
// static int mytest_widthInt(int x);

using namespace std;

class Utils {
public:
    Utils();
    int max_prime;
    int primes_count;
    void set_primes();
    int mytest_GetR(int x, int y);
    int mytest_ri(int x, int y);
    double mytest_rd(int x, int y, int z);
    std::vector<int> mytest_rfr(int numWidth, int denomWidth);
    bool mytest_is_prime(int x);
    void mytest_prime_factors(int x, vector<int> &ptr);
    long long mytest_lcm(vector<int> set);
    int mytest_hcf(vector<int> set);
    int mytest_get_max_prime();
    string mytest_boolOut(int b, string rtn);
    void mytest_swap(int* x, int* y);
    int mytest_strlen_int(int x);
    int mytest_strlen_double(double x);
    int gjlib_sq(int x, int y);
    int gjlib_notSq(int x, int y);
    bool gjlib_isInt(double x);
    bool gjlib_isSquare(int x);
    int gjlib_int_choose(vector<int> fromset);
    double gjlib_shrink(double x, int power);
    int gjlib_int_not(std::vector<int> notUs, int x, int y, int maxTries, int (Utils::*func)(int, int));
    double gjlib_significant_figures(double num, int figures);
    void mytest_to_super(string str, string &rtn);
    void mytest_to_sub(string str, string &rtn);
    void mytest_to_standard_form(double num, string &rtn);
private:
};

void Utils::set_primes(){
    max_prime = prime_numbers.back();
    primes_count = prime_numbers.size();
}

void Utils::mytest_swap(int* x, int* y) {
    int tmp = *y;
    *y = *x;
    *x = tmp;
}

int Utils::mytest_ri(int x, int y) {
    int nonZero = 1;
    if (x == y)
        return x;

    int rtn = 0;

    int negBit = 0;
    int posBit = 0;

    if (x < 0 && y < 0) {
        // negative range
        x = abs(x);
        y = abs(y);
        if (x > y)
            mytest_swap(&x, &y);
        while (nonZero == 1 && rtn == 0)
            rtn = mytest_GetR(x, y) * -1;

    }
    else if (x < 0) {
        if (y == 0) {  // range is negative
            while (nonZero == 1 && rtn == 0)
                rtn = -1 * mytest_GetR(0, abs(x));
        }
        else {
            // range crosses the zero
            while (nonZero == 1 && rtn == 0) {
                negBit = mytest_GetR(0, abs(x)) * -1;
                posBit = mytest_GetR(0, y);
                rtn = (negBit + posBit);
            }
        }
    }
    else if (y < 0) {
        if (x == 0) {   // range is negative
            while (nonZero == 1 && rtn == 0)
                rtn = -1 * mytest_GetR(0, abs(y));
        }
        else {
            // range crosses the zero
            while (nonZero == 1 && rtn == 0) {
                negBit = mytest_GetR(0, abs(y)) * -1;
                posBit = mytest_GetR(0, x);
                rtn = (negBit + posBit);
            }
        }
    }
    else {
        // positive range
        if (x > y)
            mytest_swap(&x, &y);
        int nudge = 0;
        if (x == 0)
            nudge++;
        if (y == 0)
            nudge++;
        while (nonZero == 1 && rtn == 0)
            rtn = mytest_GetR(x + nudge, y + nudge) - nudge;
    }
    return rtn;
}

int Utils::mytest_GetR(int x, int y) {
    return rand() % (y - x + 1) + x;
}

double Utils::mytest_rd(int x, int y, int z) {
    if (z == 0)
        return (double)mytest_ri(x, y); //swap etc covered

    //if(z==1)
    //    return (double)mytest_ri(x,y) + (double)mytest_ri(1,9)/10.0;

    if (x == INT_MAX) {
        x--;
    }
    else if (x == INT_MIN) {
        x++;
    }
    if (y == INT_MAX) {
        y--;
    }
    else if (y == INT_MIN) {
        y++;
    }

    z = abs(z);
    double dec = (double)rand() / RAND_MAX;
    while ((int)(round(dec * pow(10, z) - .5)) % 10 == 0 || dec == 0) //make right-most decimal non-zero
        dec = (double)rand() / RAND_MAX;

    double power = pow(10, z);
    if (x == y) {
        if (x < 0)
            dec = 1 - dec;
        return ((int)((x + dec) * power)) / power;
    }

    double rtn = 0;
    int nonZero = 1;
    int negBit = 0;
    int posBit = 0;

    if (x < 0 && y < 0) {
        // range negative
        x = abs(x);
        y = abs(y);
        if (x > y)
            mytest_swap(&x, &y);
        if (y - x == 1) {
            rtn = (x + dec) * -1;
        }
        else {
            while (nonZero == 1 && rtn == 0)
                rtn = ((double)mytest_GetR(x, (y - 1)) + dec) * -1;
        }

    }
    else if (x < 0) {
        if (y - x == 1) { // implication: -1, 0
            rtn = dec * -1;
        }
        else if (y == 0) {   // range is negative
            rtn = -1.0 * ((double)mytest_GetR(0, abs(x)) + dec);
        }
        else {
            // range crosses the zero
            while (nonZero == 1 && rtn == 0) {
                negBit = mytest_GetR(0, abs(x)) * -1;
                posBit = mytest_GetR(0, y - 1);
                rtn = (double)(negBit + posBit) + dec;
            }
        }

    }
    else if (y < 0) {
        if (x - y == 1) { // implication: 0, -1
            rtn = dec * -1;
        }
        else if (x == 0) {   // range is negative
            rtn = -1.0 * ((double)mytest_GetR(0, abs(y)) + dec);
        }
        else {
            // range crosses the zero
            while (nonZero == 1 && rtn == 0) {
                negBit = mytest_GetR(0, abs(y)) * -1;
                posBit = mytest_GetR(0, x - 1);
                rtn = (double)(negBit + posBit) + dec;
            }
        }

    }
    else {
        // range positive
        if (x > y)
            mytest_swap(&x, &y);
        int nudge = 0;
        y--;
        if (x == 0)
            nudge++;
        if (y == 0)
            nudge++;
        while (nonZero == 1 && rtn == 0)
            rtn = (double)(mytest_GetR(x + nudge, y + nudge) - nudge) + dec;
    }

    return ((int)(rtn * power)) / power;
}

std::vector<int> Utils::mytest_rfr(int numWidth, int denomWidth) {
    if (numWidth <= 0 || denomWidth <= 0 || numWidth > 9 || denomWidth > 9) {
        cout << endl << "Argument error - numWidth:" << numWidth  << " denomWidth: " << denomWidth << " in mytest_rfr\n";
        exit(-1);
    }

    std::vector<int> rtn;

    int proper = 1;
    int num = mytest_ri(pow(10, numWidth - 1), pow(10, numWidth) - 1);
    int denom = mytest_ri(pow(10, denomWidth - 1), pow(10, denomWidth) - 1);
    if (numWidth > denomWidth)
        proper = 0;
    while (num >= denom && proper) {
        num = mytest_ri(pow(10, numWidth - 1), pow(10, numWidth) - 1);
        denom = mytest_ri(pow(10, denomWidth - 1), pow(10, denomWidth) - 1);
    }
    rtn.push_back(num);
    rtn.push_back(denom);
    return rtn;
}

bool Utils::mytest_is_prime(int x) {
    if (x == 2)
        return true;
    if (x < 2)
        return false;
    if (x % 2 == 0 && x > 2) {
        return false;
    }
    if (x < max_prime) {
        return std::binary_search(prime_numbers.begin(), prime_numbers.end(), x);
    } else {
        for (int y = 3; y < x; y++) {
            if (y % x == 0) {
                return false;
            }
        }
        return true;
    }
}

void Utils::mytest_prime_factors(int x, vector<int> &rtn) {
    if (x > 1048577) {
        cout << endl << "Argument too large (mytest_prime_factors) : " <<  x;
        exit(-1);
    }
    if (x < 1) {
        rtn.push_back(0);
        return;
    }
    int i = (x / (fmax(mytest_strlen_int(x) * 2 - 2, 1))); // upper(ish) bound for prime space
    while (i >= 0) {
        if (x % prime_numbers[i] == 0) {
            rtn.push_back(prime_numbers[i]);
            x /= prime_numbers[i];
            if (x == 1)
                break;
            i = (x / (fmax(mytest_strlen_int(x) * 2 - 2, 1))) + 2; // bring the bound down accordingly
        }
        else {
            i -= 1;
        }
    }
    return;
}

int Utils::mytest_strlen_int(int x) {
    return snprintf(NULL, 0, "%d", abs(x));
}

int Utils::mytest_strlen_double(double x) {
    return snprintf(NULL, 0, "%f", fabs(x));
}

long long Utils::mytest_lcm(vector<int> set) {
    if(set.front()=='\0')
        return 0;
    for(int i=0;i<set.size();i++){
        if(set[i]<0)
            set[i]*=-1;
    }
    long long mult = accumulate(begin(set), end(set), 1, std::multiplies<>());
    if (mult > 1000000000) {
        cout << endl << "Input array product too large: %lld - mytest_lcm\n", mult;
        exit(-1);
    }
    long long rtn = mult;
    bool skip = false;
    int j;
    for (long long i = mult; i >= 1; i--) {
        skip = false;
        for(auto& j : set){
            if (i % j != 0) {
                skip = true;
                break;
            }
        }
        if (!skip)
            rtn = i;
        j++;
    }
    return rtn;
}

int Utils::mytest_hcf(vector<int> set) {
    int rtn = 0;

    // make set positive
    int setLen= set.size();
    for(int i=0;i<setLen;i++){
        if(set[i]<0)
            set[i]*=-1;
    }

    int bound = *std::min_element(set.begin(), set.end());
    if (INT_MAX == bound) {
        cout << endl << "Invalid element in input array (INT_MAX): mytest_hcf";
        exit(-1);
    }
    bound++;
    bool skip = false;
    int j = 0;
    for (int i = 1; i < bound; i++) {
        j = 0;
        //for(auto& j : set){
        for (int j = 0; j < setLen; j++) {
            if (set[j] % i != 0) {
                skip = true;
                break;
            }
            if (skip)
                rtn = i;
            skip = false;
            j++;
        }
    }
    return rtn;
}

int Utils::gjlib_sq(int x, int y) {
    // random square integer
    if (y<0 || x > sqrt(INT_MAX)) {
        cout << "Argument(s) exception: " << x << ", " << y << " in gjlib_sq";
        exit(-1);
    }
    if (x == 0)
        return 0;

    int ran = mytest_ri(x, y);
    long long rslt = pow(ran, 2);
    if (rslt <= INT_MIN || rslt >= INT_MAX) {
        cout << "Argument(s) exception: " << x << ", " << y << " in gjlib_sq";
        exit(-1);
    }
    return rslt;
}

int Utils::gjlib_notSq(int x, int y) {
    int rtn = 4;
    while (gjlib_isSquare(rtn)) {
        rtn = mytest_ri(x, y);
        if (1 == abs(rtn))
            break;
    }
    return rtn;
}

bool Utils::gjlib_isInt(double x) {
    if (x - (int)x == 0)
        return 1;
    return 0;
}

bool Utils::gjlib_isSquare(int x) {
    if (x < 4)
        return 0;
    return gjlib_isInt(sqrt(x)) == 1;
}

int Utils::gjlib_int_choose(vector<int> fromset) {
    int idx = mytest_ri(1, fromset.size())-1;
    return fromset[idx];
}

double Utils::gjlib_shrink(double x, int power) {
    return x / pow(10, power);
}

int Utils::gjlib_int_not(vector<int> notUs, int x, int y, int maxTries, int (Utils::*func)(int, int)) {
    using namespace std;
    int rslt = notUs.front();
    int tries=0;
    while( find(begin(notUs), end(notUs), rslt) != end(notUs) && tries <maxTries){
        rslt = (this->*func)(x, y);
        tries++;
    }
    if(tries==maxTries)
        throw runtime_error("gjlib_int_not exceeded maxTries");
    return rslt;
}

double Utils::gjlib_significant_figures(double num, int figures) {
    if (figures < 1) {
        cout << endl << "Argument exception: gjlib_significant_figures - figures =" <<  figures << "\n";
        exit(-1);
    }
    if (num == 0.0)
        return 0.0;

    double rtn = fabs(num);

    int shifts = 0;
    if (rtn < 1.0) {
        while (rtn < 1.0) {
            rtn *= 10;
            shifts--;
        }
        rtn *= 0.1;
        shifts++;
    }
    else {
        while (rtn > 1.0) {
            rtn *= 0.1;
            shifts++;
        }
    }
    rtn *= (double)pow(10, figures);
    rtn = (double)((int)round(rtn));
    rtn *= (double)pow(10, shifts - figures);

    if (num < 0)
        rtn *= -1;
    return rtn;
}

void Utils::mytest_to_super(string str, string &rtn) {//  ³√27    x²
    int len = str.length();
    for(int i=0; i<len; i++){
        switch (str[i]) {
        case '1': rtn.append("¹");break; //printf("\n1: %ld", strlen("¹")); 
        case '2': rtn.append( "²"); break; //printf("\n2: %ld", strlen("²")); 
        case '3': rtn.append( "³"); break; //printf("\n3: %ld", strlen("³")); 
        case '4': rtn.append( "⁴"); break; //printf("\n4: %ld", strlen("⁴")); 
        case '5': rtn.append( "⁵"); break; //printf("\n5: %ld", strlen("⁵")); 
        case '6': rtn.append( "⁶"); break; //printf("\n6: %ld", strlen("⁶")); 
        case '7': rtn.append( "⁷"); break; //printf("\n7: %ld", strlen("⁷")); 
        case '8': rtn.append( "⁸"); break; //printf("\n8: %ld", strlen("⁸")); 
        case '9': rtn.append( "⁹"); break; //printf("\n9: %ld", strlen("⁹")); 
        case '0': rtn.append( "⁰"); break; //printf("\n0: %ld", strlen("⁰")); 
        case '-': rtn.append( "⁻"); break; //printf("\n-: %ld", strlen("⁻")); 
        case '+': rtn.append( "⁺"); break; //printf("\n+: %ld", strlen("⁺")); 
        case '*': rtn.append( "*"); break; //printf("\n*: %ld", strlen("*")); 
        case '/': rtn.append( "ᐟ"); break; //printf("\n/: %ld", strlen("ᐟ")); 
        case '\\': rtn.append( "ᐠ"); break; //printf("\n\\: %ld", strlen("ᐠ"));
        case 'a': rtn.append( "ᵃ"); break; //printf("\na: %ld", strlen("ᵃ")); 
        case 'b': rtn.append( "ᵇ"); break; //printf("\nb: %ld", strlen("ᵇ")); 
        case 'c': rtn.append( "ᶜ"); break; //printf("\nc: %ld", strlen("ᶜ")); 
        case 'd': rtn.append( "ᵈ"); break; //printf("\nd: %ld", strlen("ᵈ")); 
        case 'e': rtn.append( "ᵉ"); break; //printf("\ne: %ld", strlen("ᵉ")); 
        case 'f': rtn.append( "ᶠ"); break; //printf("\nf: %ld", strlen("ᶠ")); 
        case 'g': rtn.append( "ᵍ"); break; //printf("\ng: %ld", strlen("ᵍ")); 
        case 'h': rtn.append( "ʰ"); break; //printf("\nh: %ld", strlen("ʰ")); 
        case 'i': rtn.append( "ⁱ"); break; //printf("\ni: %ld", strlen("ⁱ")); 
        case 'j': rtn.append( "ʲ"); break; //printf("\nj: %ld", strlen("ʲ")); 
        case 'k': rtn.append( "ᵏ"); break; //printf("\nk: %ld", strlen("ᵏ")); 
        case 'l': rtn.append( "ˡ"); break; //printf("\nl: %ld", strlen("ˡ")); 
        case 'm': rtn.append( "ᵐ"); break; //printf("\nm: %ld", strlen("ᵐ")); 
        case 'n': rtn.append( "ⁿ"); break; //printf("\nn: %ld", strlen("ⁿ")); 
        case 'o': rtn.append( "ᵒ"); break; //printf("\no: %ld", strlen("ᵒ")); 
        case 'p': rtn.append( "ᵖ"); break; //printf("\np: %ld", strlen("ᵖ")); 
        case 'q': rtn.append( "۹"); break;
        case 'r': rtn.append( "ʳ"); break; //printf("\nr: %ld", strlen("ʳ")); 
        case 's': rtn.append( "ˢ"); break; //printf("\ns: %ld", strlen("ˢ")); 
        case 't': rtn.append( "ᵗ"); break; //printf("\nt: %ld", strlen("ᵗ")); 
        case 'u': rtn.append( "ᵘ"); break; //printf("\nu: %ld", strlen("ᵘ")); 
        case 'v': rtn.append( "ᵛ"); break; //printf("\nv: %ld", strlen("ᵛ")); 
        case 'w': rtn.append( "ʷ"); break; //printf("\nw: %ld", strlen("ʷ")); 
        case 'x': rtn.append( "ˣ"); break; //printf("\nx: %ld", strlen("ˣ")); 
        case 'y': rtn.append( "ʸ"); break; //printf("\ny: %ld", strlen("ʸ")); 
        case 'z': rtn.append( "ᶻ"); break; //printf("\nz: %ld", strlen("ᶻ")); 
        case 'A': rtn.append( "ᴬ"); break; //printf("\nA: %ld", strlen("ᴬ")); 
        case 'B': rtn.append( "ᴮ"); break; //printf("\nB: %ld", strlen("ᴮ")); 
        case 'C': rtn.append( "ᶜ"); break;
        case 'D': rtn.append( "ᴰ"); break; //printf("\nD: %ld", strlen("ᴰ")); 
        case 'E': rtn.append( "ᴱ"); break; //printf("\nE: %ld", strlen("ᴱ")); 
        case 'F': rtn.append( "ᶠ"); break;
        case 'G': rtn.append( "ᴳ"); break; //printf("\nG: %ld", strlen("ᴳ")); 
        case 'H': rtn.append( "ᴴ"); break; //printf("\nH: %ld", strlen("ᴴ")); 
        case 'I': rtn.append( "ᴵ"); break; //printf("\nI: %ld", strlen("ᴵ")); 
        case 'J': rtn.append( "ᴶ"); break; //printf("\nJ: %ld", strlen("ᴶ")); 
        case 'K': rtn.append( "ᴷ"); break; //printf("\nK: %ld", strlen("ᴷ")); 
        case 'L': rtn.append( "ᴸ"); break; //printf("\nL: %ld", strlen("ᴸ")); 
        case 'M': rtn.append( "ᴹ"); break; //printf("\nM: %ld", strlen("ᴹ")); 
        case 'N': rtn.append( "ᴺ"); break; //printf("\nN: %ld", strlen("ᴺ")); 
        case 'O': rtn.append( "ᴼ"); break; //printf("\nO: %ld", strlen("ᴼ")); 
        case 'P': rtn.append( "ᴾ"); break; //printf("\nP: %ld", strlen("ᴾ")); 
        case 'R': rtn.append( "ᴿ"); break; //printf("\nR: %ld", strlen("ᴿ")); 
        case 'T': rtn.append( "ᵀ"); break; //printf("\nT: %ld", strlen("ᵀ")); 
        case 'S': rtn.append( "ˢ"); break; //printf("\nT: %ld", strlen("ᵀ")); 
        case 'U': rtn.append( "ᵁ"); break; //printf("\nU: %ld", strlen("ᵁ")); 
        case 'V': rtn.append( "ⱽ"); break; //printf("\nV: %ld", strlen("ⱽ")); 
        case 'W': rtn.append( "ᵂ"); break; //printf("\nW: %ld", strlen("ᵂ")); 
        case 'X': rtn.append( "ˣ"); break; //printf("\nT: %ld", strlen("ᵀ")); 
        case 'Y': rtn.append( "ʸ"); break; //printf("\nT: %ld", strlen("ᵀ")); 
        case 'Z': rtn.append( "ᶻ"); break; //printf("\nT: %ld", strlen("ᵀ")); 
        case '=': rtn.append( "⁼"); break; //printf("\n=: %ld", strlen("₌")); 
        case '(': rtn.append( "⁽"); break; //printf("\n(: %ld", strlen("⁽")); 
        case ')': rtn.append( "⁾"); break; //printf("\n): %ld", strlen("⁾")); 
        default: rtn+= wchar_t(str[i]); break;
        }
    }
    return;
}

void Utils::mytest_to_sub(string str, string &rtn) {
    int len = str.length();
    for(int i=0; i<len ;i++){
        switch (str[i]) {
        case '1': rtn.append( "₁"); break; //printf("\n₁ : %ld",strlen("₁"));
        case '2': rtn.append( "₂"); break; //printf("\n₂ : %ld",strlen("₂"));
        case '3': rtn.append( "₃"); break; //printf("\n₃ : %ld",strlen("₃"));
        case '4': rtn.append( "₄"); break; //printf("\n₄ : %ld",strlen("₄"));
        case '5': rtn.append( "₅"); break; //printf("\n₅ : %ld",strlen("₅"));
        case '6': rtn.append( "₆"); break; //printf("\n₆ : %ld",strlen("₆"));
        case '7': rtn.append( "₇"); break; //printf("\n₇ : %ld",strlen("₇"));
        case '8': rtn.append( "₈"); break; //printf("\n₈ : %ld",strlen("₈"));
        case '9': rtn.append( "₉"); break; //printf("\n₉ : %ld",strlen("₉"));
        case '0': rtn.append( "₀"); break; //printf("\n₀ : %ld",strlen("₀"));

        case '+': rtn.append( "₊"); break; //printf("\n₊ : %ld",strlen("₊"));
        case '-': rtn.append( "₋"); break; //printf("\n₋ : %ld",strlen("₋"));
        case '=': rtn.append( "₌"); break; //printf("\n₌ : %ld",strlen("₌"));
        case '(': rtn.append( "₍"); break; //printf("\n₍ : %ld",strlen("₍"));
        case ')': rtn.append( "₎"); break; //printf("\n₎ : %ld",strlen("₎"));

        case 'a': rtn.append( "ₐ"); break; //printf("\nₐ : %ld",strlen("ₐ"));
        case 'b': rtn.append( "♭"); break;
        case 'e': rtn.append( "ₑ"); break; //printf("\nₑ : %ld",strlen("ₑ"));
            //case 'h': rtn.append( "ₕ"); break;; //printf("\nₕ : %ld",strlen("ₕ")); 
        case 'g': rtn.append( "₉"); break;
        case 'h': rtn.append( "ₕ"); break;
        case 'i': rtn.append( "ᵢ");  break; //printf("\nᵢ : %ld",strlen("ᵢ"));
        case 'j': rtn.append( "ⱼ");  break; //printf("\nⱼ : %ld",strlen("ⱼ"));
            // case 'k': rtn.append( "ₖ"); break;; //printf("\nₖ : %ld",strlen("ₖ")); 
            // case 'l': rtn.append( "ₗ"); break;; //printf("\nₗ : %ld",strlen("ₗ")); 
            // case 'm': rtn.append( "ₘ"); break;; //printf("\nₘ : %ld",strlen("ₘ")); 
            // case 'n': rtn.append( "ₙ"); break; //printf("\nₙ : %ld",strlen("ₙ"));
        case 'k': rtn.append( "ₖ"); break;
        case 'l': rtn.append( "ₗ"); break;
        case 'm': rtn.append( "ₘ"); break;
        case 'n': rtn.append( "ₙ"); break;
        case 'o': rtn.append( "ₒ"); break; //printf("\nₒ : %ld",strlen("ₒ"));
            //case 'p': rtn.append( "ₚ"); break; //printf("\nₚ : %ld",strlen("ₚ"));
        case 'p': rtn.append( "ₚ"); break;
        case 'r': rtn.append( "ᵣ"); break; //printf("\nᵣ : %ld",strlen("ᵣ"));
            // case 's': rtn.append( "ₛ"); break; //printf("\nₛ : %ld",strlen("ₛ")); 
            // case 't': rtn.append( "ₜ"); break; //printf("\nₜ : %ld",strlen("ₜ")); 
        case 's': rtn.append( "ₛ"); break;
        case 't': rtn.append( "ₜ"); break;
        case 'u': rtn.append( "ᵤ"); break; //printf("\nᵤ : %ld",strlen("ᵤ")); 
        case 'v': rtn.append( "ᵥ"); break; //printf("\nᵥ : %ld",strlen("ᵥ")); 
        case 'x': rtn.append( "ₓ"); break; //printf("\nₓ : %ld",strlen("ₓ")); 
        default: rtn+= wchar_t(str[i]); break;
        }
    }
    return;
}

void Utils::mytest_to_standard_form(double num, string &rtn) {
    if (num == 0) {
        rtn.append("0");
        return;
    }
    if (num == 1) {
        rtn.append("1");
        return;
    }
    if (num == -1) {
        rtn.append("-1");
        return;
    }

    double sign = num > 0 ? 1 : -1;
    char buffer[20];
    int i = 0;

    if (fabs(num) >= 1.0 && fabs(num) < 10.0) { //already in standard form.
        rtn.append(to_string(num));
        return;
    }

    double orig = num;
    int shifts = 0;
    num = fabs(num);
    if (num < 1) {
        while (num < 1.0) {
            num *= 10.0;
            shifts++;
        }
    }
    else {
        while (num >= 10.0) {
            num /= 10.0;
            shifts++;
        }
    }
    num *= sign;
    std::defaultfloat;
    rtn.append(to_string(num));
    rtn.append("*10");

    string supe;
    if (fabs(orig) > 1){
        mytest_to_super("-", supe);
    }
        
    mytest_to_super(to_string(shifts), supe);
    rtn.append(supe);
    return;
}
 
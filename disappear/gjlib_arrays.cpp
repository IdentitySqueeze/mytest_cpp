#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

int * gjlib_int_array_init(int * rtn, int argnum, ...){
    rtn = (int*) malloc((2+argnum) * sizeof(int));
    if(rtn==NULL){
        printf("Error allocating memory: g_int_array_create");
        exit(-1);
    }
    va_list valist;
    va_start(valist, argnum);
    int j=0;
    int i=0;
    for(i=0; i<argnum; i++){
        j=va_arg(valist,int);
        *rtn++=j;
    }
    *rtn++='\0';
    va_end(valist);
    rtn = rtn-(i+1);
    return rtn;
}

int gjlib_int_array_contains(int x, int arr[], int n){
    //int rtn=0;
    int low, mid, high;
    low =0;
    high = n-1;
    while(low <= high){
        mid = (low+high)/2;
        if(x < arr[mid]){
            high = mid -1;
        }else if( x > arr[mid]){
            low = mid + 1;
        }else{
            //return mid;
            return 1;
        }
    }
    //return rtn;
    return 0;
}

int gjlib_int_array_min(int * set){
    int rtn=INT_MAX;
    int j=0;
    while(*(set+j)){
        if(*(set+j) < rtn)
            rtn= *(set+j);
        *set++;        
    }
    return rtn;
}

long long gjlib_int_array_product( int * x){
    long int rtn = 1;
    while(*x)
        rtn *= *x++;
    return rtn;
}

char * gjlib_int_array_implode(int * a, char * rtn){
    char buffer[100];
    int i =0;
    memset(rtn, 0, sizeof rtn);
    i = snprintf(buffer, 10, "%i", *a++);
    if(!(i>=0 && i <100)){
        printf("Error imploding array");
        exit(0);
    }
    rtn.append(buffer);
    if(*a=='\0')
        return rtn;
    rtn.append(",");
    for(;;){
        i = snprintf(buffer, 10, "%i", *a++);
        if(!(i>=0 && i <100)){
            printf("Error imploding array");
            exit(-1);
        }
        rtn.append(buffer);
        if(*a =='\0'){
            break;
        }
        rtn.append(",");
    }
    return rtn;
}

int * gjlib_int_array_reverse(int * inbound){
    int el_count=1;
    int save_count =0;
    int * pel_count = &el_count;

    while(*inbound++)
        el_count++; //ok just count
    save_count = el_count;

    // memory ------------
    int * rtn = (int *)malloc(*(pel_count+1)*sizeof(int));
    if(rtn==NULL){
        printf("Unable to (re)allocate memory: gjlib_int_array_reverse");
        exit(-1);
    } //------------------

    *inbound--;
    while(el_count-->0)
        *rtn++ = *(--inbound);

    * (rtn +(el_count))='\0';
    rtn = rtn - save_count;
    return rtn;
}
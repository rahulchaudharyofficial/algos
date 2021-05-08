#include "utils.h"

bool array_eq(const int* a1, const int* a2) {
    
    if(sizeof(a1) == sizeof(a2)) {
        bool eq = true;
        for(int i=0; i< sizeof(a1);i++) {
            if(*(a1+i) != *(a2+i)) {
                eq = false;
                break;
            }
        }
        return eq;
    }
    else {
        return false;
    }
}
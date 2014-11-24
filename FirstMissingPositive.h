#ifndef _FIRST_MISSING_POSITIVE
#define _FIRST_MISSING_POSITIVE

#include "commonHeader.h"

int firstMissingPositive(int A[], int n) {
        if (n<=0) return 1;
        int min = 2;
        for(int i=0;i<n;i++)
            if (A[i]<min && A[i]>0) min = A[i];
        if (min>1) return 1;
        for(int i=0;i<n;i++){
            if (A[i]>0 && A[i]!=i+1 && A[i]-1 < n && A[A[i]-1] != A[i]){
                int temp = A[i];
                A[i] = A[A[i]-1];
                A[temp-1] = temp;
                i--;
            }
        }
        for(int i=0;i<n;i++)
            if(A[i]!=i+1) return i+min;
        return n+1;
    }

#endif
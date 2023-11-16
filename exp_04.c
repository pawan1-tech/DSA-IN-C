#include <stdio.h>

void binarysearch(int a[], int start, int end, int val){
    int mid;
    while (start <= end){
        mid = (start + end) / 2;
        if (a[mid] == val){
            printf("The element %d is found at index %d.\n", val, mid);
            return;
        }
        else if (val < a[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    printf("The element %d is not found in the list.\n", val);
    return;
}


void linearsearch(int a[], int n, int val){
    int i;
    for (i = 0; i < n; i++){
        if (a[i] == val){
            printf("The element %d is found at index %d.\n", val, i);
            return;
        }
    }
    printf("The element %d is not found in the list.\n", val);
}


int main(){
    int a[] = {10, 20, 30, 15, 45, 60, 70};
    int b[] = { 24, 36, 52, 57, 59, 69, 72, 78, 79, 81};

    binarysearch(b, 0, 9, 59); 
    linearsearch(a, 7, 15);
    
    return 0;
}

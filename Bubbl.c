#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[],int n){
    int i,j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    int array[]={5,4,3,2,1};
    int n=sizeof(array)/sizeof(array[0]);
    printf("Original Array: \n");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    printf("\n\n");
    bubbleSort(array,n);
    printf("Array after Bubble Sorting: \n");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    return 0;
}
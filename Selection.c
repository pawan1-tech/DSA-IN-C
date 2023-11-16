#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int arr[],int n){
    int i, j, min_idx;
    for (i = 0; i < n-1; i++){
        min_idx = i;
        for(j=i;j<n;j++){
            if(arr[min_idx] > arr[j]){
                min_idx = j;
            }
        }
        int tmp=arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx]=tmp;
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
    SelectionSort(array,n);
    printf("Array after Selection Sorting: \n");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    return 0;
}
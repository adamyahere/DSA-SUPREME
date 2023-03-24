// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int partition(int *arr, int s , int e ){
    //step1: choose pivot
    int pivotIndex = s;
    int pivotElement = arr[s];
    
    //step2: find the right position for pivot element and place it there
    int count = 0;
    for(int i = s + 1; i<=e; i++){
        if(arr[i] <= pivotElement){
            count++;
        }
    }
    
    //count -> is the right index for the pivot element 
    int rightIndex = s + count ;
    swap(arr[pivotIndex],arr[rightIndex]);
    pivotIndex = rightIndex;
    
    //step 3: ->left me chhote and rigth me bade elements:
    int i = s;
    int j = e;
    
    while(i<pivotIndex && j > pivotIndex){
        while(arr[i] <= pivotElement ){
            i++;
        }
        while(arr[j] > pivotElement ){
            j--;
        }
        //2cases ->
        //1. case->you find the element to swap;
        if(i<pivotIndex && j > pivotIndex){
            swap(arr[i], arr[j]);
        }
        //2. No need to swap:
    }
    return pivotIndex;
}

void quickS(int *arr, int s , int e ){
    //base case
    if(s>=e){
        return;
    }
    
    //partition logic
    int p = partition(arr,s,e);
    //recursive call
    //pivot element -> left
    quickS(arr,s,p-1);
    //pivot element -> right
    quickS(arr,p+1,e);
}

int main() {
    int arr[7] = {8,3,4,1,20,50,30};
    int n = 7;
    int s = 0;
    int e = n -1;
    
    quickS(arr,s,e);
    
    for(int i = 0 ; i< n ;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

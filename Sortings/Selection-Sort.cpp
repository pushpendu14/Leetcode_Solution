#include <iostream>
using namespace std;

int main() {
    int arr[5]={15,6,-8,58,9};
    int n=5;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    return 0;
}

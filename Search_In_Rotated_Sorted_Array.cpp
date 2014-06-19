#include <iostream>

using namespace std;

//O(n) solution
int search(int A[], int n, int target)
{
    for(int i = 0; i < n; ++i)
        if(A[i] == target)
            return i;
    return -1;
}

//binary search O(logn) solution
int search2(int A[], int n, int target)
{
    int low = 0, high = n -1;
    while(low <= high){
        int middle = (low + high) / 2;
        if(A[middle] == target) return middle;

        if(A[middle] >= A[low]){// find the first exact sorted half
            //if target is in the sorted part
            if(target >= A[low] && target <= A[middle])
                high = middle - 1;
            else
                low = middle + 1;
        }else{//the second sorted half
            if(target >= A[middle] && target <= A[high])
                low = middle + 1;
            else
                high = middle - 1;
        }
    }
    return -1;
}

void generateArray(int *A, const int n)
{
    for(int i = 0; i < n; i ++){
        A[i] = i;
    }
}

void printArray(int *A, const int n)
{
    for(int i = 0; i < n; ++i){
        cout<< A[i] << " ";
    }
    cout<<endl;
}

int main(){
    const int size = 20;
    int B[size];
    generateArray(B, size);
    printArray(B, size);

    int A[2] = {3, 1};
    cout<< search2(A, 2, 1) << endl;
    return 0;
}

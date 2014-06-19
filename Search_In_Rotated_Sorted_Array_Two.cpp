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
bool search2(int A[], int n, int target)
{
    int low = 0, high = n -1;
    while(low <= high){
        int middle = (low + high) / 2;
        if(A[middle] == target) return true;

        if(A[middle] > A[low]){// find the first exact sorted half
            //if target is in the sorted part
            if(target >= A[low] && target <= A[middle])
                high = middle - 1;
            else
                low = middle + 1;
        }else if(A[middle] < A[low]){//the second sorted half
            if(target >= A[middle] && target <= A[high])
                low = middle + 1;
            else
                high = middle - 1;
        }else{
            low++;
        }
    }
    return false;
}

void generateArray(int *A, const int n)
{
    for(int i = 0; i < n; i += 2){
        A[i] = i;
        A[i+1] = i;
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

    cout<< search2(B, size, 4) << endl;

    int C[4] = {3, 1, 1, 3};
    printArray(C, 4);
    cout<<"search 3: "<<search2(C, 4, 3)<<endl;
    cout<<"search 2: " <<search2(C, 4, 2)<<endl;

    int D[5] = {1, 3, 1, 1, 1};
    printArray(D, 5);
    cout<<"search 1: " <<search2(D, 5, 1)<<endl;
    cout<<"search 2: " <<search2(D, 5, 2)<<endl;
    cout<<"search 3: " <<search2(D, 5, 3)<<endl;

    int E[3] = {3, 1, 2};
    printArray(E, 3);
    cout<<"search 3: " <<search2(E, 3, 3) <<endl;
    cout<<"search 1: " <<search2(E, 3, 1) <<endl;
    cout<<"search 2: " <<search2(E, 3, 2) <<endl;
    return 0;
}

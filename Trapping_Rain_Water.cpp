#include <iostream>
#include <vector>

using namespace std;

int trap(int A[], int n) {
    vector<int> left(n, 0), right(n, 0);

    //compute the left highest
    int highest = 0;
    for(int i = 0; i < n; ++i){
        if(i == 0) left[i] = 0;
        else{
            highest = max(highest, A[i-1]);
            left[i] = highest;

        }
    }

    //compute the right highest
    highest = 0;
    for(int i = n - 1; i >= 0; --i){
        if(i == n - 1) right[i] = 0;
        else{
            highest = max(highest, A[i+1]);
            right[i] = highest;
        }
    }

    //compute the total rain trap
    int sum = 0;
    for(int i = 0; i < n; ++i){
        int tmp =  (min(left[i], right[i]) - A[i]);
        if(tmp > 0) sum += tmp;
        //cout<<sum <<" "<<endl;
    }

    return sum;
}

int main()
{
    int A[12] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout<< trap(A, 12);
    return 0;
}

#include <iostream>

using namespace std;

//O(log(m + n)) solution
int find_kth(int A[], int m, int B[], int n, int k)
{
    if(m > n) return find_kth(B, n, A, m, k);
    if(m == 0) return B[k-1];
    if(k == 1) return min(A[0], B[0]);

    int ai = min(m, k / 2), bi = k - ai;
    if(A[ai-1] < B[bi-1])
        return find_kth(A + ai, m - ai, B, n, k - ai);
    else if(A[ai-1] > B[bi-1])
        return find_kth(A, m, B + bi, n - bi, k - bi);
    else return A[ai-1];
}

double findMedianSortedArrays(int A[], int m, int B[], int n)
{
    int total = m + n;
    if(total & 0x1)
        return find_kth(A, m, B, n, total / 2 + 1);
    else
        return (find_kth(A, m, B, n, total / 2)
                + find_kth(A, m, B, n, total / 2 + 1)) / 2.0f;
}



//O(n + m) solution
double findMedianSortedArrays2(int A[], int m, int B[], int n)
{
    if( m == 0 && n == 0) return 0.0f;

    int median = (m + n) / 2;
    bool need_average = ((m + n) % 2 == 0) ? true : false;
    double median_val = 0;
    double median_val_prev  = 0;
    int i = 0, j = 0, k = 0;
    while(i < m && j < n && k <= median){
        if(need_average){
            if(i-1 >= 0 && j-1 >=0) { median_val_prev = B[j-1] >= A[i-1] ? B[j-1] : A[i-1]; }
            else if(i-1 < 0 && j-1 >= 0) { median_val_prev = B[j-1]; }
            else if(i-1 >=0 && j-1 < 0) { median_val_prev = A[i-1]; }
        }

        if(A[i] <= B[j]) {
            median_val = A[i]; i++; k++;
        }else {
            median_val = B[j]; j++; k++;
        }
    }

    while(i < m && k <= median){
        if(need_average){
            if(n > 0 && i-1 >= 0) { median_val_prev = A[i-1] >= B[n-1] ? A[i-1] : B[n-1]; }
            else if(n <= 0 && i-1 >= 0) { median_val_prev = A[i-1]; }
            else if(i-1 < 0 && n > 0) { median_val_prev = B[n-1]; }
        }
        median_val = A[i];
        //cout<<"i: "<<i <<"k:  "<<k<<endl;
        //cout<<"median val: " <<median_val<<endl;
        i++; k++;
    }

    while(j < n && k <= median){
        if(need_average){
            if(m > 0 && j-1 >= 0) { median_val_prev = B[j-1] >= A[m-1] ? B[j-1] : A[m-1]; }
            else if(m <= 0 && j-1 >= 0) { median_val_prev = B[j-1]; }
            else if(j-1 < 0 && m > 0) { median_val_prev = A[m-1]; }
        }
        median_val = B[j];
        j++; k++;
        //cout<<"j: "<<j <<"k: "<<k <<endl;
        //cout<<"median val: " <<median_val<<endl;
    }

    //cout<<"pre val: "<<median_val_prev <<" median: " <<median_val <<endl;
    if(need_average)
        return (median_val + median_val_prev) / 2.0f;
    else
        return median_val;
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
    int A[1] = {1};
    int B[1] = {1};
    cout<<findMedianSortedArrays(A, 1, B, 1)<<endl;
    return 0;
}

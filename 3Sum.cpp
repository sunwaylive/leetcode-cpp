#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num)
{
    typedef vector<int>::iterator VI;

    vector<vector<int> > result;
    if(num.size() < 3) return result;

    sort(num.begin(), num.end());
    const int target = 0;
    VI last = num.end();
    VI a_end = prev(last, 2);
    for(VI a = num.begin(); a < a_end; ++a){
        if(a > num.begin() && *a == *(a-1)) continue;

        VI b = next(a);
        VI c = prev(last);
        while(b < c){
            if(b - 1 > a && *b == *(b-1)) { b++; continue; }
            if(c + 1 < num.end() && *c == *(c+1)) { c--; continue; }
            //cout<<"b: "<< *b <<"c: " << *c <<endl;
            if(*a + *b + *c < target){ b++; }
            else if(*a + *b + *c > target) { c--; }
            else{
                int tmp[3] = {*a, *b, *c};
                vector<int> t(tmp, tmp + 3);
                result.push_back(t);
                //result.push_back({*a, *b, *c});
                b++; c--;
            }
        }
    }
    //sort(result.begin(), result.end());
    //result.erase(unique(result.begin(), result.end()), result.end());
    return result;
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

void printVector(const vector<int> &v)
{
    for(vector<int>::const_iterator iter = v.begin();
        iter != v.end(); ++iter){
        cout<<*iter <<" ";
    }
    cout<<endl;
}


int main(){
    const int size = 20;
    int A[size];
    generateArray(A, size);
    vector<int> num;
    for(int i = 0; i < size; ++i)
        num.push_back(A[i]);
    printVector(num);

    num.clear();
    num.push_back(-1);
    num.push_back(1);
    num.push_back(-2);
    num.push_back(0);
    num.push_back(2);
    num.push_back(1);
    num.push_back(2);
    vector<vector<int> > re;
    re = threeSum(num);
    cout<<"result size: "<< re.size() <<endl;
    return 0;
}

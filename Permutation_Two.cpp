#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool nextPermutation(vector<int> &);
vector<vector<int> > permute(vector<int> &);

vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int> > ret;
    ret = permute(num);

    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    return ret;
}

vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > ret;

    sort(num.begin(), num.end());
    ret.push_back(num);

    while(nextPermutation(num))
        ret.push_back(num);

    return ret;
}

//detect the position of the permutation
int getPermutationPos(int s[], int n)
{
    const int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};///阶乘
    int i, j;
    int cnt = 0, sum = 0;
    for(i = 0; i < n; ++i){
        cnt = 0;
        for(j = i + 1; j < n; j++){
            if(s[j] < s[i]) cnt++;
        }
        sum += cnt * fac[n - i - 1];
    }

    return sum + 1;
}

//康托展开 求k-th permutation
string getPermutation2(int n, int k)
{
    const int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};///阶乘
    bool visited[10] = {false, false, false, false, false,
                        false, false, false, false, false };
    string ans(n, '0');
    int i, j, t;
    k--;
    for(i = 0; i < n; i++){
        t = k / fac[n - i - 1];
        for(j = 1; j <= n; j++){
            if(!visited[j]){
                if(t == 0) break;
                else t--;
            }
        }
        ans[i] += j, visited[j] = true;
        k %= fac[n - i - 1];
    }
    return ans;
}

//Time Limit Exceed solution
bool nextPermutation(vector<int> &num) {
    int size = num.size();
    int pivot, first_larger, i;
    for(i = size - 2; i >= 0; --i)
        if(num[i] < num[i+1])
            break;

    pivot = i;
    //cout<<"pivot: "<<pivot<<endl;
    //if already in descending order, then reverse and return;
    if(pivot < 0)
        return false;

    for(i = size - 1; i > pivot; --i){
        if(num[i] > num[pivot])
            break;
    }

    first_larger = i;
    //cout<<"first larger: "<<first_larger <<endl;
    //swap the two numbers
    num[pivot] ^= num[i];
    num[i] ^= num[pivot];
    num[pivot] ^= num[i];

    reverse(num.begin() + pivot + 1, num.end());
    return true;
}

string getPermutation(int n, int k) {
    vector<int> permutation;
    string ret(n, '0');
    for(int i = 0; i < n; ++i)
        permutation.push_back(i+1);

    bool has_next = true;
    for(int i = 0; i < k-1 && has_next; ++i)
        has_next = nextPermutation(permutation);

    for(int i = 0; i < n; ++i)
        ret[i] = ret[i] + permutation[i];

    return ret;
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
    int a[] = {1, 1, 2};
    vector<int> A(a, a+3);
    vector<vector<int> > result;
    result = permuteUnique(A);
    for(int i = 0; i < result.size(); ++i){
        printVector(result[i]);
    }
    cout<<result.size() <<endl;
    return 0;
}

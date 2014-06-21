#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int> > result;
    if(num.size() < 4) return result;

    sort(num.begin(), num.end());
    unordered_map<int, vector<pair<int, int> > > cache;
    //save sum of two
    for(size_t a = 0; a < num.size(); ++a)
        for(size_t b = a + 1; b < num.size(); ++b)
            cache[num[a] + num[b]].push_back(pair<int, int>(a, b));

    //forward and backward shrink
    for(int c = 0; c < num.size(); ++c){
        for(size_t d = c + 1; d < num.size(); ++d){
            const int key = target - num[c] - num[d];
            if(cache.find(key) == cache.end()) continue;

            vector<pair<int, int> > vec = cache[key];
            for(size_t k = 0; k < vec.size(); ++k){
                if(c <= vec[k].second) continue;//duplicate exists

                vector<int> tmp;
                tmp.push_back(num[vec[k].first]);
                tmp.push_back(num[vec[k].second]);
                tmp.push_back(num[c]);
                tmp.push_back(num[d]);
                result.push_back(tmp);
            }
        }
    }

    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
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
    int B[6] = {-1,5,1,-3,-4,0};
    vector<int> num(B, B+6);
    vector<vector<int> > re = fourSum(num, -7);
    for(size_t i = 0; i < re.size(); ++i){
        printVector(re[i]);
    }
    cout<<re.size() <<endl;
    return 0;
}

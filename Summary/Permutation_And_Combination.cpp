#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


//************************************************************
int strStr(const string txt, const string pat)
{
    if(txt.empty() || pat.empty())
        return -1;
    const int t_len = txt.length();
    const int p_len = pat.length();
    int i, j;
    for(i = 0; i < t_len - p_len + 1; ++i){
        for(j = 0; j < p_len; ++j){
            if(txt[i + j] != pat[j])
                break;
        }
        if(j == p_len) return i;
    }
    return -1;
}


//************************************************************
void subsetsHelper(vector<int> &nums, vector<vector<int> > &result, vector<int> &path, int start){
    result.push_back(path);
    for(int i = start; i < nums.size(); ++i){
        path.push_back(nums[i]);
        subsetsHelper(nums, result, path, i + 1);
        path.pop_back();
    }
}

void subsetsHelperUnique(vector<int> &nums, vector<vector<int> > &result, vector<int> &path, int start){
    result.push_back(path);
    for(int i = start; i < nums.size(); ++i){
        if(i > start && nums[i] == nums[i - 1]) // case: 1 2 2 case: 3 3 4
            continue;
        path.push_back(nums[i]);
        subsetsHelperUnique(nums, result, path, i + 1);
        path.pop_back();
    }
}

vector<vector<int> > subsets(vector<int> &nums){
    vector<vector<int> > result;
    if(nums.empty()) return result;

    sort(nums.begin(), nums.end());
    vector<int> path;
    subsetsHelperUnique(nums, result, path, 0);
    return result;
}

//************************************************************
void permuteHelper(const vector<int> &nums, vector<vector<int> > &result, vector<int> &path){
    if(path.size() == nums.size()){
        result.push_back(path);
        return;
    }
    for(int i = 0; i < nums.size(); ++i){
        vector<int>::iterator pos = std::find(path.begin(), path.end(), nums[i]);
        if(pos == path.end()){
            path.push_back(nums[i]);
            permuteHelper(nums, result, path);
            path.pop_back();
        }
    }
}

map<int, int> cache;
int n;
void permuteHelperUnique(map<int, int>::iterator begin, map<int, int>::iterator end,  vector<vector<int> > &result, vector<int> &path){
    if(path.size() == n){
        result.push_back(path);
        return ;
    }

    for(map<int, int>::iterator iter = begin; iter != end; ++iter){
        int count = 0;
        for(int j = 0; j < path.size(); ++j)
            if( iter->first== path[j])
                count++;

        if(count < iter->second){
            path.push_back(iter->first);
            permuteHelperUnique(begin, end, result, path);
            path.pop_back();
        }
    }
}

vector<vector<int> > permute(vector<int> nums){
    vector<vector<int> > result;
    if(nums.empty()) return result;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); ++i){
        cache[nums[i]]++;
    }

    vector<int> path;
    n = nums.size();
    permuteHelperUnique(cache.begin(), cache.end(), result, path);
    return result;
}

//************************************************************
//problem located here:  https://oj.leetcode.com/problems/combinations/
void combineHelper(int n, int k, vector<vector<int> > &result, vector<int> &path, int start){
    if(path.size() == k){
        result.push_back(path);
        return;
    }
    for(int i = start; i <= n; ++i){
        path.push_back(i);
        combineHelper(n, k, result, path, i + 1);
        path.pop_back();
    }
}

vector<vector<int> > combine(int n, int k){
    vector<vector<int> > result;

    vector<int> path;
    combineHelper(n, k, result, path, 1);
    return result;
}

//************************************************************
//https://oj.leetcode.com/problems/combination-sum/
//https://oj.leetcode.com/problems/combination-sum-ii/
void combinationSumHelper(vector<int> &candidates, int sum, vector<vector<int> > &result, vector<int> &path, int start){
    if(sum < 0) return;
    else if(sum == 0){
        result.push_back(path);
        return;
    }

    for(int i = start; i < candidates.size(); ++i){
        path.push_back(candidates[i]);
        combinationSumHelper(candidates, sum - candidates[i], result, path, i + 1);
        path.pop_back();
    }
}

void combinationSumHelperUnique(vector<int> &candidates, int sum, vector<vector<int> > &result, vector<int> &path, int start){
    if(sum < 0) return;
    else if(sum == 0){
        result.push_back(path);
        return;
    }

    for(int i = start; i < candidates.size(); ++i){
        if(i > start && candidates[i] == candidates[i - 1]) continue;
        path.push_back(candidates[i]);
        combinationSumHelperUnique(candidates, sum -  candidates[i], result, path, i);
        path.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target){
    vector<vector<int> > result;
    if(candidates.empty()) return result;

    vector<int> path;
    sort(candidates.begin(), candidates.end());
    combinationSumHelperUnique(candidates, target, result, path, 0);
    return result;
}

//************************************************************
//https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
map<char, vector<char> > dict;
void createDict();//implementation at the end of the file

void letterCombinationsHelper(string &digits, vector<string> &result, string &path, int start){
    if(path.size() == digits.size()){
        result.push_back(path);
        return;
    }
    for(int i = 0; i < dict[digits[start]].size(); ++i){
        path += dict[digits[start]][i];
        letterCombinationsHelper(digits, result, path, start + 1);
        path.erase(path.end() - 1, path.end());
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if(digits.empty()) return result;

    createDict();
    string path;
    letterCombinationsHelper(digits, result, path, 0);
    return result;
}

//************************************************************

int main()
{
    string a("234");
    vector<string> result;
    result = letterCombinations(a);
    for(int i = 0; i < result.size(); ++i){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}


//utility function
void createDict()
{
    dict.clear();
    dict['2'].push_back('a');
    dict['2'].push_back('b');
    dict['2'].push_back('c');
    dict['3'].push_back('d');
    dict['3'].push_back('e');
    dict['3'].push_back('f');
    dict['4'].push_back('g');
    dict['4'].push_back('h');
    dict['4'].push_back('i');
    dict['5'].push_back('j');
    dict['5'].push_back('k');
    dict['5'].push_back('l');
    dict['6'].push_back('m');
    dict['6'].push_back('n');
    dict['6'].push_back('o');
    dict['7'].push_back('p');
    dict['7'].push_back('q');
    dict['7'].push_back('r');
    dict['7'].push_back('s');
    dict['8'].push_back('t');
    dict['8'].push_back('u');
    dict['8'].push_back('v');
    dict['9'].push_back('w');
    dict['9'].push_back('x');
    dict['9'].push_back('y');
    dict['9'].push_back('z');
}

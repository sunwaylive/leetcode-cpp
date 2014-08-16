#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//************************************************************
//https://oj.leetcode.com/problems/palindrome-partitioning/
bool isPalindrome(string &s, int start, int end){
    while(s[start] == s[end])
        start++, end--;
    return start >= end;
}

void partitionHelper(string &s, vector<vector<string> > &result, vector<string> &path, int start){
    if(start == s.size()) result.push_back(path);

    for(int i = start; i < s.size(); ++i){
        if(isPalindrome(s, start, i)){
            path.push_back(s.substr(start, i - start + 1));
            partitionHelper(s, result, path, i + 1);
            path.pop_back();
        }
    }
}

vector<vector<string> > partition(string s){
    vector<vector<string> > result;
    if(s.empty()) return result;

    vector<string> path;
    partitionHelper(s, result, path, 0);
    return result;
}

//https://oj.leetcode.com/problems/palindrome-partitioning-ii/


int main()
{
    string a("aab");
    vector<vector<string> > result;
    result = partition(a);
    for(int i = 0; i < result.size(); ++i){
        for(int j = 0; j < result[i].size(); ++j){
            cout<<result[i][j] <<" ";
        }
        cout<<endl;
    }
    return 0;
}

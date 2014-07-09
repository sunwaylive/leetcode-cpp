#include <iostream>
#include <vector>
using namespace std;

struct Interval{
    int start;
    int end;
    Interval() : start(0), end(0){}
    Interval(int s, int e) : start(s), end(e){}
};

bool cmp(Interval &l, Interval &r){
    return l.start < r.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        result.clear(); //because Leetcode run test in one go;

        sort(intervals.begin(), intervals.end(), cmp);
        for(int i = 0; i < intervals.size(); ++i){
            if(result.empty()) result.push_back(intervals[i]);
            else{
                if(intervals[i].start >= result.back().start
                   && intervals[i].start <= result.back().end)
                    result.back().end = max(intervals[i].end, result.back().end);//start overlap, use the max end
                else
                    result.push_back(intervals[i]);
            }
        }

        return result;
    }

private:
    vector<Interval> result;
};

int main()
{
    vector<Interval> in;
    in.push_back(Interval(1, 3));
    in.push_back(Interval(2, 6));
    in.push_back(Interval(8, 10));
    in.push_back(Interval(15, 18));

    Solution sln;
    vector<Interval> result = sln.merge(in);
    for(int i = 0; i < result.size(); ++i){
        cout<<result[i].start<<" "<<result[i].end<<endl;
    }
    return 0;
}

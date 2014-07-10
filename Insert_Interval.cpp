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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator it = intervals.begin();
        auto it_pre = it;
        while(it != intervals.end()){
            if(newInterval.end < it->start){
                if(it != it_pre)
                    it = intervals.erase(it_pre, it);//it_pre's pos won't change, still the x-th element

                intervals.insert(it, newInterval);
                return intervals;
            }else if(newInterval.start > it->end){
                it++;
                it_pre++;
                continue;
            }else{//overlap cases
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                it++;
            }
        }//end while

        if(it != it_pre) it = intervals.erase(it_pre, it);
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }

private:
    vector<Interval> result;
};

int main()
{
    vector<Interval> in;
    in.push_back(Interval(1, 3));
    in.push_back(Interval(5, 8));
    in.push_back(Interval(9, 10));
    Interval iv = Interval(2, 7);

    Solution sln;
    vector<Interval> result = sln.insert(in, iv);
    for(int i = 0; i < result.size(); ++i){
        cout<<result[i].start<<" "<<result[i].end<<endl;
    }
    return 0;
}

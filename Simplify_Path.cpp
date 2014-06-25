#include <iostream>
#include <vector>

using namespace std;

//more simplified code
string simplifyPath2(string path)
{
    typedef string::iterator SI;
    vector<string> dirs;
    for(SI i = path.begin(); i != path.end(); ){
        ++i;//move i to the next char to /
        SI j = find(i, path.end(), '/');
        string dir = string(i, j);
        cout<<dir <<endl;
        if(dir != "." && !dir.empty()){
            if(dir == ".."){
                if(!dirs.empty())
                    dirs.pop_back();
            }else dirs.push_back(dir);
        }
        i = j; //now i points to the end /,
    }

    string ret;
    if(dirs.empty())
        return "/";
    else{
        for(size_t i = 0; i < dirs.size(); ++i)
            ret = ret + "/" + dirs[i];
    }
    return ret;
}

string simplifyPath(string path) {
    vector<string> result;
    int l = 0, r = l;
    for(size_t i = 1; i < path.size(); ++i){
        if(path[i] != '/') r = i;
        else{
            string temp = path.substr(l+1, r-l);
            if(temp == "." || temp == ""){
                ;
            }else if (temp == ".."){
                if(!result.empty())
                    result.pop_back();
            }else{
                result.push_back(temp);
            }
            l = r + 1;
            r = l;
        }
    }

    string temp = path.substr(l+1, r-l);
    if(temp == "" || temp == ".")
        ;
    else if(temp == ".."){
        if(!result.empty())
            result.pop_back();
    }else{
        result.push_back(temp);
    }

    string ret;
    if(result.empty())
        return "/";
    else{
        for(size_t i = 0; i < result.size(); ++i){
            ret = ret + "/" + result[i];
        }
    }

    return ret;
}

int main()
{
    string s = "/../";
    cout<<endl<<"simplifyPath:"<< simplifyPath2(s)<<endl;
    return 0;
}

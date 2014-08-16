#include <iostream>
#include <cstdio>
using namespace std;

const int RES_MAX = 5;
int resource[RES_MAX];
int head = 0, tail = 0;
bool p_mutex = false;
bool c_mutex = false;

bool produce(int a){
    if(!p_mutex){
        p_mutex = true;
        tail %= RES_MAX;
        head %= RES_MAX;
        if((head + 1) == tail){
            cout<<"resource full!"<<endl;
            return false;
        }else{
            resource[head] = a;
            cout<<"produce: " <<resource[head]<<endl;
            head++;
            return true;
        }
        p_mutex = false;
    }
}

int consume(){
    if(!c_mutex){
        c_mutex = true;
        head %= RES_MAX;
        tail %= RES_MAX;
        if(head == tail){
            cout<<"resource empty"<<endl;
            return -1;
        }else{
            cout<<"consume: " <<resource[tail]<<endl;
            return resource[tail++];
        }
        c_mutex = false;
    }
}



int main()
{
    produce(1);
    produce(2);
    consume();
    consume();
    return 0;
}

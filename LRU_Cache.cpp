#include <iostream>
using namespace std;

class LRUCache
{
public:
    LRUCache(int capacity){
        this->capacity = capacity;
        memory = new CacheNode(-1);
        size = 0;
    }

    int get(int key){
        if(this->memory->next == NULL) return -1;

        CacheNode *tmp = memory->next;
        for(; tmp; tmp = tmp->next)
            if(tmp->key == key)
                return tmp->val;
        return -1;
    }

    //Input:2,[set(2,1),set(2,2),get(2),set(1,1),set(4,1),get(2)]
    //     Output:[1,1]
    //      Expected:[2,-1]
    void set(int key, int value){
        CacheNode *prev = memory;
        for(; prev && prev->next; prev = prev->next){
            if(prev->next->key == key)
                break;
        }

        if(prev->next == NULL){
            //key doesn't exist
            CacheNode *p = (CacheNode *)malloc(sizeof(CacheNode));
            p->key = key;
            p->val = value;
            //check the capacity
            if(this->size >= this->capacity){
                //delete the last one
                CacheNode *pre_tail = memory;
                while(pre_tail->next && pre_tail->next->next)
                    pre_tail = pre_tail->next;
                CacheNode *d = pre_tail->next;
                pre_tail->next = NULL;
                delete d;
            }
            p->next = memory->next;
            memory->next = p;
            this->size++;
        }else{
            //now prev point to the previous of the right node
            CacheNode *lru = prev->next;
            lru->val = value;
            prev->next = prev->next->next;
            lru->next = memory->next;
            memory->next = lru;
        }

        printMemory();
    }

    void printMemory(){
        cout<<"memory size: "<<this->size <<endl;
        cout<<"memory capacity: "<< this->capacity <<endl;
        CacheNode *tmp = memory->next;
        cout<<"key: ";
        for(; tmp; tmp = tmp->next){
            cout<<tmp->key << " ";
        }
        cout<<endl;

        tmp = memory->next;
        cout<<"value: ";
        for(; tmp; tmp = tmp->next){
            cout<<tmp->val << " ";
        }
        cout<<endl;

    }

private:
    struct CacheNode {
        int key;
        int val;
        CacheNode *next;
        CacheNode(int v) :key(v), val(v), next(NULL){}
    };

    CacheNode *memory;
    int capacity;
    int size;
};

int main()
{
    LRUCache my_cache = LRUCache(2);
    my_cache.set(2,1);
    my_cache.set(2,2);
    cout<<my_cache.get(2)<<endl;
    my_cache.set(1,1);
    my_cache.set(4,1);
    cout<<my_cache.get(2)<<endl;
    return 0;
}

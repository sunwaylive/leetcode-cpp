#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp
{
    bool operator()(const ListNode *l1, const ListNode *l2){
        return l1->val < l2->val;
    }
};

ListNode* mergeKLists(vector<ListNode *> &lists)
{
    int i;
    int size = lists.size();
    priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
    for(i = 0; i < size; i++){
        ListNode *tmp = lists[i];
        while(tmp != NULL){
            pq.push(tmp);
            tmp = tmp->next;
        }
    }

    //pop the list into a new merged one
    ListNode dummy(-1);
    ListNode *p = &dummy;
    while(!pq.empty()){
        ListNode *tmp = pq.top();
        p->next = tmp;
        p = p->next;
        pq.pop();
    }
    p->next = NULL;
    return dummy.next;
}

ListNode* generateList(int size)
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *cur = head;
    for(int i = 0; i < size; i++){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->val = i;//rand() % 100;
    p->next = NULL;
    cur->next = p;
    cur = cur->next;
    }
    return head->next;
}

void print_list(ListNode *l)
{
    ListNode *tmp = l;
    while(tmp != NULL){
        cout<< tmp->val <<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

int main()
{
    ListNode *l1 = generateList(20);
    ListNode *l2 = generateList(10);
    ListNode *l3 = generateList(4);
    vector<ListNode *> l;
    l.push_back(l1);
    l.push_back(l2);
    l.push_back(l3);
    ListNode *re = mergeKLists(l);
    print_list(re);
    return 0;
}

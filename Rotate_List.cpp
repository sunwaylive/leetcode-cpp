#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* findPos(ListNode* head, int p)
{
    ListNode *tmp = head;
    for(int i = 1; i < p; ++i){
        tmp = tmp->next;
    }
    return tmp;
}

ListNode* rotateList(ListNode *head, int k)
{
    if (!head) return head;
    //make a circle
    ListNode *tmp = head;
    int size = 1;
    while(tmp->next != NULL){
        size++;
        tmp = tmp->next;
    }

    k = k % size;
    if(k == 0) return head;

    ListNode *tail = tmp;
    ListNode *new_head = findPos(head, size - k + 1);
    ListNode *prev = findPos(head, size - k);
    tail->next = head;
    prev->next = NULL;
    return new_head;
}

ListNode* generateList(int size)
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *cur = head;

    for(int i = 0; i < size-1; i++){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    srand((unsigned)time(NULL));
    p->val = rand() % 10;
    p->next = NULL;
    cur->next = p;
    cur = cur->next;
    }

    ListNode *manual = (ListNode*) malloc(sizeof(ListNode));
    manual->val = 1;
    manual->next = NULL;
    cur->next = manual;
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
    ListNode *l2 = generateList(2);
    print_list(l2);

    ListNode *re = rotateList(l2, 2);
    print_list(re);
    return 0;
}

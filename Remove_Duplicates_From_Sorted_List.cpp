#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode *head)
{
    ListNode *p, *q, *pre;
    for(p = head; p != NULL; p = p->next){
        for(pre = p, q = p->next; q != NULL;){
            if(p->val == q->val){
                pre->next = q->next;
                ListNode *tmp = q;
                q = q->next;
                delete tmp;
            }else{
                pre = q;
                q = q->next;
            }
        }
    }

    return head;
}

ListNode* generateList(int size)
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *cur = head;
    for(int i = 0; i < size; i++){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    // srand((unsigned)time(NULL));
    p->val = rand() % 10;
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
    ListNode *l2 = generateList(10);
    print_list(l2);

    ListNode *re = deleteDuplicates(l2);
    print_list(re);
    return 0;
}

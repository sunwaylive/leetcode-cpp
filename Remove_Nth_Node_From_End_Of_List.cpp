#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode *head, int n)
{
    if(!head) return head;

    ListNode dummy(-1);
    dummy.next = head;

    ListNode *first = &dummy, *second_prev = &dummy;
    for (int i = 0; i <= n; ++i)
        first = first->next;

    for(; first; first = first->next, second_prev = second_prev->next)
        ;
    second_prev->next = second_prev->next->next;
    return dummy.next;
}

ListNode* generateList(int size)
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *cur = head;

    for(int i = 0; i < size-1; i++){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    //srand((unsigned)time(NULL));
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

    ListNode *re = removeNthFromEnd(l2, 2);
    print_list(re);
    return 0;
}

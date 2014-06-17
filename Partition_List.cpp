#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//O(n^2) solution
ListNode* partition(ListNode* head, int x)
{
    ListNode dummy(INT_MIN);
    dummy.next = head;

    ListNode *cur = &dummy;
    ListNode *p, *q;
    while(cur->next != NULL){
        for(q = p, p = cur->next; p != NULL && p->val >= x; q = p, p = p->next)
            ;
        if(p != NULL){
            q->next = p->next;
            p->next = cur->next;
            cur->next = p;
            cur = cur->next;
        }else break;
    }
    return dummy.next;
}

//space complexity: O(1), time complexity: O(n)
ListNode* partition2(ListNode *head, int x)
{
    ListNode left_dummy(-1);
    ListNode right_dummy(-1);

    ListNode *left_cur = &left_dummy;
    ListNode *right_cur = &right_dummy;

    for(ListNode *cur = head; cur; cur = cur->next){
        if(cur->val < x) { left_cur->next = cur; left_cur = left_cur->next; }
        else { right_cur->next = cur; right_cur = right_cur->next; }
   }

    left_cur->next = right_dummy.next;
    right_cur->next = NULL;

    return left_dummy.next;
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

    ListNode *re = partition2(l2, l2->val);
    print_list(re);
    return 0;
}

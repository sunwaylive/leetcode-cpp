#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode *);

ListNode* findMiddle(ListNode *head)
{
    if(!head || !head->next) return head;

    ListNode *fast = head, *slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

ListNode* reverse(ListNode *head)
{
    if(!head || !head->next) return head;

    ListNode *p, *q, *r;
    for(p = head, q = p->next, r = q->next; q; ){
        q->next = p;
        p = q;
        q = r;
        r = (r == NULL) ? NULL : r->next;
    }

    head->next = NULL;
    return p;
}

void reorder(ListNode *head){
    if(!head || !head->next) return ;

    ListNode *middle = findMiddle(head);
    ListNode *second_half = middle->next;
    middle->next = NULL;
    ListNode *first_half = head;

    second_half = reverse(second_half);

    ListNode dummy(-1);
    ListNode *p = &dummy;
    while(first_half && second_half){
        p->next = first_half;
        first_half = first_half->next;
        p = p->next;

        p->next = second_half;
        second_half = second_half->next;
        p = p->next;
    }

    p->next = (first_half == NULL) ? second_half : first_half;
}

ListNode* generateList(int size)
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *cur = head;
    for(int i = 0; i < size; i++){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->val = rand() % 100;
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
    ListNode *l1 = generateList(5);
    print_list(l1);
    reorder(l1);
    print_list(l1);
    return 0;
}

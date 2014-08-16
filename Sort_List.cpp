#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sortList(ListNode *head)
{
    if(head == NULL || head->next ==NULL) return head;

    ListNode *fast = head, *slow = head;
    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    //cut the link list into two parts
    fast = slow;
    slow = slow->next;
    fast->next = NULL;

    head = sortList(head);
    slow = sortList(slow);

    ListNode dummy(-1);
    ListNode *p = &dummy;
    while(head != NULL && slow != NULL){
        if(head->val < slow->val) { p->next = head; p = p->next; head = head->next; }
        else{ p->next = slow; p = p->next; slow = slow->next; }
    }
    p->next = (head == NULL) ? slow : head;
    return dummy.next;
}

ListNode* generateList(int size)
{
    ListNode dummy(-1);
    ListNode *p = &dummy;
    for(int i = 0; i < size; ++i){
        int val = rand() % 100;
        ListNode *t = new ListNode(val);
        p->next = t;
        p = t;
    }
    return dummy.next;
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
    print_list(l1);
    ListNode *l2 = generateList(10);
    print_list(l2);
    ListNode *re2 = sortList(l1);
    print_list(re2);
    return 0;
}

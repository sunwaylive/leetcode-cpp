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

    //merge the two sorted lists
    ListNode dummy(-1);
    ListNode* p = &dummy;
    for(; head != NULL && slow != NULL; p = p->next){
        if(head->val < slow->val) { p->next = head; head = head->next; }
        else { p->next = slow; slow = slow->next; }
    }
    p->next = (head == NULL) ? slow : head;
    return dummy.next;
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
    ListNode *l1 = generateList(20);
    print_list(l1);
    ListNode *l2 = generateList(10);
    print_list(l2);
    ListNode *re = mergeTwoLists(l1, l2);
    ListNode *re2 = sortList(re);
    print_list(re2);
    return 0;
}

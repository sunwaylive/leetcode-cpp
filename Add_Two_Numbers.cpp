#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode dummy(-1);
    ListNode *p = &dummy;
    int carry = 0;
    for(ListNode *pa = l1, *pb = l2;
        pa != NULL || pb != NULL;
        pa = (pa == NULL) ? NULL : pa->next, pb = (pb == NULL) ? NULL : pb->next)
    {
        const int ipa = (pa == NULL) ? 0 : pa->val;
        const int ipb = (pb == NULL) ? 0 : pb->val;
        int value = ipa + ipb + carry;
        carry = value / 10;
        p->next = new ListNode(value % 10);
        p = p->next;
    }

    if(carry > 0) { p->next = new ListNode(carry); }
    return dummy.next;
}

ListNode* generateList(int size)
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    ListNode *cur = head;
    for(int i = 0; i < size; i++){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    srand((unsigned)time(NULL));
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
    ListNode *l1 = generateList(5);
    print_list(l1);
    ListNode *l2 = generateList(5);
    print_list(l2);
    ListNode *re = addTwoNumbers(l1, l2);
    print_list(re);
    return 0;
}

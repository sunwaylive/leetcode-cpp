#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicatesSecond(ListNode *head)
{
    if(!head) return head;

    ListNode dummy(head->val - 1);
    dummy.next = head;
    ListNode *prev = &dummy, *cur = prev->next;
    while(cur != NULL){
        bool is_duplicated = false;
        while(cur->next != NULL && cur->next->val == cur->val){
            is_duplicated = true;
            ListNode *tmp = cur;
            prev->next = cur->next;
            cur = cur->next;
            delete tmp;
        }
        if(is_duplicated){
            ListNode *tmp = cur;
            prev->next = cur->next;
            cur = cur->next;
            delete tmp;
        }else{
            prev->next = cur;
            prev = prev->next;
            cur = cur->next;
        }
    }
    return dummy.next;
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
    ListNode *l2 = generateList(10);
    print_list(l2);

    ListNode *re = deleteDuplicatesSecond(l2);
    print_list(re);
    return 0;
}

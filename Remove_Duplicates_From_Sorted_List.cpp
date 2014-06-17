#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//method 1: works for all link lists
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

//method 2: only works for sorted link list
ListNode* deleteDuplicates2(ListNode *head)
{
    if(head == NULL) return head;

    ListNode *prev, *cur;
    for(prev = head, cur = prev->next; cur != NULL;){
        if(prev->val == cur->val){
            prev->next = cur->next;
            ListNode *tmp = cur;
            cur = cur->next;
            delete tmp;
        }else{
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

//method3: only works for sorted link list
void recurDelete(ListNode *prev, ListNode *cur)
{
    if(cur == NULL) return;

    if(prev->val == cur->val){
        prev->next = cur->next;
        delete cur;
        recurDelete(prev, prev->next);
    }else{ recurDelete(prev->next, cur->next); }
}

ListNode* deleteDuplicatesRecur(ListNode *head)
{
    if(head == NULL) return head;

    ListNode dummy(head->val - 1);//different with head->val is ok
    dummy.next = head;

    recurDelete(&dummy, head);
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
    ListNode *l2 = generateList(10);
    print_list(l2);

    ListNode *re = deleteDuplicates2(l2);
    print_list(re);
    return 0;
}

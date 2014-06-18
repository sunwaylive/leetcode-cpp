#include <iostream>
using namespace std;

struct RandomListNode{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL){}
};

RandomListNode* copyRandomList(RandomListNode *head)
{
    //copy new list nodes in the original list
    for(RandomListNode *cur = head; cur != NULL; ){
        RandomListNode *new_cur = new RandomListNode(cur->label);
        new_cur->next = cur->next;
        cur->next = new_cur;
        cur = new_cur->next;
    }

    //point the random pointer to the right node
    for(RandomListNode *cur = head; cur != NULL; cur = cur->next->next)
        if(cur->random != NULL)
            cur->next->random = cur->random->next;

    //split the list
    RandomListNode dummy(-1);
    RandomListNode *new_head = &dummy;
    for(RandomListNode *cur = head; cur != NULL; ){
        new_head->next = cur->next;
        new_head = new_head->next;
        cur->next = cur->next->next;
        cur = cur->next;
    }
    return dummy.next;
}

RandomListNode* generateRandomList(int size)
{
    RandomListNode *head = (RandomListNode*)malloc(sizeof(RandomListNode));
    RandomListNode *cur = head;

    for(int i = 0; i < size-1; i++){
    RandomListNode *p = (RandomListNode*)malloc(sizeof(RandomListNode));
    //srand((unsigned)time(NULL));
    p->label = rand() % 10 + 1;
    p->next = NULL;
    p->random = NULL;
    cur->next = p;
    cur = cur->next;
    }

    RandomListNode *manual = (RandomListNode*) malloc(sizeof(RandomListNode));
    manual->label = 1;
    manual->next = NULL;
    manual->random = NULL;
    cur->next = manual;
    return head->next;
}

void print_list(RandomListNode *l)
{
    RandomListNode *tmp = l;
    while(tmp != NULL){
        cout<< tmp->label <<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

int main()
{
    RandomListNode *l2 = generateRandomList(4);
    print_list(l2);

    RandomListNode *re = copyRandomList(l2);
    print_list(re);
    return 0;
}

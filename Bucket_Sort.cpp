#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

void bucket_sort(int keys[], int size, int bucket_size)
{
    //build bucket table
    ListNode **bucket_table = (ListNode**)malloc(bucket_size * sizeof(ListNode*));
    for(int i = 0; i < bucket_size; ++i)
        bucket_table[i] = new ListNode(keys[i]);

    //traverse keys and add to the corresponding bucket
    for(int j = 0; j < size; ++j)
    {
        ListNode *node = new ListNode(keys[j]);
        int b_idx = keys[j] / 10;
        //get the head node of the bucket
        ListNode *tmp = bucket_table[b_idx];
        //find the position
        while(tmp->next != NULL && tmp->next->val < keys[j])
            tmp = tmp->next;

        node->next = tmp->next;
        tmp->next = node;
        (bucket_table[b_idx]->val)++;
    }

    //print out
    for(int b = 0; b < bucket_size; ++b){
        for(ListNode *l = bucket_table[b]->next; l != NULL; l = l->next){
            cout<<l->val<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    int raw[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int size = sizeof(raw) / sizeof(raw[0]);
    bucket_sort(raw, size, 10);
    return 0;
}

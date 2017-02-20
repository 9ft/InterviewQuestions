#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL) return NULL;

        RandomListNode *newHead = new RandomListNode(pHead->label);
        RandomListNode *pHead1=NULL, *pHead2=NULL;

        // 上链，使新旧链表成之字形链接
        for(pHead1=pHead,pHead2=newHead;pHead1;){
            RandomListNode* tmp = pHead1->next;
            pHead1->next = pHead2;
            pHead2->next = tmp;

            // next
            pHead1 = tmp;
            if(tmp) pHead2 = new RandomListNode(tmp->label);
            else pHead2 = NULL;
        }

        // 更新新链表的random指针
        for(pHead1=pHead,pHead2=newHead;pHead1;){
            if(pHead1->random) pHead2->random = pHead1->random->next;
            else pHead2->random = NULL;

            pHead1 = pHead2->next;
            if(pHead1) pHead2 = pHead1->next;
            else pHead2 = NULL;
        }

        // 脱链，更新各链表的next指针
        for(pHead1=pHead,pHead2=newHead;pHead1;){
            pHead1->next = pHead2->next;
            if(pHead1->next) pHead2->next = pHead1->next->next;
            else pHead2->next = NULL;

            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }

        return newHead;
    }
};

int main(int argc, char const* argv[])
{

    return 0;
}

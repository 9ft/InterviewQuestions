#include <iostream>
#include <map>

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

        map<RandomListNode*,RandomListNode*> m;
        RandomListNode* pHead1 = pHead;
        RandomListNode* pHead2 = new RandomListNode(pHead1->label);
        RandomListNode* newHead = pHead2;
        m[pHead1] = pHead2;
        while(pHead1){
            if(pHead1->next) pHead2->next = new RandomListNode(pHead1->next->label);
            else pHead2->next = NULL;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
            m[pHead1] = pHead2;
        }

        pHead1 = pHead;
        pHead2 = newHead;
        while(pHead1){
            pHead2->random = m[pHead1->random];
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

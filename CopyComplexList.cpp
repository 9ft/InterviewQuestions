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
    RandomListNode* Clone(RandomListNode* pHead){
        if(!pHead) return NULL;
        RandomListNode *preHead = new RandomListNode(0),
                       *newTail = preHead, *p = pHead;
        while(p){
            RandomListNode *newNode = new RandomListNode(p->label);
            newTail->next = newNode;
            newTail = newNode;
            p = p->next;
        }
        RandomListNode *newP = preHead->next;
        p = pHead;
        while(p){
            if(p->random){
                RandomListNode *pTmp = p,
                    *newPTmp = newP;
                while(pTmp != p->random){
                    pTmp = pTmp->next;
                    newPTmp = newPTmp->next;
                }
                newP->random = newPTmp;
            }
            newP = newP->next;
            p = p->next;
        }
        return preHead->next;
    }
};

int main(int argc, char const* argv[])
{

    return 0;
}

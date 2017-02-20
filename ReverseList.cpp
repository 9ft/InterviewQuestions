#include<iostream>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead || !pHead->next){
            return pHead;
        }
        ListNode *p = pHead->next;
        pHead->next = NULL;
        while(p){
            ListNode *pNext = p->next;
            p->next = pHead;
            pHead = p;
            p = pNext;
        }
        return pHead;
    }
};

int main(int argc, char const* argv[])
{

    return 0;
}

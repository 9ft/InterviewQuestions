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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        ListNode *preHead = new ListNode(INT_MIN);
        ListNode *tail = preHead;
        while(pHead1 && pHead2){
            if(pHead1->val < pHead2->val){
                tail->next = pHead1;
                pHead1 = pHead1->next;
            }else{
                tail->next = pHead2;
                pHead2 = pHead2->next;
            }
            tail = tail->next;
        }
        tail->next = pHead1 ? pHead1 : pHead2;

        return preHead->next;
    }
};

int main(int argc, char const* argv[])
{

    return 0;
}

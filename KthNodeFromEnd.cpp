#include <iostream>

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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *pfirst = pListHead;
        ListNode *pseconde = pListHead;
        if (pListHead == NULL || k == 0)
            return NULL;
        for(int i = 1; i < k; i++){
            if(!(pfirst->next)){
                return NULL;
            }
            pfirst = pfirst->next;
        }
        while (pfirst->next != NULL){
            pfirst = pfirst->next;
            pseconde = pseconde->next;
        }
        return pseconde;

    }
};

int main(int argc, char const* argv[])
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    Solution sol;
    //head = sol.FindKthToTail(head, argc==2 ? stoi(argv[1]) : 3);
    head = sol.FindKthToTail(NULL, argc==2 ? stoi(argv[1]) : 3);

    if(head){
        cout << head->val;
    }else{
        cout << "null";
    }


    return 0;
}

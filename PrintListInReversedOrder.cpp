#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> printListFromTailToHead_iterate(ListNode* head) {
        vector<int> result;
        stack<ListNode *> stack;
        while(head){
            stack.push(head);
            head = head->next;
        }
        while(!stack.empty()){
            result.push_back(stack.top()->val);
            stack.pop();
        }
        return result;
    }

    vector<int> printListFromTailToHead_recursive(ListNode* head) {
        vector<int> result;
        printListFromTailToHead_recursive(head, result);
        return result;
    }
private:
    void printListFromTailToHead_recursive(ListNode *head, vector<int> &result){
        if(head->next){
            printListFromTailToHead_recursive(head->next, result);
        }
        result.push_back(head->val);
    }
};

int main(int argc, char const* argv[])
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution sol;
    vector<int> result = sol.printListFromTailToHead_iterate(head);
    for(int &i : result){
        cout << i << " ";
    }
    cout << endl;
    result = sol.printListFromTailToHead_recursive(head);
    for(int &i : result){
        cout << i << " ";
    }
    return 0;
}

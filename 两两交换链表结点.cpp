/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = new ListNode(0);//开辟内存空间存入数据0
        ans->next = head;
        ListNode* temp = ans;
        while(temp->next != nullptr && temp->next->next != nullptr)
        {
            ListNode* a = temp->next;
            ListNode* b = temp->next->next;
            temp->next = b;
            a->next = b->next;//a->next = b->next；b->next = a；这两行不可以写反，否则发生冲突，因为下一行对b->next进行了更新，不可提前赋值给老的a
            b->next = a;
            temp = a;
        }
        return ans->next;
    }
};
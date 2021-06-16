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
    pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* tail)
    {
        ListNode* pre = tail->next;//nullptr
        ListNode* curr = head;
        while(tail != pre)
        {
            ListNode* next = curr->next;//保存当前节点的下一个结点
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return {tail, head};//一个链表反转，头变尾，尾变头
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* hair = new ListNode(0);//创建伪头部结点，指针不会变
        hair->next = head;
        ListNode* pre = hair;

        while(head)
        {
            ListNode* tail = pre;//必须写在循环里面，因为每次都需要更新tail到下一组
            for(int i = 0; i < k; i++)
            {
                tail = tail->next;//一直往后移动
                if(!tail)//如果进入了if语句，说明不到k个结点，此组数据不算，就不反转
                {
                    return hair->next;//直接返回即可
                }
            }
            ListNode* next = tail->next;//下一组的开始结点
            tie(head, tail) = reverseList(head, tail);//tie()函数获取pair对象的数据
            pre->next = head;//新的链表头部
            tail->next = next;
            pre = tail;
            head = tail->next;
        }
        return hair->next;
    }
};
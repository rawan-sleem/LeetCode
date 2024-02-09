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
// Time O(n)
// space O(1)
// Idea of  iterate through the linked list and remove any duplicates encountered by the next pointers
/* trace => input 1 1 2 3  3 
cur_node = 1 , next_node=1 , cur_node == next_node so now cur_node =2 
Inside the loop:
next_node points to the node with value 3.
Since the values are not equal, cur_node is moved to the next node.
Now, cur_node points to the first node with value 3.
Inside the loop:
next_node points to the second node with value 3.
Since the values are equal, the next node is skipped.
The loop ends as cur_node becomes null.
Finally, the modified linked list is returned
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // pointer to the head 
        ListNode* cur_node = head;
        // not reach to the last node 
        while (cur_node && cur_node->next) {
            // next node of the current 
            ListNode* next_node = cur_node->next;
            // if the value of the current == the value of the next 
            if (cur_node->val == next_node->val)
            // If the values are equal, it skips the next node by updating the next pointer of the current node to point to the node after the next node
                cur_node->next = next_node->next;
            else
            // if the current not equal the next 
                cur_node = next_node;
        }
        return head;// return the pointer of the head it modified 
    }
};
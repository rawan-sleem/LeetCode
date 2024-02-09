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
//  Time O(n)
// Space O(1)
// Idea =>achieved by first finding the size of the linked list and then traversing the list again to find the node that will become the new tail of the rotated list. After breaking the circular link, the rotated list is obtained.
/* trace Input: head = [1,2,3,4,5], k = 2 Output: [4,5,1,2,3] 
size =5 , node it indicit now to the last node with 5
connect the last node's next pointer to the head 
 */
class Solution {
public:
 ListNode *rotateRight(ListNode *head, int k) 
     {
        //  check if it empty || has only one node || k==0
        if(head == NULL || head->next == NULL||k==0) return head;
        // node to travesal to the linked list  
        ListNode* node = head;
        // size to count the nodes in the linkedlist 
        int size =1;
        // not reach to the end node 
        while(node->next != NULL)
        {
            // number of nodes increasing 
            size++;
            // move the node to the next node 
            node = node->next;
        }
        
        //loop the list
        node->next=head;
        
        //handle the case if  k>size
        k = k%size;
        
        //find the node to break the loop at
        while(--size >= k)
        {
            node=node->next;
        }
        
        ListNode* first = node->next;
        node->next=NULL;
        
        return first;
    }
};
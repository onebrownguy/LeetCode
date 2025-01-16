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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node and a current pointer
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        // Traverse while both lists have nodes
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                curr->next = list1;  // Attach the smaller node
                list1 = list1->next;  // Move list1 forward
            } else {
                curr->next = list2;  // Attach the smaller node
                list2 = list2->next;  // Move list2 forward
            }
            curr = curr->next;  // Move current pointer
        }

        // Attach any remaining nodes from list1 or list2
        if (list1 != nullptr) {
            curr->next = list1;
        } else {
            curr->next = list2;
        }

        // Return the merged list starting from dummy->next
        ListNode* mergedList = dummy->next;
        delete dummy;  // Clean up dummy node to prevent memory leak
        return mergedList;
    }
};
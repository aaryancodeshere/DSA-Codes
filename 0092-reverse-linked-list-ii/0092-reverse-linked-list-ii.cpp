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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> nums;
        int l = left,r = right,count=1;
        ListNode* ptr = head;
        while(count<l && ptr && ptr->next){
            ptr = ptr->next;
            count++;
        }
        while(count<=r && ptr->next){
            nums.push_back(ptr->val);
            ptr = ptr->next;
            count++;
        }
        
        int n = nums.size();
        ptr = head;
        count=1;
        while(count<l && ptr && ptr->next){
            ptr= ptr->next;
            count++;
        }
        int i=0;
        while(count<=r && ptr && ptr->next){
            ptr->val = nums[n-1-i];
            ptr = ptr->next;
            count++;
            i++;
        }

        return head;

    }
};
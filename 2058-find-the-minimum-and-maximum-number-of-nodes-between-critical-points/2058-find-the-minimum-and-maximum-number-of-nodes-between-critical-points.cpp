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
    vector<int> nodesBetweenCriticalPoints(ListNode* head){
        int ind=2;
        ListNode*prev=head;
        head=head->next;
        vector<int>ans;
        while(head!=NULL && head->next!=NULL){
            if(head->val>prev->val && head->val>head->next->val) ans.push_back(ind);
            else if(head->val<prev->val && head->val<head->next->val) ans.push_back(ind);
            prev=head;
            head=head->next;
            ind++;
        }
        if(ans.empty() || ans.size()==1) return {-1,-1};
        int mini=INT_MAX;
        for(int i=1;i<ans.size();i++){
            mini=min(mini,ans[i]-ans[i-1]);
        }
        return {mini,ans[ans.size()-1]-ans[0]};
    }
};
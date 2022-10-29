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
    void insert(ListNode* &head, int val){
        ListNode* newNode = new ListNode(val);
        if(head==NULL){
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next = newNode;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*a;
        ListNode*ans;
        
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        if(list1->val<=list2->val){
            ans = list1;
            list1 = list1->next;
        }
        else{
            ans = list2;
            list2 = list2->next;
        }
        ListNode*temp = ans;
       
        int val;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                val = list1->val;
                list1 = list1->next;
            }
            else{
                val = list2->val;
                list2 = list2->next;
            }
            a = new ListNode(val);
            ans->next = a;
            ans = ans->next;
        }
        while(list1!=NULL){
            a = new ListNode(list1->val);
            ans->next = a;
            ans = ans->next;
            list1 = list1->next;
        }
        while(list2!=NULL){
            a = new ListNode(list2->val);
            ans->next = a;
            ans = ans->next;
            list2=list2->next;
        }
        return temp;
    }
};

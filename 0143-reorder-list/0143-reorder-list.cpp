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
    void reorderList(ListNode* head) {
         if (!head || !head->next) return; 
        stack<ListNode*>st;
        ListNode* slow = head ;
        ListNode* fast = head ;
        ListNode* prev = NULL ;
        while( fast != NULL && fast->next != NULL ){
            prev = slow ;
            slow = slow->next;
            fast = fast->next->next;
           
        }
           prev->next = NULL ;

         ListNode* temp = slow ;
         while( temp ){
            
            st.push(temp);
            temp = temp -> next ;
         }
         ListNode* dev = head ;
         
         ListNode* tail = NULL ;
        while(!st.empty()){
             
             ListNode* r = st.top();
             st.pop();
            if(dev != NULL){
                ListNode* nex = dev ->next ;
                r->next = nex ;
                dev-> next = r ;
                dev = nex ;
                tail = r ;
             }
             else{
                tail -> next = r ;
                r->next = NULL; 
                 tail = r ;
             }
        }
        
    }
};
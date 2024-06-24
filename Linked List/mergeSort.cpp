//Merge Sort in linked list
//Time Complexity O(n log n)
//Space Complexity O(log n)
//Solved on leetcode

// Definition for singly-linked list.
#define NULL nullptr
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL )  return list2;
        if(list2 == NULL )  return list1;

        //Both are not null lets join them 
        ListNode* ans = NULL;
        ListNode* temp = NULL;
        if(list1->val < list2->val) {
            ans = list1;
            list1 = list1->next;
        }else{
            ans = list2;
            list2 = list2->next;
        }
        temp = ans ;
        
        while(list1 !=NULL &&list2!=NULL){
            if(list1->val<list2->val){
                temp->next = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        while(list1!=NULL){
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
        }
        while(list2!=NULL){
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
        }
        //temp = NULL;
        return ans;
        
    }
    ListNode* mergeSort(ListNode* head){
        //Merge Sort Algorithm
        //Base Case
        if(head==NULL ||head->next==NULL)    return head;
        //Step 1: Find mid
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        //slow indicated mid
        ListNode* left ;
        ListNode* right ;
        prev -> next = nullptr;
        left = mergeSort(head);
        right= mergeSort(slow);

        //Now merge these subarrays
        ListNode* ans = mergeTwoLists(left,right);
        return ans;

    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
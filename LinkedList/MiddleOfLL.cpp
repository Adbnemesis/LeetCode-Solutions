 ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp   = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        temp = head;
       count/=2;
        
        while(count--){
            temp = temp->next;
        }
        return temp;
        
        
    }

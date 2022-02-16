class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> m;
      
        Node* trav = head;
        Node* temp;
        
        
        while(trav!=NULL){
            temp = new Node(trav->val);
            m[trav] = temp;
            trav = trav->next;
            
        }
        trav = head;
        while(trav){
            temp = m[trav];
            temp->next = m[trav->next];
            temp->random = m[trav->random];
            
            trav = trav->next;
        }
        return m[head];
    }
};

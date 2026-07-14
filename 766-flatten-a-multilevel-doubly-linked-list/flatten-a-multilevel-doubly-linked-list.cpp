/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;

        while (curr != NULL) {
            if (curr->child != NULL) {

                Node* front = curr->next;
                curr->next = curr->child;
                Node* temp = flatten(curr->child);
                curr->child = NULL;
                temp->prev = curr;

                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = front;
                if (front != NULL) {
                    front->prev = temp;
                }
            }
            curr = curr->next;
        }

        return head;
    }
};
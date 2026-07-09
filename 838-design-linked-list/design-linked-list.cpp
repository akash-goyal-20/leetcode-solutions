class MyLinkedList {
public:
    ListNode* head;

    MyLinkedList() {
        head = new ListNode(-1);
    }

    int get(int index) {
        ListNode* temp = head->next;
        int cnt = 0;

        while (temp != NULL) {
            if (cnt == index)
                return temp->val;

            cnt++;
            temp = temp->next;
        }

        return -1;
    }

    void addAtHead(int val) {
        ListNode* node = new ListNode(val,head->next);
        head->next = node;
    }

    void addAtTail(int val) {
        ListNode* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new ListNode(val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0)
            return;

        ListNode* temp = head;
        int cnt = -1;

        while (temp != NULL) {
            if (cnt == index - 1) {
                ListNode* node = new ListNode(val);
                node->next = temp->next;
                temp->next = node;
                return;
            }

            cnt++;
            temp = temp->next;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0)
            return;

        ListNode* temp = head;
        int cnt = -1;

        while (temp != NULL) {
            if (cnt == index - 1) {
                if (temp->next == NULL)
                    return;

                ListNode* del = temp->next;
                temp->next = del->next;
                delete del;
                return;
            }

            cnt++;
            temp = temp->next;
        }
    }
};
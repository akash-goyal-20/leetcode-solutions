class CustomStack {
public:
    int maxSize;
    stack<int> st;
    CustomStack(int maxSize) { this->maxSize = maxSize; }

    void push(int x) {
        if (st.size() < maxSize) {
            st.push(x);
        }
    }

    int pop() {
        if (!st.empty()) {
            int x = st.top();
            st.pop();
            return x;
        }
        return -1;
    }

    void increment(int k, int val) {
        stack<int> temp;
        int cnt = 0;
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        while (!temp.empty()) {
            if (cnt < k) {
                st.push(temp.top() + val);
                temp.pop();
                cnt++;
            } else {
                st.push(temp.top());
                temp.pop();
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
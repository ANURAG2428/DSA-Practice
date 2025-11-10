class MinStack {
public:
    stack<long long> st;  // stack bana liya
    long long mini;       // current minimum store karne ke liye

    MinStack() {
        while (!st.empty()) st.pop(); // stack clear kar diya (optional)
        mini = INT_MAX;               // initially min bohot bada
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        } else {
            if (val < mini) {
                // encode kar rahe hain taaki purana min yaad rahe
                st.push(2LL * val - mini);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long topVal = st.top();
        st.pop();

        if (topVal < mini) {
            // iska matlab encoded value thi, to purana min wapas lao
            mini = 2LL * mini - topVal;
        }
    }

    int top() {
        long long topVal = st.top();
        if (topVal < mini) {
            // encoded value thi, matlab actual top == mini
            return (int)mini;
        }
        return (int)topVal;
    }

    int getMin() {
        return (int)mini;
    }
};

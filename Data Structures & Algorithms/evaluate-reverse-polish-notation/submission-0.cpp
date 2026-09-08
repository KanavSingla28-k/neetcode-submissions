class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        set<string> op;
        op.insert("+");
        op.insert("-");
        op.insert("*");
        op.insert("/");

        for (string c : tokens) {

            if (!op.count(c)) {
                st.push(stoi(c));
            }
            else {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                if (c == "+")
                    st.push(a + b);
                else if (c == "-")
                    st.push(b - a);
                else if (c == "*")
                    st.push(a * b);
                else if (c == "/")
                    st.push(b / a);
            }
        }

        return st.top();
    }
};
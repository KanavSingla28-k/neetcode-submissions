class Solution {
public:
    bool isValid(string s) {
        set<char> open;
        open.insert('(');
        open.insert('{');
        open.insert('[');

        int op = 0, close = 0;
        for (char c: s){
            if (open.count(c)) op++;
            else close++;
        }

        if (op != close) return false;

        stack<char> st;

        for (char c: s){
            if (st.empty() && !open.count(c)) return false;

            if (open.count(c)) st.push(c);

            else if (!open.count(c)){
                if (c == ')' && st.top() == '(') st.pop();
                else if (c == '}' && st.top() == '{') st.pop();
                else if (c == ']' && st.top() == '[') st.pop();
            }
        }

        return st.empty();
    }
};

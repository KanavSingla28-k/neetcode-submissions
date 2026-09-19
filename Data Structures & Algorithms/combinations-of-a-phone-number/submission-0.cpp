class Solution {
public:

    void backtrack(const string& digits, const vector<string>& mapping, string& current, int index, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        string letters = mapping[digits[index] - '2'];
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, mapping, current, index+1, result);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
    
        vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string current;
        backtrack(digits, mapping, current, 0, result);
        return result;
    }
};
class Solution {
public:

    string encode(vector<string>& strs) {
        string hash = "";

        for (string s:strs){
            hash += s;
            hash += "|||";
        }

        return hash;
    }

    vector<string> decode(string s) {
        vector<string> result;
        size_t pos = 0, prev = 0;
        size_t len = 3;

        while ((pos = s.find("|||", prev)) != string::npos) {

            if (pos == 0){
                result.push_back("");
            }

            if (pos > prev) {
                result.push_back(s.substr(prev, pos - prev));
            }
            prev = pos + len; 
        }

        if (prev < s.size()) {
            result.push_back(s.substr(prev));
        }

        return result;
    }
};

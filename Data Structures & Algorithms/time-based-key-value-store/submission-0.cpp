class TimeMap {
public:
unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";

        vector<pair<int, string>>& v = mp[key];

        string ans = "";

        int l = 0, r = v.size()-1;

        while (l<=r){
            int mid = l+(r-l)/2;

            if (v[mid].first<=timestamp){
                ans = v[mid].second;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans;
    }
};

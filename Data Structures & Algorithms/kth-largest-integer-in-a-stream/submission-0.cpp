class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int cap;
    int size;
    KthLargest(int k, vector<int>& nums) {
        cap = k;

        int n = nums.size();
        int i = 0;
        if (cap<n){
            for (i; i<cap; i++){
                pq.push(nums[i]);
            }
            for (i; i<n; i++){
                if (pq.top()<nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            size = cap;
        }
        else {
            for (i; i<n; i++){
                pq.push(nums[i]);
            }
            size = n;
        }
    }
    
    int add(int val) {
        if (size == cap){
            if (val > pq.top()){
                pq.pop();
                pq.push(val);
            }
        }
        else {
            pq.push(val);
            size++;
        }
        return pq.top();
    }
};

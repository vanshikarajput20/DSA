class Solution {
public:
    
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int maxi = INT_MIN, mini = INT_MAX;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }

        unordered_set<int> st (nums.begin(), nums.end());

        for(int i = mini; i < maxi; i++){
            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }
    
        return ans;
    }
};
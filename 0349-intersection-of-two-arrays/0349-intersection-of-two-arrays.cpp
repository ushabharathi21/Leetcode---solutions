class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> ans;

        for(int i:nums1){
            m[i] = 1;
        }

        for(int i:nums2){
            if(m[i]==1){
                ans.push_back(i);
                m[i] = 0;
            }
        }
        return ans;
    }
};
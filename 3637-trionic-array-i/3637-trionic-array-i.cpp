class Solution {
public:
    bool isTrionic(vector<int>& nums) {
       int n=nums.size();
       for(int p=1;p<=n-1;p++){
        for(int q=p+1;q<=n-2;q++){
            int k=1;
            for(int i=1;i<=p;i++) k&=(nums[i]>nums[i-1]);
            for(int i=p+1;i<=q;i++) k&=(nums[i]<nums[i-1]);
            for(int i=q+1;i<n;i++)   k&=(nums[i]>nums[i-1]);
            if(k) return true;    
            }
       }
        return false;
    }
};
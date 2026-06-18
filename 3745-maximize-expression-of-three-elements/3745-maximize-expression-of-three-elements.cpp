class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
     int n=nums.size(),ans=INT_MIN;
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             for(int k=0;k<n;k++){
                 if(i!=j&&j!=k&&i!=k){
                     ans=max(ans,nums[i]+nums[j]-nums[k]);
                 }
             }
         }
     }
        return ans;
    }
};
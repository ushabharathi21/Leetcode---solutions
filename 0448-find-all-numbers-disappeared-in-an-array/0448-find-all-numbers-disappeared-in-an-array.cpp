class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      int n = nums.size();
      int i = 0;
      vector<int>ans;

      while(i<n){
        int correctIndex = nums[i] - 1;
        if(nums[i] != nums[correctIndex])
         swap(nums[i], nums[correctIndex]);
        else 
         i++;
      }  
      for(int i=0;i<n;i++){
        if(nums[i] != i+1){
            ans.push_back(i+1);
        }
      }
      return ans;

    }
};
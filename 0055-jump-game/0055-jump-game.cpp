class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return false;
        int safePosition = nums.size() - 1;
        for (int j = nums.size() - 1; j >= 0; j--) {
            if (j + nums[j] >= safePosition) {
                safePosition = j;
            }
        }
        return safePosition == 0;
    }
};

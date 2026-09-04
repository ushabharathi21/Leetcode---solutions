class Solution {
public:

    // Returns number of subarrays with at most k distinct integers
    long long atMostK(vector<int>& nums, int k) {

        int n = nums.size();
        int left = 0;
        long long ans = 0;

        unordered_map<int, int> freq;

        for (int right = 0; right < n; right++) {

            // Add nums[right]
            freq[nums[right]]++;

            // If distinct elements > k, shrink window
            while (freq.size() > k) {

                freq[nums[left]]--;

                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }

                left++;
            }

            // All subarrays ending at right are valid
            ans += (right - left + 1);
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};
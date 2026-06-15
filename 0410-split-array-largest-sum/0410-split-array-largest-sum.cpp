class Solution {
public:
    int possible(vector<int>& arr, int k, int maxSum){
        int partitions = 1;
        int currentSum = 0;

        for(int x:arr){
            if(currentSum+x<=maxSum){
                currentSum+=x;
            }else{
                partitions++;
                currentSum = x;
            }
        }
        return partitions <= k;
    }
    int splitArray(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);

        while(low<=high){
            int mid = low+(high - low)/2;
            if(possible(arr,k,mid))
              high = mid - 1;
            else
             low = mid + 1;
        }

        return low;
    }
};
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k = 0;
        string repeated = word;
        while(sequence.find(repeated) != -1){
            k++;
            repeated += word;
        }
        return k;
    }
};
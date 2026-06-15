class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        int i=0,z=size-1;
        while(i<z){
            char temp = s[i];
            s[i] = s[z];
            s[z] = temp;
            i++;
            z--;
        }
    }
};
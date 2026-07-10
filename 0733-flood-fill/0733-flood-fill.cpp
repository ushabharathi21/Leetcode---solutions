class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
      fill(image,sr,sc,image[sr][sc],newColor);   
      return image; 
        
    }
     void fill(vector<vector<int>>& image, int i, int j,int color, int newColor){
        if(i<0 || i>image.size()-1 || j<0 || j>image[0].size()-1 || image[i][j] != color){
            return;
        }
        image[i][j]=newColor;
        fill(image,i-1,j,color,newColor);
        fill(image,i+1,j,color,newColor);
        fill(image,i,j-1,color,newColor);
        fill(image,i,j+1,color,newColor);
        return;
     }
};
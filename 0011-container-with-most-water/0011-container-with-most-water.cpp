class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int i=0, j = size - 1, maxArea = 0, currArea = 0;
        
        while(i < j){
            currArea = min(height[i], height[j])*(j - i);
            maxArea = max(maxArea, currArea);
            
            height[i] < height[j] ? i++ : j-- ;
                
        }
        
        return maxArea;
        
    }
};
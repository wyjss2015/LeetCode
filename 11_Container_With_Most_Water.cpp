class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int maxA=0, tmp;
        while(i<j){
            tmp = min(height[i], height[j])*(j-i);
            maxA = max(tmp, maxA);
            if(height[i]<height[j]) ++i;
            else --j;
        }
        return maxA;
    }
};

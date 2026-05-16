// Brute-Force Approach | T.C = O(n^2)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int width = j - i;
                int ht = min(height[i], height[j]);
                int curWater = width * ht;
                maxWater = max(maxWater, curWater);
            }
        }
        return maxWater;
    }
};

//Optimal Approach (2 Pointers) | T.C = O(n)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0;
        int rp = height.size() - 1;
        int maxWater = 0;
        while (lp < rp) {
            int width = rp - lp;
            int h = min(height[lp], height[rp]);
            int curWater = width * h;
            maxWater = max(maxWater, curWater);
            height[lp] < height[rp] ? lp++ : rp--;
        }
        return maxWater;
    }
};
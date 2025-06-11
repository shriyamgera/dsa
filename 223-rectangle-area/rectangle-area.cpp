class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaA = (ax2-ax1) * (ay2-ay1);
        int areaB = (bx2-bx1) * (by2-by1);

        int commonWidth = max(0, min(ax2,bx2) - max(ax1,bx1));
        int commonHeight = max(0, min(ay2,by2) - max(ay1,by1));
        int commonArea = commonWidth * commonHeight;
        int ans = areaA + areaB - commonArea;
        return ans;
    }
};
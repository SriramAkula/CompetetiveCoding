
class Solution {
public:
    struct Box {
        int h, w, l; 
    };

    static bool compare(const Box& a, const Box& b) {
        return (a.w * a.l) > (b.w * b.l);
    }

    int maxHeight(int height[], int width[], int length[], int n) {
        vector<Box> boxes;

        for (int i = 0; i < n; i++) {
            boxes.push_back({height[i], max(width[i], length[i]), min(width[i], length[i])});
            boxes.push_back({width[i], max(height[i], length[i]), min(height[i], length[i])});
            boxes.push_back({length[i], max(height[i], width[i]), min(height[i], width[i])});
        }

        sort(boxes.begin(), boxes.end(), compare);

        int m = boxes.size();
        vector<int> dp(m);

        for (int i = 0; i < m; i++) {
            dp[i] = boxes[i].h;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++) {
                if (boxes[i].w < boxes[j].w && boxes[i].l < boxes[j].l) {
                    dp[i] = max(dp[i], dp[j] + boxes[i].h);
                }
            }
        }

        int maxHeight = 0;
        for (int i = 0; i < m; i++) {
            maxHeight = max(maxHeight, dp[i]);
        }

        return maxHeight;
    }
};
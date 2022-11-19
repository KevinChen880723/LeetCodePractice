namespace BaselineSolution {
    class Solution {
    public:
        vector<int> countBits(int n) {
            vector<int> result;
            for (int i = 0; i <= n; i++) {
                int count = 0, num = i;
                while(num != 0) {
                    if (num & 0x00000001) count++;
                    num = num >> 1;
                }
                result.push_back(count);
            }
            return result;
        }
    };
};
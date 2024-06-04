#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class Solution {
    private:
        vector<int> nums = {};
    public:
        Solution() {
            fstream fi("input.txt");
            int n, temp;
            fi >> n;

            for (int i = 0; i < n; i++) {
                fi >> temp;
                nums.push_back(temp);
            }
            
            vector<int> result = singleNumber(nums);

            for (int i = 0; i < 2; i++)
                cout << result[i] << ' ';
        }

        vector<int> singleNumber(vector<int>& nums) {
            int overall_xor = 0;
            
            for (int i = 0; i < nums.size(); i++) {
                overall_xor ^= nums[i];
            }

            int last_0_xor = 0;
            int last_1_xor = 0;
            int bit_diff = 0;
            
            while (((overall_xor >> bit_diff) & 1) != 1) {
                bit_diff++;
            }

            for (int i = 0; i < nums.size(); i++) {
                if ((nums[i] >> bit_diff) & 1 == 1) {
                    last_1_xor ^= nums[i];
                } else {
                    last_0_xor ^= nums[i];
                }
            }

            return {last_1_xor, last_0_xor};
        }
};

int main() {
    Solution S;
}
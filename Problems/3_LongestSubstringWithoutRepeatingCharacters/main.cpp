#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
    private:
        vector<int> nums = {};
        string s;
    public:
        Solution() {
            fstream fi("input.txt");
            getline(fi, s);
            cout << lengthOfLongestSubstring(s);
        }

        // int lengthOfLongestSubstring(string s) {
        //     unordered_map<char, int> char_check;
        //     int max = 0;
        //     int left = 0;

        //     for (int right = 0; right < s.size(); right++) {
        //         if (char_check[s[right]] == 0) {
        //             char_check[s[right]]++;
        //             max = (max < right - left + 1) ? right - left + 1 : max;
        //         }
        //         else {
        //             while (char_check[s[right]] != 0) {
        //                 char_check[s[left]]--;
        //                 left++;
        //             }

        //             char_check[s[right]]++;
        //         }
        //     }

        //     return max;
        // }


        int lengthOfLongestSubstring(string s) {
            int n = s.size();
            if (n == 0) return 0;
            vector<int> indices(256, -1);
            int left = 0, right = 0;
            int maxLength = 0;

            while (right < n) {
                if (indices[s[right] != -1]) {
                    if (left <= indices[s[right]])
                        left = indices[s[right]] + 1;
                }

                indices[s[right]] = right;
                maxLength = (maxLength < right - left + 1) ? maxLength : right - left + 1;
                right++;
            }

            return maxLength;
        }
};

int main() {
    Solution S;
}
#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
    private:
        string s;
    public:
        Solution() {
            fstream fi("input.txt");
            getline(fi, s);
            cout << romanToInt(s);
        }

        int romanToInt(string s) {
            unordered_map<char, int> romanInt = 
                {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
            int sum = 0;
            int n = s.size();
            int prev = 0;
            
            // for (int i = n - 1; i >= 0; i--) {
            //     sum += romanInt[s[i]];
            //     if (i > 0 && romanInt[s[i]] > romanInt[s[i - 1]]) {
            //         sum -= romanInt[s[i - 1]];
            //         i--;
            //     }
            // }

            for (int i = 0; i < n; i++) {
                sum += (romanInt[s[i]] > prev) ? (romanInt[s[i]] - 2 * prev) : romanInt[s[i]];
                prev = romanInt[s[i]];
            }

            return sum;
        }
};

int main() {
    Solution S;
}
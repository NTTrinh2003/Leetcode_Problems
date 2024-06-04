#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class Solution {
    private:
        string str1, str2;
        char ch;
    public:
        Solution() {
            fstream fi("input.txt");
            getline(fi, str1);
            getline(fi, str2);
            string result = gcdOfStrings(str1, str2);
            cout << "Actual Output: " << result << endl;
        }

        int gcd(int a, int b) {
            if (b == 0) {
                return a;
            } else {
                return gcd(b, a % b);
            }
        }

        string gcdOfStrings(string str1, string str2) {
            // result
            string s = "";


            int idx = 0;
            int s1_n = str1.length(), s2_n = str2.length();
            int s_maxLength = gcd(s1_n, s2_n);

            // Find divisor
            while (idx < s1_n && idx < s2_n) {
                if (str1[idx] == str2[idx] && idx < s_maxLength) {
                    s += str1[idx];
                    idx++;
                    cout << s << endl;
                } else break;
            }

            // Only find first matched substring not divisor
            // Find gcd of length of str1, str2?


            // No divisor found
            if (s == "") return s;

            while (idx < s1_n || idx < s2_n) {
                // Iterating through string divisor
                for (int i = 0; i < s.length(); i++) {
                    // End of string but not finish divisor
                    if (((idx + i == s1_n - 1) || (idx + i == s2_n - 1)) 
                        && (i != s.length() - 1))
                        return "";
                    
                    // If not end of string and iterating string is not match
                    if (idx + i < s1_n && str1[idx + i] != s[i]) return "";
                    if (idx + i < s2_n && str2[idx + i] != s[i]) return "";
                }

                // Move iterating index
                idx += s.length();
            }

            return s;
        }
};

int main() {
    Solution S;
}
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class Solution {
    private:
        string word;
        char ch;
    public:
        Solution() {
            fstream fi("input.txt");
            getline(fi, word);
            fi >> ch;
            cout << reversePrefix(word, ch);
        }

        string reversePrefix(string word, char ch) {
            int i;

            for (i = 0; i < word.size(); i++) {
                if (word[i] == ch) {
                    break;
                }
            }

            if (i == word.size()) return word;

            for (int j = 0; j <= i / 2; j++) {
                char temp = word[j];
                word[j] = word[i - j];
                word[i - j] = temp;
            }

            return word;
        }
};

int main() {
    Solution S;
}
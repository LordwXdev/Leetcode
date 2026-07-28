#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        int n = words.size();

        while (i < n) {
            // figure out how many words fit on this line
            int j = i;
            int lineLen = 0;
            while (j < n && lineLen + (int)words[j].size() + (j - i) <= maxWidth) {
                lineLen += words[j].size();
                j++;
            }

            int numWords = j - i;
            int totalChars = lineLen; // sum of word lengths, no spaces
            int totalSpaces = maxWidth - totalChars;

            string line = "";

            bool isLastLine = (j == n);

            if (numWords == 1 || isLastLine) {
                // left justify: single space between words, pad right
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) line += " ";
                }
                while ((int)line.size() < maxWidth) line += " ";
            } else {
                int gaps = numWords - 1;
                int spaceEach = totalSpaces / gaps;
                int extra = totalSpaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) {
                        int spacesToAdd = spaceEach + (k - i < extra ? 1 : 0);
                        line += string(spacesToAdd, ' ');
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};
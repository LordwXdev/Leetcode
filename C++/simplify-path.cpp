#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string part;

        while (getline(ss, part, '/')) {
            if (part == "" || part == ".") {
                continue; // skip empty pieces and current-dir
            } else if (part == "..") {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(part);
            }
        }

        string result = "";
        for (string& dir : stack) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};
class Solution {
public:
    string simplifyPath(string path) {
        istringstream ss(path);
        string token;
        vector<string> stack;
        
        while (getline(ss, token, '/')) {
            if (token == \\ || token == \.\) continue;
            if (token == \..\) {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(token);
            }
        }
        
        if (stack.empty()) return \/\;
        
        string result = \/\;
        for (const auto& dir : stack) {
            result += dir + \/\;
        }
        result.pop_back();
        return result;
    }
};

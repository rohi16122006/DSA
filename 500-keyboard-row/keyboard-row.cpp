class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        for(string word : words) {
            string w = word;
            for(char &ch : w)
                ch = tolower(ch);
            int row = 0;
            if(row1.find(w[0]) != string::npos)
                row = 1;
            else if(row2.find(w[0]) != string::npos)
                row = 2;
            else
                row = 3;
            bool valid = true;
            for(char ch : w) {
                if(row == 1 && row1.find(ch) == string::npos)
                    valid = false;
                if(row == 2 && row2.find(ch) == string::npos)
                    valid = false;
                if(row == 3 && row3.find(ch) == string::npos)
                    valid = false;
            }
            if(valid)
                ans.push_back(word);
        }
        return ans;
    }
};
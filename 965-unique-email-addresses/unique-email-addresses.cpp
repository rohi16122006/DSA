class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(string email : emails) {
            string temp = "";
            int i = 0;
            while(email[i] != '@' && email[i] != '+') {
                if(email[i] != '.')
                    temp += email[i];
                i++;
            }
            while(email[i] != '@')
                i++;
            while(i < email.size()) {
                temp += email[i];
                i++;
            }
            st.insert(temp);
        }
        return st.size();
    }
};
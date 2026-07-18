class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if(n < 10) return {};
        string key = s.substr(0,10);
        unordered_set<string> ans;
        unordered_set<string> st;
        st.insert(key);
        for(int i=10;i<n;i++){
            key.erase(0,1);
            key+=s[i];
            if(st.find(key) != st.end()){
                if(ans.find(key) == ans.end()){
                    ans.insert(key);
                }
            }
            st.insert(key);
        }
        return {ans.begin(),ans.end()};
    }
};
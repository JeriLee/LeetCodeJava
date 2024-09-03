/*
很普通的遍历
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int size = s.length();
        bool vis[size];
        memset(vis, 0, sizeof(bool) * size);
        stack<int> st;
        int count = 0;
        for (int i = 0 ; i < size; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i]==')') {
                if (st.size() > 0) {
                    st.pop();
                } else {
                    vis[i] = true;
                    count++;
                }
            }
        }
        
        while(st.size() > 0) {
            int index = st.top(); st.pop();
            vis[index] = true;
            ++count;
        }

        string s2(size -count, 'a');
        int cur = 0;
        for(int i = 0; i < size; ++i) {
            if (vis[i]) continue;
            s2[cur++] = s[i];
        }

        return s2;
    }
};
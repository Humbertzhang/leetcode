/*leetcode的测算时间也不准确．．一次打败了2% 一次打败了90%..*/
class Solution {
public:
    bool isValid(string s) {
       stack<char> in;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                in.push(s[i]);
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(in.empty())
                    return false;
                char temp = in.top();
                in.pop();
                if(s[i] == ')'){
                    if(temp != '(')
                        return false;
                }
                else if(s[i] == '}'){
                    if(temp != '{')
                        return false;
                }
                else if(s[i] == ']'){
                    if(temp != '[')
                        return false;
                }
            }
        }
        
    if(!in.empty())
        return false;
        
    return true;
    }
};

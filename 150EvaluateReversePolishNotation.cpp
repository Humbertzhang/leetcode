/*后缀表达式求值*/
/*
注意atoi只能用在char *上而不可以用在string上，
可以用str.c_str()来转化
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums; 
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                nums.push(atoi(tokens[i].c_str()));
            }else{
                int num1 = nums.top();  nums.pop();
                int num2 = nums.top();  nums.pop();
                int num3 = eval(num2, num1, tokens[i]);
                nums.push(num3);
            }
        }
        return nums.top();
    }
    int eval(int num1, int num2, string s) {
        if(s=="+"){
            return num1 + num2;
        }else if(s == "-"){
            return num1 - num2;
        }else if(s == "*"){
            return num1 * num2;
        }else if(s == "/"){
            return num1/num2;
        }
    }
};

/*Maybe the simplest problem
但是注意如果首先判断是否是数字的话可以
节省很多时间
因为还是数字多，就不需要再在下面的if else那里浪费时间了	
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for(int i = 1; i <= n; i++){
            if(i%3 != 0 && i%5 != 0)
                ret.push_back(to_string(i));
            else if(i%15 ==0)
                ret.push_back("FizzBuzz");
            else if(i%5 == 0)
                ret.push_back("Buzz");
            else if(i%3 == 0)
                ret.push_back("Fizz");
        }
        return ret;
    }
};

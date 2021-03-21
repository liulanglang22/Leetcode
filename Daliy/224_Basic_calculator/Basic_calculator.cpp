//
// Created by Admin on 2021/3/11.
//
// 方法描述的是动作，当所有的对象执行这个动作时，最终产生的影响是一样的，
// 那么这个动作就不再属于某一个对象的动作了，可以将这个动作提升为类级别的动作，模板级别的动作。
#include <iostream>
#include <stack>
#include <string>
using namespace std;


class Solution {
public:
    static int calculate(string s) {
        stack<int> ops;
        ops.push(1);
        int sign = 1;
        int ret = 0;
        int n = s.length();
        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                i++;
            } else if (s[i] == '+') {
                sign = ops.top();
                i++;
            } else if (s[i] == '-') {
                sign = -ops.top();
                i++;
            } else if (s[i] == '(') {
                ops.push(sign);
                i++;
            } else if (s[i] == ')') {
                ops.pop();
                i++;
            } else {
                long num = 0;
                while ( i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                ret += sign * num;
            }


        }
        return ret;
    }
};

int main()
{

    string s = "(1+(4+5+2)-3)+(6+8)";
    int ret = Solution::calculate(s);
    printf("%d", ret);
}
































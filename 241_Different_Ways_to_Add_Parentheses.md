#241. Different Ways to Add Parentheses
##Question
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".
```
((2-1)-1) = 0
(2-(1-1)) = 2
```
Output: [0, 2]


Example 2
Input: "2*3-4*5"
```
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
```
Output: [-34, -14, -10, -10, 10]

##Analysis
* 分治
* 根据符号进行切分

##Solution
```
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int n = input.size();
        vector<int> res;
        for(int i=0;i<input.size();++i){
            if(input[i]=='*'||input[i]=='-'||input[i]=='+'){
                string left = input.substr(0, i);
                string right = input.substr(i+1, n-i-1);
                vector<int> ltemp = diffWaysToCompute(left);
                vector<int> rtemp = diffWaysToCompute(right);
                for(auto &l: ltemp){
                    for(auto &r: rtemp){
                        switch(input[i]){
                            case '*':
                                res.push_back(l*r);
                                break;
                            case '-':
                                res.push_back(l-r);
                                break;
                            default:
                                res.push_back(l+r);
                                break;
                        }
                    }
                }
            }
        }
        if(res.empty())
            res.push_back(stoi(input));
        return res;
    }
};
```
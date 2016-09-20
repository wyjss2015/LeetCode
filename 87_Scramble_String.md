#87. Scramble String
##Question
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":
```
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
```
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

```
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
```
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
```
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
```
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

##Analysis
* 递归+DP
* 实现时要注意四个递归一定要写在条件判断里面，因为or语句在前面条件满足时就结束，所以大多情况不用四个递归都进行，如果四个全递归后在统一做判断，则时间大大加大，PS:因为这个原因调试了1个小时T.T，血的教训

##Solution
```
class Solution {
public:
    bool helper(unordered_map<string,bool> &hash, string s1, string s2){
        if(s1.size()==1) return s1==s2;
        int n = s1.size();
        int flag = 0;
        if(hash.count(s1+s2)) return hash[s1+s2];
        if(s1==s2) flag = 1;
        else{
            for(int i=1;i87. Scramble String<n;++i){
               if((helper(hash, s1.substr(0,i), s2.substr(0,i))&&helper(hash, s1.substr(i,n-i), s2.substr(i,n-i)))||(helper(hash, s1.substr(0,i), s2.substr(n-i,i))&&helper(hash, s1.substr(i,n-i), s2.substr(0,n-i)))){
                  flag = 1;
                  break;
               }
          }
        }
        if(flag == 1){
            hash[s1+s2] = true;
            return true;
        }else{
            hash[s1+s2] = false;
            return false;
        }
    }
    bool isScramble(string s1, string s2) {
        unordered_map<string,bool> hash;
        return helper(hash, s1, s2);
    }
};
```
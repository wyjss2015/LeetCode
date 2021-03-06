/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        vector<int> leftChild, rightChild;
        leftChild = DFS(root->left, 'l');
        rightChild = DFS(root->right, 'r');
        if(leftChild==rightChild)
            return true;
        else
            return false;
    }
    vector<int> DFS(TreeNode *root, char direction){
        vector<int> flag, leftChild, rightChild;
        if(root==nullptr){
            flag.push_back(-1);
            return flag;
        }
        flag.push_back(root->val);
        leftChild = DFS(root->left, direction);
        rightChild = DFS(root->right, direction);
        if(direction=='l'){
            for(auto a:leftChild)
                flag.push_back(a);
            for(auto a:rightChild)
                flag.push_back(a);
        }else{
            for(auto a:rightChild)
                flag.push_back(a);
            for(auto a:leftChild)
                flag.push_back(a);
        }
        return flag;
    }
};


//Solution 2 recurtive
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return !root||isSymmetricHelper(root->left, root->right);
    }
    bool isSymmetricHelper(TreeNode *left, TreeNode *right){
        if(left==nullptr||right==nullptr)
            return left == right;
        else if(left->val!=right->val)
            return false;
        else{
            return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
        }
    }
};

//Solution 3 iterative
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return !root||isSymmetricHelper(root->left, root->right);
    }
    bool isSymmetricHelper(TreeNode *left, TreeNode *right){
        if(left==nullptr||right==nullptr)
            return left==right;
        else if(left->val!=right->val)
            return false;
        else{
            TreeNode *leftStack[100], *rightStack[100];
            int leftStackFlag[100], rightStackFlag[100];
            int leftTop=-1, rightTop=-1;
            leftStack[++leftTop] = left;
            leftStackFlag[leftTop] = 0;
            rightStack[++rightTop] = right;
            rightStackFlag[rightTop] = 0;
            while(leftTop!=-1&&rightTop!=-1){
                left = leftStack[leftTop];
                right = rightStack[rightTop];
                if(leftStackFlag[leftTop]==0){
                    if(left->left==nullptr||right->right==nullptr){
                        if(left->left == right->right){
                            leftStackFlag[leftTop] = 1;
                            rightStackFlag[rightTop] = 1;
                            continue;
                        }else
                            return false;
                    }else if(left->left->val!=right->right->val)
                        return false;
                    else{
                        leftStackFlag[leftTop] = 1;
                        leftStack[++leftTop] = left->left;
                        leftStackFlag[leftTop] = 0;
                        rightStackFlag[rightTop] = 1;
                        rightStack[++rightTop] = right->right;
                        rightStackFlag[rightTop] = 0;
                    }
                }else if(leftStackFlag[leftTop]==1){
                    if(left->right==nullptr||right->left==nullptr){
                        if(left->right == right->left){
                            leftStackFlag[leftTop] = 2;
                            rightStackFlag[rightTop] = 2;
                            continue;
                        }else
                            return false;
                    }else if(left->right->val!=right->left->val)
                        return false;
                    else{
                        leftStackFlag[leftTop] = 2;
                        leftStack[++leftTop] = left->right;
                        leftStackFlag[leftTop] = 0;
                        rightStackFlag[rightTop] = 2;
                        rightStack[++rightTop] = right->left;
                        rightStackFlag[rightTop] = 0;
                    }
                }else{
                    --leftTop;
                    --rightTop;
                }
            }
            return true;
        }
    }
};

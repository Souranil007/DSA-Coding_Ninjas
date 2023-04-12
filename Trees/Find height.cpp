// Given a generic tree, find and return the height of given tree.
// Input Format:
// The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
// Output Format :
// The first and only line of output prints the height of the given generic tree.
// Constraints:
// Time Limit: 1 sec
// Sample Input 1:
// 10 3 20 30 40 2 40 50 0 0 0 0 
// Sample Output 1:
// 3


/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

void getHeight(TreeNode<int> *root, int height, int *max)
{
    if ((*max) < height)
        *max = height;
    for (int i = 0; i < root->children.size(); i++)
        getHeight(root->children[i], 1 + height, max);
}
int getHeight(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return 0;
    int max = 1, height = 1;
    getHeight(root, height, &max);
    return max;
}
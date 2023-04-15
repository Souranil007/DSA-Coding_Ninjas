// Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
// Input format:
// The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
// Output Format:
// The binary tree is printed level wise, as described in the task. Each level is printed in new line.
// Constraints
// Time Limit: 1 second
// Sample Input :
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
// Sample Output :
// 5
// 10 6
// 2 3
// 9


/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

#include <vector>
void zigZagOrder(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;
    vector<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push_back(root);
    int level = 1;
    while (pendingNodes.size() != 0)
    {
        int n = pendingNodes.size();
        if (level % 2 == 0)
        {
            for (int i = n - 1; i >= 0; i--)
                cout << pendingNodes[i]->data << " ";
        }
        else
        {
            for (auto i : pendingNodes)
                cout << i->data << " ";
        }
        for (int i = 0; i < n; i++)
        {
            BinaryTreeNode<int> *front = pendingNodes[i];
            if (front->left != NULL)
                pendingNodes.push_back(front->left);
            if (front->right != NULL)
                pendingNodes.push_back(front->right);
        }
        pendingNodes.erase(pendingNodes.begin(), pendingNodes.begin() + n);
        cout << "\n";
        level++;
    }
}

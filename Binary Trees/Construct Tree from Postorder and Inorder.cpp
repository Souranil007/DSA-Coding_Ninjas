// For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
// Note:
// Assume that the Binary Tree contains only unique elements. 
// Input Format:
// The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

// The second line of input contains N integers, all separated by a single space. It represents the Postorder-traversal of the binary tree.

// The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.
// Output Format:
// The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
// Elements on every level will be printed in a linear fashion. A single space will separate them.
// Constraints:
// 1 <= N <= 10^4
// Where N is the total number of nodes in the binary tree.

// Time Limit: 1 sec
// Sample Input 1:
// 7
// 4 5 2 6 7 3 1 
// 4 2 5 1 6 3 7 
// Sample Output 1:
// 1 
// 2 3 
// 4 5 6 7 
// Sample Input 2:
// 6
// 2 9 3 6 10 5 
// 2 6 3 9 5 10 
// Sample Output 2:
// 5 
// 6 10 
// 2 3 
// 9 


/***********************************************************
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
BinaryTreeNode<int>* buildTreeHelp(int* in, int* post, int inS, int inE, int postS, int postE){
    if(inS>inE){
        return NULL;
    }
    int rootData = post[postE];
    int rootIndex = -1;
    for(int i=inS; i<=inE; i++){
        if(in[i] == rootData){
            rootIndex = i;
        }
    }
    
    int lInS = inS;
    int lInE = rootIndex-1;
    int lPostS = postS;
    int lPostE = lInE-lInS+lPostS;
    int rInS = rootIndex+1;
    int rInE = inE;
    int rPostS = lPostE+1;
    int rPostE = postE-1;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelp(in, post, lInS, lInE, lPostS, lPostE);
    root->right = buildTreeHelp(in, post, rInS, rInE, rPostS, rPostE);
    
    return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    buildTreeHelp(inorder, postorder, 0, inLength-1, 0, postLength-1);
}

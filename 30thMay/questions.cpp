#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode {
public:
	int val; // data
	TreeNode* left; // address of left child
	TreeNode* right; // address of right child

	TreeNode(int data) {
		this->val = data;
		this->left = NULL;
		this->right = NULL;
	}
};

TreeNode* builtTree(TreeNode* root) {
	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	if (root == NULL) {
		root = new TreeNode(data); // calling a constructor to create
		// a new TreeNode object
	}

	root->left = builtTree(root->left);
	root->right = builtTree(root->right);

	return root;
}

// in a tree problem you are always given a root address/root node of
// a tree

// if you have the access to root that means you have the access to your
// whole tree

void preOrder(TreeNode* root) {
	// BASE CASE
	if (root == NULL) {
		return;
	}

	cout << root->val << " ";
	preOrder(root->left); // first you will complete your left child traversal
	preOrder(root->right);
}

void inOrder(TreeNode* root) {
	// BASE CASE
	if (root == NULL) {
		return;
	}

	// first left
	inOrder(root->left); // left recursion call
	// then node itself
	cout << root->val << " ";
	// then right
	inOrder(root->right); // right recursion call (solving the right subtree)
}

int countNodes(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	// CALL FOR LEFT SUBTREE
	int leftCount = countNodes(root->left);
	// CALL FOR RIGHT SUBTREE
	int rightCount = countNodes(root->right);

	int totalCount = leftCount + 1 + rightCount;
	return totalCount;
}

int sumOfNodes(TreeNode* root) {
	// BASE CASE
	if (root == NULL) { // when you reach to the base case
		return 0; // what you shoulf return when you reach case
	}

	int leftSum = sumOfNodes(root->left);
	int rightSum = sumOfNodes(root->right);

	int totalSum = leftSum + root->val + rightSum;
	return totalSum;
}

bool search(TreeNode* root, int key) {
	//BASE CASE
	if (root == NULL) {
		return false;
	}

	if (root->val == key) { // if the key is present at the root node
		// then there is no point of further checking the subtrees
		// just return true
		return true;
	}

	// if you're here that means the root does not contain the key
	bool leftSearch = search(root->left, key);
	bool rightSearch = search(root->right, key);

	// if (leftSearch or rightSearch) {
	// 	return true;
	// }
	// return false;

	// can be written like
	return leftSearch or rightSearch;
}

int maxDepth(TreeNode* root) {
	//BASE CASE
	if (root == NULL) {
		return 0;
	}

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	int myDepth = max(leftDepth, rightDepth) + 1;
	return myDepth;
}

bool searchInBST(TreeNode* root, int key) {
	//BASE CASE
	if (root == NULL) {
		return false;
	}

	if (root->val == key) {
		return true;
	}

	if (key > root->val) {
		bool resultFromRightSubtree = searchInBST(root->right, key);
		return resultFromRightSubtree;
	} else {
		bool resultFromLeftSubtree = searchInBST(root->left, key);
		return resultFromLeftSubtree;
	}
}

void inorder(TreeNode* root, vector<int> &res) {
	if (root == NULL) {
		return;
	}

	inorder(root->left, res);
	res.push_back(root->val);
	inorder(root->right, res);
}

int kthSmallest(TreeNode* root, int k) {
	vector<int> res;

	inorder(root, res);

	return res[k - 1];
}

int main() {

	TreeNode* root = NULL;
	cout << "Please enter the tree values ?" << endl;
	root = builtTree(root);

	// cout << "******* PREORDER *********" << endl;
	// preOrder(root);
	// cout << endl;

	// cout << "*********** INORDER **********" << endl;
	// inOrder(root);
	// cout << endl;

	// cout << "Number of nodes is " << countNodes(root) << endl;

	// cout << "Sum of all nodes is " << sumOfNodes(root) << endl;

	// int key = 54;

	// if (search(root, key)) {
	// 	cout << "Found the key value in my tree" << endl;
	// } else {
	// 	cout << "Key not found!" << endl;
	// }

	// int key = 15;
	// if (searchInBST(root, key)) {
	// 	cout << "Found the key value in my tree" << endl;
	// } else {
	// 	cout << "Key not found!" << endl;
	// }

	// cout << root->val << endl;
	return 0;
}

// Input Binary Tree
// 4 13 19 -1 -1 -1 5 17 -1 -1 3 -1 -1


// Input BST
// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1

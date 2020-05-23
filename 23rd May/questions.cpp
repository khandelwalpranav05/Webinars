#include <iostream>
#include <vector>

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
		root = new TreeNode(data);
	}

	root->left = builtTree(root->left);
	root->right = builtTree(root->right);

	return root;
}

// In tree problems you are always given a root node address in your question

void inOrder(TreeNode* root) {
	//BASE CASE
	if (root == NULL) {
		return;
	}

	// RECURSIVE CASE
	inOrder(root->left); // recursion subproblem of calling for your left subtree
	cout << root->val << " ";
	inOrder(root->right);
}

void preOrder(TreeNode* root) {
	//BASE CASE
	if (root == NULL) {
		return;
	}

	// RECURSIVE CASE
	cout << root->val << " ";
	preOrder(root->left); // print my left subtree in preorder (subproblem)
	preOrder(root->right);
}

int countNodes(TreeNode* root) {
	//BASE CASE
	if (root == NULL) {
		return 0;
	}

	// RECURSIVE CASE
	int leftCount = countNodes(root->left);
	int rightCount = countNodes(root->right);

	int totalCount = leftCount + 1 + rightCount;
	return totalCount;
}

int sumOfNodes(TreeNode* root) {
	// BASE CASE
	if (root == NULL) {
		return 0;
	}

	// RECURSIVE CASE
	int leftSum = sumOfNodes(root->left);
	int rightSum = sumOfNodes(root->right);

	int totalSum = leftSum + root->val + rightSum;
	return totalSum;
}

bool search(TreeNode* root, int key) {
	// BASE CASE
	if (root == NULL) { // recursion has come to the smallest subproblem
		return false;
	}

	// first we'll check ourselves
	if (root->val == key) {
		return true;
	}

	// RECURSIVE CASE
	bool leftSearch = search(root->left, key);
	bool rightSearch = search(root->right, key);

	if (leftSearch or rightSearch) {
		return true;
	}

	return false;
}

int maxDepth(TreeNode* root) {
	// BASE CASE
	if (root == NULL) {
		return 0;
	}

	// RECURSIVE CASE
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	int myDepth = max(leftDepth, rightDepth) + 1;
	return myDepth;
}

void inorder(TreeNode* root, vector<int> &res) {
	if (root == NULL) {
		return;
	}

	inorder(root->left, res); // Left
	res.push_back(root->val); // Node
	inorder(root->right, res); // Right
}

int kthSmallest(TreeNode* root, int k) {
	vector<int> res;

	inorder(root, res);

	return res[k - 1];
}

bool searchBST(TreeNode* root, int key) {
	//BASE CASE
	if (root == NULL) {
		return false;
	}

	if (key == root->val) {
		return true;
	}

	// RECURSIVE CASE
	if (root->val > key) { // you might find the key in left subtree
		return searchBST(root->left, key);
	} else { // you might find the key in the right subtree
		return searchBST(root->right, key);
	}
}

int main() {

	TreeNode* root = NULL;
	cout << "Please Enter the tree data ?" << endl;
	root = builtTree(root);

	// Input Tree
	// 4 2 1 -1 -1 -1 6 5 -1 -1 8 -1 -1

	// cout << "Inorder" << endl;
	// inOrder(root);
	// cout << endl;

	// cout << "PreOrder" << endl;
	// preOrder(root);
	// cout << endl;

	// cout << "Total number of nodes are " << countNodes(root) << endl;

	// cout << "Total sum of the tree is " << sumOfNodes(root) << endl;

	// int key = 15;
	// if (search(root, key)) {
	// 	cout << "Key Found!" << endl;
	// } else {
	// 	cout << "Not Found!" << endl;
	// }

	// int key = 5;
	// if (searchBST(root, key)) {
	// 	cout << "Key Found!" << endl;
	// } else {
	// 	cout << "Not Found!" << endl;
	// }

	return 0;
}
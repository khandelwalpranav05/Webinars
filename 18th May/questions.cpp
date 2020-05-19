#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

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

// Root Left Right
void preOrder(TreeNode* root) {
	//BASECASE
	if (root == NULL) {
		return;
	}

	cout << root->val << " ";
	// print left subtree
	preOrder(root->left); // recursion (solving your subproblem)
	// print right subtree
	preOrder(root->right); //recursion (solving your subproblem)
}

void inOrder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	inOrder(root->left); // printing lefttree in inorder
	cout << root->val << " ";
	inOrder(root->right);
}

int sumOfNodes(TreeNode* root) {
	//BASE CASE
	if (root == NULL) {
		return 0;
	}

	int leftSum = sumOfNodes(root->left); // recursion
	int rightSum = sumOfNodes(root->right); // recursion

	int total = leftSum + rightSum + root->val;
	return total;
}

int countNodes(TreeNode* root) {
	//BASE CASE
	if (root == NULL) {
		return 0;
	}

	int leftCount = countNodes(root->left);
	int rightCount = countNodes(root->right);

	int total = leftCount + 1 + rightCount;
	return total;
}

bool search(TreeNode* root, int key) {
	//BASE CASE
	if (root == NULL) {
		return false;
	}

	if (root->val == key) {
		return true;
	}

	bool searchLeft = search(root->left, key);
	bool searchRight = search(root->right, key);

	if (searchLeft or searchRight) {
		return true;
	}

	return false;
}

bool searchBST(TreeNode* root, int key) {
	if (root == NULL) {
		return false;
	}

	if (root->val == key) {
		return true;
	}

	if (root->val > key) {
		// search in left subtree
		return searchBST(root->left, key);
	} else {
		//search in right subtree
		return searchBST(root->right, key);
	}
}

vector<int> res;
void inorder(TreeNode* root) {
	if (root == NULL) {
		return;
	}

	inorder(root->left);
	res.push_back(root->val);
	inorder(root->right);
}

int kthSmallest(TreeNode* root, int k) {

	inorder(root);
	return res[k - 1];
}


int main() {

	TreeNode* root = NULL;
	root = builtTree(root);

	// preOrder(root);
	// cout << endl;

	// inOrder(root);
	// cout << endl;

	// cout << sumOfNodes(root) << endl;

	// int key = 15;

	// if (search(root, key)) {
	// 	cout << "Found the key" << endl;
	// } else {
	// 	cout << "Not Found!" << endl;
	// }

	return 0;
}

// Input Tree
// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1

// 1 -1 2 3 -1 5 6 -1 -1 7 -1 -1 4 -1 -1

// Balanced Input
// 1 2 -1 -1 3 -1 4 -1 6 -1 -1

// Left View
// 1 2 4 -1 6 -1 -1 -1 3 -1 5 7 9 -1 -1 10 11 -1 -1 -1 8 -1 -1
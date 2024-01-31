#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

vector<double> averageOfLevels(TreeNode* root);
void deleteTree(TreeNode* root);
void printVector(const vector<double>& container);

int main() {
	// Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. 
	// Answers within 10-5 of the actual answer will be accepted.
	
	TreeNode* emptyTree = nullptr;
	printVector(averageOfLevels(emptyTree)); // Expected: EMPTY

	// Manually build a tree for testing purposes
	TreeNode* filledTree = new TreeNode(3);
	filledTree->left = new TreeNode(9);
	filledTree->right = new TreeNode(20);
	filledTree->right->left = new TreeNode(15);
	filledTree->right->right = new TreeNode(7);

	printVector(averageOfLevels(filledTree)); // Expected: [3, 14.5, 11]
	deleteTree(filledTree);

	return 0;
}

vector<double> averageOfLevels(TreeNode* root) {
	// Edge Cases
	if (!root) { return {}; }
	if (!root->left && !root->right) { return { double(root->val) }; }

	// Store level averages in a vector
	vector<double> averages;

	// Create a queue for level order traversal
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		// Keep track of current queue size and level average
		int queueSize = q.size();
		double levelSum = 0;

		for (int i = 0; i < queueSize; ++i) {
			TreeNode* current = q.front();
			q.pop();

			// Add current node's value to level sum
			levelSum += current->val;

			// Enqueue left child
			if (current->left) {
				q.push(current->left);
			}

			// Enqueue right child
			if (current->right) {
				q.push(current->right);
			}
		}
		averages.push_back(levelSum / queueSize);
	}
	return averages;
}

void deleteTree(TreeNode* root) {
	if (root == nullptr) return;

	// Recursively delete left and right subtrees
	deleteTree(root->left);
	deleteTree(root->right);

	// Delete the current node after deleting its children
	delete root;
}

void printVector(const vector<double>& container) {
	if (container.empty()) {
		cout << "EMPTY\n\n";
	}
	else {
		int len = container.size();
		cout << "[";
		for (int i = 0; i < len; ++i) {
			cout << container[i];

			if (i < len - 1) {
				cout << ", ";
			}
		}
		cout << "]";
	}
}


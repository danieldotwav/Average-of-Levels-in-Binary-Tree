#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

vector<double> averageOfLevels(TreeNode* root);
TreeNode* buildTree(const vector<int>& vec);
void deleteTree(TreeNode* root);
void printVector(const vector<double>& container);

int main() {
	
	// Case 1: Empty Tree
	std::cout << "Case 1: Empty Tree" << std::endl;
	TreeNode* emptyTree = nullptr;
	printVector(averageOfLevels(emptyTree)); // Expected: EMPTY

	// Case 2: Partially Filled Tree
	std::cout << "Case 2: Partially Filled Tree" << std::endl;
	TreeNode* filledTree = buildTree({ 3, 9, 20, INT_MIN, INT_MIN, 15, 7 });
	printVector(averageOfLevels(filledTree)); // Expected: [3, 14.5, 11]
	deleteTree(filledTree);

	// Case 3: Single Node Tree
	std::cout << "Case 3: Single Node Tree" << std::endl;
	TreeNode* singleNodeTree = buildTree({ 42 });
	printVector(averageOfLevels(singleNodeTree)); // Expected: [42]
	deleteTree(singleNodeTree);

	// Case 4: Full Tree
	std::cout << "Case 4: Full Tree" << std::endl;
	TreeNode* fullTree = buildTree({ 1, 2, 3, 4, 5, 6, 7 });
	printVector(averageOfLevels(fullTree)); // Expected: [1, 2.5, 5.5]
	deleteTree(fullTree);

	// Case 5: Left-skewed Tree
	std::cout << "Case 5: Left-skewed Tree" << std::endl;
	TreeNode* leftSkewedTree = buildTree({ 1, 2, INT_MIN, 3 });
	printVector(averageOfLevels(leftSkewedTree)); // Expected: [1, 2, 3]
	deleteTree(leftSkewedTree);

	// Case 6: Right-skewed Tree
	std::cout << "Case 6: Right-skewed Tree" << std::endl;
	TreeNode* rightSkewedTree = buildTree({ 1, INT_MIN, 2, INT_MIN, 3 });
	printVector(averageOfLevels(rightSkewedTree)); // Expected: [1, 2, 3]
	deleteTree(rightSkewedTree);

	// Case 7: Tree with only left children
	std::cout << "Case 7: Tree with only left children" << std::endl;
	TreeNode* leftChildrenTree = buildTree({ 1, 2, INT_MIN, 4, INT_MIN, INT_MIN, 8 });
	printVector(averageOfLevels(leftChildrenTree)); // Expected: [1, 2, 4, 8]
	deleteTree(leftChildrenTree);

	// Case 8: Tree with only right children
	std::cout << "Case 8: Tree with only right children" << std::endl;
	TreeNode* rightChildrenTree = buildTree({ 1, INT_MIN, 3, INT_MIN, 7 });
	printVector(averageOfLevels(rightChildrenTree)); // Expected: [1, 3, 7]
	deleteTree(rightChildrenTree);

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

TreeNode* buildTree(const vector<int>& vec) {
	if (vec.empty() || vec[0] == INT_MIN) return nullptr;

	TreeNode* root = new TreeNode(vec[0]);
	queue<TreeNode*> q;
	q.push(root);

	for (size_t i = 1; i < vec.size(); i++) {
		TreeNode* parent = q.front();
		if (i % 2 == 1) { // Odd index, potential left child
			if (vec[i] != INT_MIN) {
				parent->left = new TreeNode(vec[i]);
				q.push(parent->left);
			}
		}
		else { // Even index, potential right child
			if (vec[i] != INT_MIN) {
				parent->right = new TreeNode(vec[i]);
				q.push(parent->right);
			}
			q.pop(); // Finished with this parent
		}
	}

	return root;
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
		cout << "]\n\n";
	}
}


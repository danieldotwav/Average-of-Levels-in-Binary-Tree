# Average of Levels in Binary Tree

## Introduction
This C++ program is designed to efficiently calculate the average values of each level in a binary tree. It primarily focuses on the `averageOfLevels` function, which showcases effective tree traversal and complex calculations.

## Main Algorithm: averageOfLevels

### Logic
The `averageOfLevels` function calculates the average values of nodes at each level in a binary tree. It uses a queue to perform a level-order traversal, summing node values at each level and then computing the average.

#### Implementation Details

- **Initial Checks:** The function begins by handling edge cases, such as an empty tree or a tree with only a root node.
- **Queue for Traversal:** A queue is used to facilitate level-order traversal. The root node is initially enqueued.
- **Looping Through Levels:** The function enters a while loop, which continues until there are no more nodes to process. Inside this loop, it performs the following steps:
  - **Determining Level Size:** The current size of the queue, which indicates the number of nodes at the current level, is recorded.
  - **Summing Node Values:** The function iterates over each node at this level, dequeuing each node, adding its value to a cumulative sum, and enqueueing its children (if they exist).
  - **Calculating Average:** After processing all nodes at a level, it calculates the average value for that level by dividing the cumulative sum by the number of nodes.
  - **Storing the Average:** This average is then stored in a result vector.

### Complexity Analysis

- **Time Complexity:** O(N), where N is the number of nodes in the tree. Each node is visited exactly once.
- **Space Complexity:** O(M), where M is the maximum number of nodes at any level in the tree. This space is required for the queue in the level-order traversal.

### Code Snippet
```cpp
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
```

## Helper Functions

In addition to the main algorithm, the program includes several utility functions for managing binary trees:

### 1. buildTree
Constructs a binary tree from a vector of integers. `INT_MIN` is used to represent null nodes, allowing for the construction of a range of binary tree configurations.

### 2. deleteTree
Safely deallocates the memory used by the binary tree. This function ensures efficient memory management and prevents memory leaks by recursively deleting all nodes in the tree.

### 3. printVector
A utility function to print the contents of a vector. It is primarily used for displaying the results of `averageOfLevels`, showing the average values at each level of the binary tree.

## Usage Instructions

To use this program:

1. Include the `TreeNode.h` header in your project.
2. Compile and run the provided C++ files.
3. Utilize the `buildTree` function to create a binary tree from a vector representation.
4. Pass the root of this tree to the `averageOfLevels` function to compute the average values at each level.
5. Use `printVector` to print these averages for verification.

## Test Cases

The `main` function includes several test cases to demonstrate the functionality of the program:

- Empty Tree
- Partially Filled Tree
- Single Node Tree
- Full Tree
- Left-skewed Tree
- Right-skewed Tree
- Tree with only left children
- Tree with only right children

Each case is designed to test different scenarios and tree structures.

## Contributions

Contributions to this project are welcome. To contribute:

1. Fork the repository.
2. Make your changes.
3. Submit a pull request with a clear description of your improvements.

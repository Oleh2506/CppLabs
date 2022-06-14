#include "functions.h"

void buildTree(TreeNode* tree) {
	std::cout << "Key of tree root: ";
	float key{ 0 };
	std::cin >> key;
	tree->setKey(key);

	std::cout << "Number of nodes to add: ";
	int numOfNodes{ 0 };
	std::cin >> numOfNodes;
	std::cout << "\n";

	for (int i{ 0 }; i < numOfNodes; ) {
		std::cout << "Path to node (to stop input enter negative value): ";
		std::vector<int> path;
		int currChildIdx{};
		std::cin >> currChildIdx;

		while (currChildIdx >= 0) {
			path.push_back(currChildIdx);
			std::cin >> currChildIdx;
		}

		float currKey{};
		std::cout << "Key node: ";
		std::cin >> currKey;

		if (tree->addNode(path, currKey)) {
			++i;
		}
		else {
			std::cout << "Unfortunately, path is wrong\n";
		}

		std::cout << "\nCurrent tree state:\n";
		tree->print();
		std::cout << "\n";
	}
}
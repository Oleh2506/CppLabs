// variant 2

#include <iostream>
#include "TreeNode.h"
#include "func.h"

int main()
{
	TreeNode* tree = new TreeNode;

	buildTree(tree);
	
	std::cout << "Arithmetic mean of keys of the nodes: " << tree->calculateArithmeticMean() << "\n";
	tree->deleteTree();
	tree = nullptr;
	
	return 0;
}
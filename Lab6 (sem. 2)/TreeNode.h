#pragma once

#include <vector>
#include <iostream>

class TreeNode {

private:
	float key_;
	std::vector<TreeNode* > children_;

public:
	TreeNode();
	TreeNode(const float key);
	~TreeNode();
	void addChild(const float key);
	void addChild(TreeNode* child);
	bool addNode(std::vector<int>& path, float key);
	float getKey() const;
	void setKey(const float key);
	std::vector<TreeNode* >& getChildren();
	TreeNode* getChild(const int idx);
	void print(const int depth = 0) const;

	// using tree-level-order traversal
	float calculateArithmeticMean();
	void deleteTree();
};


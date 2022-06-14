#include "TreeNode.h"
#include <queue>
#include <cassert>

TreeNode::TreeNode(const float key) : key_{ key } {}

TreeNode::TreeNode() : key_{ 0.0 } {}

TreeNode::~TreeNode() {}

void TreeNode::deleteTree() {
	if (this == nullptr) {
		return;
	}

	for (int i{ 0 }; i < this->children_.size(); ++i) {
		this->children_.at(i)->deleteTree();
	}

	delete this;
}

void TreeNode::addChild(const float key) {
	
	this->children_.push_back( new TreeNode(key) );
}

void TreeNode::addChild(TreeNode* child) {
	this->children_.push_back(child);
}

float TreeNode::getKey() const { return this->key_; }

void TreeNode::setKey(const float key) { this->key_ = key; }

std::vector<TreeNode* >& TreeNode::getChildren() { return this->children_; }

void TreeNode::print(const int depth) const {
	
	for (int i = 0; i < depth; ++i) {

		if (i != depth - 1) {
			std::cout << "    ";
		}
		else {
			std::cout << "|-- ";
		}
	}
	std::cout << this->key_ << std::endl;

	for (int i = 0; i < this->children_.size(); ++i) {

		TreeNode* child = this->children_.at(i);
		if (child) {
			(*child).print(depth + 1);
		}
	}
}

float TreeNode::calculateArithmeticMean() {

	float average{ 0.0 };
    int numOfElems{ 0 };

    std::queue<TreeNode*> q;
	if (this) {
		q.push(this);
	}

    while (!q.empty()) {

        int n{ (int)q.size() };

        while (n > 0)
        {
            TreeNode* p = q.front();
            q.pop();
            average += p->key_;
            numOfElems++;

            for (int i = 0; i < p->children_.size(); i++) {
				if (p->children_.at(i)) {
					q.push(p->children_.at(i));
				}
            }
            n--; 
        }
    }

    average /= (float)numOfElems;

    return average;
}

TreeNode* TreeNode::getChild(const int idx) {
	assert(idx < children_.size());

	return children_.at(idx);
}

bool TreeNode::addNode(std::vector<int>& path, float key) {
	TreeNode* currNode = this;
	int idx{ 0 };
	while (idx < path.size()) {

		if (currNode->getChildren().size() > path.at(idx)) {
			currNode = currNode->getChild(path.at(idx));
			++idx;
		}
		else {
			return false;
		}
	}

	currNode->addChild(key);
	return true;
}
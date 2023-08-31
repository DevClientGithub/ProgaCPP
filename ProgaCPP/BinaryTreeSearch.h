#pragma once

typedef long long int Int64;

class BinaryTreeSearch {
private:
	class Node {
	public:
		Int64 value;

		Node* right = nullptr;
		Node* left = nullptr;

		Node(const Int64& value) : value(value) {}
	};

public:
	Node* root = nullptr;

	void add(const Int64& value, Node*& node = this->root) {

	}
};
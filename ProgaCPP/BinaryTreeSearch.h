#pragma once

typedef long long int Int64;

template <typename T>
class BinaryTreeSearch {
private:
	class Node {
		Int64 key;
		T value;

		Node* right = nullptr;
		Node* left = nullptr;

		Node(const Int64& key, const T& value) : key(key), value(value) {}
	};

public:
	Node* root = nullptr;

	void add(const Int64& key, const T& value, const Node*& node = this->root) {
		if (node == nullptr) {
			node = new Node(key, value);
			return;
		}

		if (key > node->key) {

		}
	}
};
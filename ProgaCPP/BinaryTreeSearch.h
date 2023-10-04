#pragma once

template <typename T>
class BinaryTreeSearch {
private:
	typedef long long int Int64;

	class Node {
	private:
		Node* left = nullptr;
		Node* right = nullptr;
	public:
		const Int64 key;
		T value;

		friend class BinaryTreeSearch;

	Node(const Int64& key, const T& value): key(key), value(value) {}
	};

	Node* root = nullptr;

public:
	~BinaryTreeSearch() {
		this->clear();
	}

	Node* add(const Int64& key, const T& value, Node*& node) {
		if (node == nullptr) {
			node = new Node(key, value);
		}
		else if (key < node->key) {
			this->add(key, value, node->left);
		}
		else if(key > node->key) {
			this->add(key, value, node->right);
		}

		return node;
	}

	Node* add(const Int64& key, const T& value) {
		return this->add(key, value, this->root);
	}

	Node* search(const Int64& key, Node* node) {
		if (node->key == key) {
			return node;
		}

		if (key < node->key) {
			return this->search(key, node->left);
		}

		if (key > node->key) {
			return this->search(key, node->right);
		}

		return node;
	}

	Node* search(const Int64& key) {
		return this->search(key, this->root);
	}

	void clear(Node* node) {
		if (node != nullptr) {
			this->clear(node->left);
			this->clear(node->right);
			delete node;
		}
	}

	void clear() {
		this->clear(this->root);
	}
};
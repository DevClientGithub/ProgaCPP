#pragma once

template <typename T>

// �������� ������ ������
class BinaryTreeSearch {
private:
	// ���� ������
	class Node {
	private:
		Node* left = nullptr; // ����� ������� - ���� �������� ������
		Node* right = nullptr; // ������ ������� - ���� �������� ������
	public:
		const int64_t key; // ���� ��������, ������ ����������
		T value; // �������� � ����

		friend class BinaryTreeSearch;

	Node(const int64_t& key, const T& value): key(key), value(value) {}
	};

	Node* root; // ������ ������ - ������ �������

	// �����������
	Node* copy(const Node* node) const {
		if (!node) {
			return nullptr;
		}

		Node* newNode = new Node(node->key, node->value);
		newNode->left = this->copy(node->left);
		newNode->right = this->copy(node->right);

		return newNode;
	}

public:
	BinaryTreeSearch(const int64_t& key, const T& value): root(new Node(key, value)) {}

	BinaryTreeSearch(): root(nullptr) {}

	BinaryTreeSearch(const BinaryTreeSearch<T>& tree) {
		this->root = this->copy(tree.root);
	}

	~BinaryTreeSearch() {
		this->clear();
	}

	// �������� ����� ������� � ������
	Node* add(const int64_t& key, const T& value, Node*& node) {
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

	// �������� ����� ������� � ������
	Node* add(const int64_t& key, const T& value) {
		return this->add(key, value, this->root);
	}

	// ����� ������� � ������
	Node* search(const int64_t& key, const Node*& node) const {
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

	// ����� ������� � ������
	Node* search(const int64_t& key) const {
		return this->search(key, this->root);
	}

	// �������� ������� �� ������������� �����
	Node* getMax(const Node*& node) const {
		if (node->right != nullptr) {
			return this->getMax(node->right);
		}

		return node;
	}

	// �������� ������� �� ������������� �����
	Node* getMax() const {
		return this->getMax(this->root);
	}

	// �������� ������� �� ������������ �����
	Node* getMin(const Node*& node) const {
		if (node->left != nullptr) {
			return this->getMin(node->left);
		}

		return node;
	}

	// �������� ������� �� ������������ �����
	Node* getMin() const {
		return this->getMin(this->root);
	}

	// ������� ����� ������
	void clear(const Node*& node) {
		if (node != nullptr) {
			this->clear(node->left);
			this->clear(node->right);
			delete node;
		}
	}

	// ������� ����� ������
	void clear() {
		this->clear(this->root);
	}

	Node* operator[](const int64_t& key) const {
		return this->search(key, this->root);
	}
};
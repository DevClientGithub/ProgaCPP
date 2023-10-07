#pragma once

template <typename T>

// Бинарное Дерево Поиска
class BinaryTreeSearch {
private:
	// Узел дерева
	class Node {
	private:
		Node* left = nullptr; // Левый элемент - ключ которого меньше
		Node* right = nullptr; // Правый элемент - ключ которого больше
	public:
		const int64_t key; // Ключ элемента, всегда уникальный
		T value; // Значение у узла

		friend class BinaryTreeSearch;

	Node(const int64_t& key, const T& value): key(key), value(value) {}
	};

	Node* root; // Корень дерева - первый элемент

	// Копирование
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

	// Добавить новый элемент в дерево
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

	// Добавить новый элемент в дерево
	Node* add(const int64_t& key, const T& value) {
		return this->add(key, value, this->root);
	}

	// Найти элемент в дереве
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

	// Найти элемент в дереве
	Node* search(const int64_t& key) const {
		return this->search(key, this->root);
	}

	// Получить элемент по максимальному ключу
	Node* getMax(const Node*& node) const {
		if (node->right != nullptr) {
			return this->getMax(node->right);
		}

		return node;
	}

	// Получить элемент по максимальному ключу
	Node* getMax() const {
		return this->getMax(this->root);
	}

	// Получить элемент по минимальному ключу
	Node* getMin(const Node*& node) const {
		if (node->left != nullptr) {
			return this->getMin(node->left);
		}

		return node;
	}

	// Получить элемент по минимальному ключу
	Node* getMin() const {
		return this->getMin(this->root);
	}

	// Очистка всего дерева
	void clear(const Node*& node) {
		if (node != nullptr) {
			this->clear(node->left);
			this->clear(node->right);
			delete node;
		}
	}

	// Очистка всего дерева
	void clear() {
		this->clear(this->root);
	}

	Node* operator[](const int64_t& key) const {
		return this->search(key, this->root);
	}
};
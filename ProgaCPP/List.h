#pragma once

#include <iostream>

using namespace std;

template <typename T>
class List {
private:
	class Node {
	public:
		Node* next;
		T data;

		Node(const T& data, const Node*& next = nullptr) {
			this->data = data;
			this->next = next;
		}
	};

	Node* head;
	size_t size;

public:
	List() {
		this->head = nullptr;
		this->size = 0;
	}

	List(const initializer_list<T>& items) {
		for (const T& item : items) {
			this->push(item);
		}
	}

	~List() {
		this->clear();
	}

	size_t length() const {
		return this->size;
	}

	List<T>& push(const T& item) {
		if (this->head == nullptr) {
			this->head = new Node(item);
		}
		else {
			Node* current = this->head;

			while (current->next != nullptr) {
				current = current->next;
			}

			current->next = new Node(item);
		}

		this->size++;

		return *this;
	}

	List<T>& shift() {
		Node* temp = this->head;

		head = head->next;

		delete temp;

		this->size--;

		return *this;
	}


	void clear() {
		while (this->size) {
			this->shift();
		}
	}

	T& operator[](const size_t& index) {
		if (index >= this->size) {
			throw std::runtime_error("U use very big index");
		}

		size_t counter = 0;
		Node* current = this->head;

		while (current != nullptr) {
			if (counter == index) {
				return current->data;
			}

			current = current->next;
			counter++;
		}
	}
};
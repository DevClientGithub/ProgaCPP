#pragma once

#include <iostream>

using namespace std;

template <typename T>
class List {
private:
	class Node {
	public:
		Node* next = nullptr;
		T data;

		Node(const T& data) {
			this->data = data;
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

	size_t length() {
		return this->size;
	}

	void push(const T& item) {
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
	}
};
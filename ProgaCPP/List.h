#pragma once

#include <iostream>

using namespace std;

template <typename T>
class List { //  ласс List, €вл€етс€ списком.
private:
	class Node { //  ласс Node - элемент списка.
	public:
		Node* next; // ”казатель на следующий элемент в коллекции
		T data; // ƒанные у нынешнго элемента

		Node(const T& data, Node* next = nullptr) {
			this->data = data;
			this->next = next;
		}
	};

	Node* head; // ”казатель на первый элемент в коллекции
	size_t size; // –азмер данной коллекции

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

	// ћетод возвращающий длинну коллекции
	size_t length() const noexcept {
		return this->size;
	}

	// ћетод добавл€ющий новый элемент коллекции в конец.
	List<T>& push(const T& item) {
		if (this->head == nullptr) {
			this->head = new Node(item);
		}
		else {
			Node* current = this->head; // Ќынешний элемент

			while (current->next != nullptr) {
				current = current->next;
			}

			current->next = new Node(item);
		}

		this->size++;

		return *this;
	}

	// ћетод удал€ющий элемент в конце коллекции.
	List<T>& pop() {
		if (this->size == 0) {
			return *this;
		}

		if (this->size == 1) {
			return this->shift();
		}

		Node* current = this->head; // Ќынешний элемент

		while (current->next->next != nullptr) {
			current = current->next;
		}

		delete current->next;
		current->next = nullptr;

		this->size--;

		return *this;
	}

	// ћетод добавл€ющий новый элемент в начало коллекции
	List<T>& unshift(const T& item) {
		Node* add = new Node(item, this->head); // Ќовый элемент

		this->head = add;
		this->size++;

		return *this;
	}

	// ћетод удал€ющий элемент из начала коллекции
	List<T>& shift() {
		Node* temp = this->head; // ¬ременный указатель на начальный элемент.

		head = head->next;

		delete temp;

		this->size--;

		return *this;
	}

	// ћетод удал€ющий все элементы в коллекции.
	void clear() {
		while (this->size) {
			this->shift();
		}
	}

	T& operator[](const size_t& index) const {
		if (index >= this->size) {
			throw runtime_error("U use very big index");
		}

		size_t counter = 0; // —чЄтчик, в случае если он равен индексу, то вернут элемент current
		Node* current = this->head; // Ќынешний элемент

		while (current != nullptr) {
			if (counter == index) {
				return current->data;
			}

			current = current->next;
			counter++;
		}
	}
};
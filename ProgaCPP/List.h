#pragma once

#include <iostream>

using namespace std;

template <typename T>
class List { // Класс List, является списком.
private:
	class Node { // Класс Node - элемент списка.
	public:
		Node* next; // Указатель на следующий элемент в коллекции
		T data; // Данные у нынешнго элемента

		Node(const T& data, Node* next = nullptr) {
			this->data = data;
			this->next = next;
		}
	};

	class Iterator {
	public:
		Node* current;

		Iterator(Node* node) : current(node) {}

		T& operator*() const {
			return this->current->data;
		}

		Iterator& operator++() {
			current = current->next;
			return *this;
		}

		bool operator!=(const Iterator& other) const {
			return current != other.current;
		}
	};

	Node* head; // Указатель на первый элемент в коллекции
	size_t size; // Размер данной коллекции

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

	List(const List<T>& other) { // TODO: Оптимизируй.
		for (const T& item : other) {
			this->push(item);
		}
	}

	~List() {
		this->clear();
	}

	// Метод возвращающий длинну коллекции
	size_t length() const noexcept {
		return this->size;
	}

	// Метод добавляющий новый элемент коллекции в конец.
	List<T>& push(const T& item) {
		if (this->head == nullptr) {
			this->head = new Node(item);
		}
		else {
			Node* current = this->head; // Нынешний элемент

			while (current->next != nullptr) {
				current = current->next;
			}

			current->next = new Node(item);
		}

		this->size++;

		return *this;
	}

	// Метод удаляющий элемент в конце коллекции.
	List<T>& pop() {
		if (this->size == 0) {
			return *this;
		}

		if (this->size == 1) {
			return this->shift();
		}

		Node* current = this->head; // Нынешний элемент

		while (current->next->next != nullptr) {
			current = current->next;
		}

		delete current->next;
		current->next = nullptr;

		this->size--;

		return *this;
	}

	// Метод добавляющий новый элемент в начало коллекции
	List<T>& unshift(const T& item) {
		Node* add = new Node(item, this->head); // Новый элемент

		this->head = add;
		this->size++;

		return *this;
	}

	// Метод удаляющий элемент из начала коллекции
	List<T>& shift() {
		Node* temp = this->head; // Временный указатель на начальный элемент.

		head = head->next;

		delete temp;

		this->size--;

		return *this;
	}

	// Метод удаляющий все элементы в коллекции.
	void clear() {
		while (this->size) {
			this->shift();
		}
	}

	Iterator begin() {
		return Iterator(head);
	}

	Iterator end() {
		return Iterator(nullptr);
	}
};
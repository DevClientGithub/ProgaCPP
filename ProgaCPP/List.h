#pragma once

#include <iostream>

using namespace std;

template <typename T>
class List { // ����� List, �������� �������.
private:
	class Node { // ����� Node - ������� ������.
	public:
		Node* next; // ��������� �� ��������� ������� � ���������
		T data; // ������ � �������� ��������

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

	Node* head; // ��������� �� ������ ������� � ���������
	size_t size; // ������ ������ ���������

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

	List(const List<T>& other) { // TODO: �����������.
		for (const T& item : other) {
			this->push(item);
		}
	}

	~List() {
		this->clear();
	}

	// ����� ������������ ������ ���������
	size_t length() const noexcept {
		return this->size;
	}

	// ����� ����������� ����� ������� ��������� � �����.
	List<T>& push(const T& item) {
		if (this->head == nullptr) {
			this->head = new Node(item);
		}
		else {
			Node* current = this->head; // �������� �������

			while (current->next != nullptr) {
				current = current->next;
			}

			current->next = new Node(item);
		}

		this->size++;

		return *this;
	}

	// ����� ��������� ������� � ����� ���������.
	List<T>& pop() {
		if (this->size == 0) {
			return *this;
		}

		if (this->size == 1) {
			return this->shift();
		}

		Node* current = this->head; // �������� �������

		while (current->next->next != nullptr) {
			current = current->next;
		}

		delete current->next;
		current->next = nullptr;

		this->size--;

		return *this;
	}

	// ����� ����������� ����� ������� � ������ ���������
	List<T>& unshift(const T& item) {
		Node* add = new Node(item, this->head); // ����� �������

		this->head = add;
		this->size++;

		return *this;
	}

	// ����� ��������� ������� �� ������ ���������
	List<T>& shift() {
		Node* temp = this->head; // ��������� ��������� �� ��������� �������.

		head = head->next;

		delete temp;

		this->size--;

		return *this;
	}

	// ����� ��������� ��� �������� � ���������.
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
#pragma once

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

};
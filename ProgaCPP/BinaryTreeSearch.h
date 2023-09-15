#pragma once

class BinaryTreeSearch {
private:
	typedef long long int Int64;

	class Node {
	public:
		Int64 value;

		Node* right = nullptr;
		Node* left = nullptr;

		Node(const Int64& value) : value(value) {}
	};
};
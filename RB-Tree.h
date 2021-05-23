#pragma once
#include"Iterator.h"
#include"Stack.h"
#include "Stack.cpp"

enum Color {Red, Black};

template <class Key, class Value>
class RedBlackTree {
private:
	class Node {
	public:
		Key find;
		Value value;
		Node* parent;
		Node* left;
		Node* right;
		Color color;
		Node(Key find, Value value, Node* left = NULL, Node* right = NULL, Node* parent = NULL, Color color = Red) {
			this->find = find;
			this->value = value;
			this->parent = parent;
			this->left = left;
			this->right = right;
			this->color = color;
		}
		~Node() {};
	};

	class dft_Iterator 
	{
	private:
		Stack<Node*> Stack;
		Node* IterCurrent;
		Node* nil;
	public:
		dft_Iterator(Node* cur, Node* nill) {
			IterCurrent = cur;
			nil = nill;
		};
		Node* next() {
			Node* temp = IterCurrent;
			if (IterCurrent->right != nil) {
				Stack.push(IterCurrent->right);
			}
			if (IterCurrent->left != nil) {
				IterCurrent = IterCurrent->left;
			}
			else {
				if (!Stack.IsEmpty()) {
					IterCurrent = Stack.pop();
				}
				else {
					IterCurrent = nil;
				}
			}
			return temp;
		};
		bool has_next() {
			if (IterCurrent != nil) {
				return true;
			}
			return false;
		};
		~dft_Iterator() {}
	};

	Node* root;
	Node* nil;
	int size;

	void recovery(Node*);
	void leftRotate(Node*);
	void rightRotate(Node*);
	void recoveryRemove(Node* x);

public:
	RedBlackTree() {
		nil = new Node(0, 0, NULL, NULL, NULL, Black);
		root = nil;
		size = 0;
	}
	~RedBlackTree() { 
		delete root;
		clear();  
	}

	void insert(Key, Value);
	void remove(Key);
	Value find(Key);
	void clear();
	Key* get_keys();
	Value* get_values();
	void print(); 
	int get_size();
	bool get_color(Key);
	friend class Node;
};

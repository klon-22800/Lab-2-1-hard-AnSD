#pragma once
#include<iostream>
#include <random>

using namespace std; 

namespace Polynomial {
	int random(int a, int b) {
		std::random_device random_device; // Источник энтропии.
		std::mt19937 generator(random_device()); // Генератор случайных чисел.
		// (Здесь берется одно инициализирующее значение, можно брать больше)
		std::uniform_int_distribution<> distribution(a, b); // Равномерное распределение [a, b]
		int x = distribution(generator); // Случайное число.
		return x;
	}

	struct Node {
		double k;
		int pow;
		Node* prev;
		Node* next;
		Node(){
			k = 0;
			pow = 0;
			prev = nullptr;
			next = nullptr;
		}
		Node(double k_other, int pow_other) {
			k = k_other;
			pow = pow_other;
			prev = nullptr;
			next = nullptr;
		}
	};

	class DoubleLinkedList {
	private:
		Node* _head;
		Node* _tail;

	public:
		DoubleLinkedList() {
			_head = nullptr;
			_tail = nullptr;
		}

		DoubleLinkedList(const DoubleLinkedList& other) {
			_head = nullptr;
			Node* temp = other.get_head();
			while (temp != nullptr) {
				insert_at_tail(temp->k, temp->pow);
				temp = temp->next;
			}
		}

		DoubleLinkedList(int size, int max_pows) {
			_head = nullptr;
			for (int i = 0; i < size; i++) {
				insert_at_tail(random(-100, 100), random(0, max_pows));
			}
		}

		~DoubleLinkedList() {
			Node* temp;
			while (_head != nullptr) {
				temp = _head->next;
				delete _head;
				_head = temp;
			}
			cout << _head;
		}

		Node* get_head() const {
			return _head;
		}
		Node* get_tail() const {
			return _tail;
		}

		void insert_at_tail(Node other) {
			Node* newNode = new Node(other.k, other.pow);
			newNode->next = nullptr;
			if (_head == nullptr) {
				newNode->prev = nullptr;
				_head = newNode;
				_tail = newNode;
			}
			else {
				newNode->prev = _tail;
				_tail->next = newNode;
				_tail = newNode;
			}
		}

		void insert_at_tail(double k, int pow) {
			Node* newNode = new Node;
			newNode->k = k;
			newNode->pow = pow;
			newNode->next = nullptr;
			if (_head == nullptr) {
				newNode->prev = nullptr;
				_head = newNode;
				_tail = newNode;
			}
			else {
				newNode->prev = _tail;
				_tail->next = newNode;
				_tail = newNode;
			}
		}

		void insert_at_tail(const DoubleLinkedList& other) {
			if (other.get_head() == nullptr) {
				return;
			}
			Node* cur = other.get_head();
			while (cur != nullptr) {
				Node* newNode = new Node;
				newNode->k = cur->k;
				newNode->pow = cur->pow;
				newNode->prev = nullptr;
				newNode->next = nullptr;

				insert_at_tail(*newNode);
				cur = cur->next;
			}
		}

		void insert_at_head(Node other) {
			Node* newNode = new Node(other.k, other.pow);
			newNode->next = _head;
			if (_head != nullptr)
				_head->prev = newNode;
			_head = newNode;
			_tail = _head;
		}

		void insert_at_head(double k, int pow) {
			Node* newNode = new Node;
			newNode->k = k;
			newNode->pow = pow;
			newNode->next = _head;
			if (_head != nullptr)
				_head->prev = newNode;
			_head = newNode;
			_tail = _head;
		}
		void insert_at_head(const DoubleLinkedList& other) {
			if (other.get_head() == nullptr) {
				return;
			}
			Node* cur = other.get_head();
			while (cur != nullptr) {
				Node* newNode = new Node;
				newNode->k = cur->k;
				newNode->pow = cur->pow;
				newNode->prev = nullptr;
				newNode->next = nullptr;

				insert_at_head(*newNode);
				cur = cur->next;
			}
		}

		DoubleLinkedList& operator=(const DoubleLinkedList& other) {
			_head = nullptr;
			Node* temp = other.get_head();
			while (temp != nullptr) {
				insert_at_tail(temp->k, temp->pow);
				temp = temp->next;
			}
			return *this;
		}
	};
	ostream& operator<<(ostream& stream, DoubleLinkedList& a) {
		Node* temp = a.get_head();
		while (temp != nullptr) {
			cout << temp->k << " " << temp->pow << endl;
			temp = temp->next;
		}
		return stream;
	}
}


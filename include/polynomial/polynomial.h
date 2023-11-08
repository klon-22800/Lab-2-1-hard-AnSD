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
		if (x == 0) {
			random(a, b);
		}
		else {
			return x;
		}
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
		void operator=(Node& rhs) {
			k = rhs.k;
			pow = rhs.pow;
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
		}

		Node* get_head() const {
			return _head;
		}
		Node* get_tail() const {
			return _tail;
		}

		void insert_at_tail(Node other) {
			Node* newNode = new Node(other.k, other.pow);
			if (other.k == 0) {
				return;
			}
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
			if (k == 0) {
				return;
			}
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
			if (other.k == 0) {
				return;
			}
			Node* newNode = new Node(other.k, other.pow);
			newNode->next = nullptr;
			if (_head == nullptr) {
				_head = newNode;
				_tail = newNode;
			}
			else {
				newNode->next = _head;
				_head->prev = newNode;
				_head = newNode;
			}
		}

		void insert_at_head(double k, int pow) {
			if (k == 0) {
				return;
			}
			Node* newNode = new Node;
			newNode->k = k;
			newNode->pow = pow;
			newNode->next = nullptr;
			if (_head == nullptr) {
				_head = newNode;
				_tail = newNode;
			}
			else{
				newNode->next = _head;
				_head->prev = newNode;
				_head = newNode;
			}
			
		}
		void insert_at_head(const DoubleLinkedList& other) {
			if (other.get_head() == nullptr) {
				return;
			}
			Node* cur = other.get_tail();
			while (cur != nullptr) {
				Node* newNode = new Node;
				newNode->k = cur->k;
				newNode->pow = cur->pow;
				newNode->prev = nullptr;
				newNode->next = nullptr;

				insert_at_head(*newNode);
				cur = cur->prev;
			}
		}

		void pop_head() {
			if (_head == nullptr) {
				return;
			}

			Node* pop_node = _head;

			if (_head == _tail) {
				_head = nullptr;
				_tail = nullptr;
			}
			else {
				_head = _head->next;
				_head->prev = nullptr;
			}
			pop_node->next = nullptr;
			if (_head == nullptr) {
				_tail = nullptr;
			}
		}

		void pop_tail() {
			if (_head == nullptr) {
				return;
			}
			Node* pop_node = _tail;
			if (_head == _tail) {
				_head = nullptr;
				_tail = nullptr;
			}
			else {
				_tail = _tail->prev;
				_tail->next = nullptr;
			}
			pop_node->prev = nullptr;

			if (_tail == nullptr) {
				_head = nullptr;
			}
		}
		void pop(int index) {
			if (_head == nullptr) {
				throw std::out_of_range("List is empty");
			}
			if (index < 0) {
				throw std::invalid_argument("incorrect index");
			}
			Node* cur = _head;
			if (index == 0) {
				_head = _head->next;
				if (_head != nullptr) {
					_head->prev = nullptr;
				}
				delete cur;
				return;
			}
			int cur_index = 0;
			while (cur != nullptr && cur_index < index) {
				cur = cur->next;
				cur_index++;
			}
			if (cur != nullptr && cur_index == index) {
				Node* prev = cur->prev;
				prev->next = cur->next;

				if (cur->next != nullptr) {
					cur->next->prev = prev;
				}

				delete cur;
			}
		}
		void delete_node(const Node other) {
			if (_head == nullptr) {
				return;
			}
			Node* cur = _head;
			while (cur != nullptr) {
				if (cur->k == other.k && cur->pow == other.pow) {
					Node* remove_node = cur;

					if (cur == _head) {
						_head = cur->next;
					}

					if (cur == _tail) {
						_tail = cur->prev;
					}
					if (cur->prev != nullptr) {
						cur->prev->next = cur->next;
					}

					if (cur->next != nullptr) {
						cur->next->prev = cur->prev;
					}
					cur = cur->next;
					delete remove_node;
				}
				else {
					cur = cur->next;
				}
			}
			return;
		}
		void normal_form() {
			Node* cur = _head;
			int index = 0;
			while (cur != nullptr) {
				Node* cur2 = cur->next;
				int index_2 = index + 1;
				while (cur2 != nullptr) {
					if (cur->pow == cur2->pow) {
						cur->k += cur2->k;
						cur2 = cur2->next;
						pop(index_2);
					}
					else {
						cur2 = cur2->next;
						index_2++;
					}
				}
				index_2 = 0;
				cur = cur->next;
				index++;
			}
			return;
		}
		void sort() {
			if (_head == nullptr) {
				return;
			}
			Node* cur = _head->next;
			while (cur != nullptr) {
				Node* tmp = cur;
				int value = tmp->pow;
				int value_k = tmp->k;
				Node* prev = tmp->prev;

				while (prev != nullptr && prev->pow < value) {
					tmp->pow = prev->pow;
					tmp->k = prev->k;
					tmp = prev;
					prev = prev->prev;
				}
				tmp->pow = value;
				tmp->k = value_k;
				cur = cur->next;
			}
		}
		double value(double x) {
			double sum = 0;
			Node* cur = _head;
			while (cur != nullptr) {
				sum += cur->k*pow(x, cur->pow);
				cur = cur->next;
			}
			return sum;
		}
		void print_n() {
			Node* temp = _head;
			while (temp != nullptr){
				if (temp->next == nullptr) {
					cout << temp->k << "x^" << temp->pow;
					return;
				}
				if (temp->next->k > 0) {
					cout << temp->k << "x^" << temp->pow << "+";
				}
				if (temp->next->k < 0) {
					cout << temp->k << "x^" << temp->pow;
				}
				temp = temp->next;
			}
			return;

		}

		Node& operator()(int index) const {
			Node* cur = _head;
			int cur_index = 0;
			while (cur != nullptr && cur_index < index) {
				cur = cur->next;
				cur_index++;
			}
			if (cur != nullptr && cur_index == index)
			{
				return *cur;
			}
			throw std::out_of_range("Index out of range");
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
			stream << temp->k << " " << temp->pow<<endl;
			temp = temp->next;
		}
		return stream;
	}
	ostream& operator<<(ostream& stream, Node& a) {
		stream << a.k << " " << a.pow << endl;
		return stream;
	}

	double value(Node* head,int x) {
		double sum = 0;
		while (head != nullptr) {
			sum += head->k * pow(x, head->pow);
			head = head->next;
		}
		return sum;
	}
}
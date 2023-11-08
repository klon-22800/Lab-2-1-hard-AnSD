#include<iostream>
#include<polynomial/polynomial.h>

using namespace std;
using namespace Polynomial;

int main(){
	DoubleLinkedList a(10, 10);
	cout << a<< endl;
	Node b(100, 100);
	a(0) = b;
	cout << a<<endl;
	a.normal_form();
	cout << a << endl;
	a.sort();
	a.print_n();
	cout <<"="<< value(a.get_head(), 5);
}
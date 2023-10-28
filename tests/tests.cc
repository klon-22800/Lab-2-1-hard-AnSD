#include <gtest/gtest.h>
#include <polynomial/polynomial.h>
using namespace std;
using namespace Polynomial;
TEST(FunctionsTests, Constuctor) {
    DoubleLinkedList b;
    Node a(10, 20);
    b.insert_at_tail(2,0);
    b.insert_at_head(2,2);
    b.insert_at_head(a);
    cout << b;
    a.pow = 100;
    cout << b;
}
TEST(FunctionsTests, ConstuctorByCopy) {
    DoubleLinkedList b;
    b.insert_at_tail(2, 3);
    b.insert_at_head(1, 2);
    b.insert_at_head(1, 3);
    b.insert_at_tail(2, 2);
    DoubleLinkedList a(b);
    a.insert_at_head(2, 0);
    a.insert_at_tail(2, 0);
    a = b;
    cout << a;
    cout << b;
    // Assert
}
TEST(FunctionsTests, ConstuctorByRandom) {
    DoubleLinkedList b(10, 10);
    cout << b;
    // Assert
}

TEST(FunctionsTests, insert_at_tail_DoubLeinkedList) {
    DoubleLinkedList a;
    a.insert_at_head(2, 1);
    a.insert_at_head(2, 1);
    a.insert_at_head(2, 1);
    DoubleLinkedList b;
    b.insert_at_tail(1, 0);
    b.insert_at_head(1, 0);
    b.insert_at_head(1, 0);
    DoubleLinkedList c;
    c.insert_at_tail(b);
    c.insert_at_head(a);
    cout << a;
    cout << b<<endl;
    cout << c;
    // Assert
}
TEST(FunctionsTests, pop_head) {
    DoubleLinkedList a;
    Node b(1, 1);
    a.insert_at_head(2, 1);
    a.insert_at_head(2, 1);
    a.insert_at_head(2, 1);
    a.insert_at_head(b);
    cout << a;
    a.pop_head();
    a.pop_head();
    a.pop_head();
    a.pop_head();
    cout << a;
    // Assert
}
TEST(FunctionsTests, pop_tail) {
    DoubleLinkedList a;
    Node b(1, 1);
    a.insert_at_head(2, 1);
    a.insert_at_head(2, 1);
    a.insert_at_head(2, 1);
    a.insert_at_head(b);
    cout << a;
    a.pop_tail();
    a.pop_tail();
    a.pop_tail();
    a.pop_tail();
    cout << a;
    // Assert
}
TEST(FunctionsTests, delete_node) {
    DoubleLinkedList a;
    Node deleted(0, 1);
    Node b(1, 1);
    a.insert_at_head(2, 1);
    a.insert_at_head(2, 1);
    a.insert_at_head(2, 1);
    a.insert_at_head(b);
    cout << a<<endl;
    a.delete_node(deleted);
    cout << a;
    // Assert
}
TEST(FunctionsTests, operator_by_index) {
    DoubleLinkedList a;
    Node b(1, 1);
    a.insert_at_head(2, 1);
    a.insert_at_head(2, 1);
    a.insert_at_head(2, 1);
    cout << a << endl;
    a(2) = b;
    cout << a;
    cout << a(2);
    // Assert
}
TEST(FunctionsTests, pop_by_index) {
    DoubleLinkedList a;
    Node b(1, 1);
    a.insert_at_head(2, 1);
    a.insert_at_head(2, 1);
    a.insert_at_head(2, 1);
    cout << a << endl;
    a.pop(2);
    a.pop(1);
    cout << a;
    // Assert
}
TEST(FunctionsTests, normal_view) {
    DoubleLinkedList a;
    Node b(1, 1);
    a.insert_at_head(1, 1);
    a.insert_at_head(2, 1);
    a.insert_at_head(1, 2);
    a.insert_at_head(2, 2);
    a.insert_at_head(3, 1);
    a.insert_at_head(3, 2);
    a.normal_form();
    a.sort();
    cout << a;
    // Assert
}
TEST(FunctionsTests, value_pol) {
    DoubleLinkedList a;
    Node b(1, 1);
    a.insert_at_head(1, 1);
    a.insert_at_head(2, 1);
    a.insert_at_head(1, 2);
    a.insert_at_head(2, 2);
    a.insert_at_head(3, 1);
    a.insert_at_head(3, 2);
    a.normal_form();
    a.sort();
    double res = a.value(5);
    cout << res<<endl;
    // Assert
}
TEST(FunctionsTests, print_n) {
    DoubleLinkedList a;
    Node b(1, 1);
    a.insert_at_head(1, 1);
    a.insert_at_head(2, 2);
    a.insert_at_head(3, 3);
    a.insert_at_head(4, 4);
    a.insert_at_head(5, 5);
    a.insert_at_head(6, 6);
    a.print_n();
    // Assert
}
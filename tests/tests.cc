#include <gtest/gtest.h>
#include <polynomial/polynomial.h>
using namespace std;
using namespace Polynomial;
TEST(FunctionsTests, Constuctor) {
    DoubleLinkedList b;
    Node a(10, 20);
    b.insert_at_tail(0,0);
    b.insert_at_head(0,2);
    b.insert_at_head(a);
    cout << b;
    a.pow = 100;
    cout << b;
    
    // Assert
}
TEST(FunctionsTests, ConstuctorByCopy) {
    DoubleLinkedList b;
    b.insert_at_tail(2, 3);
    b.insert_at_head(1, 2);
    b.insert_at_head(1, 3);
    b.insert_at_tail(2, 2);
    DoubleLinkedList a(b);
    a.insert_at_head(0, 0);
    a.insert_at_tail(0, 0);
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
    a.insert_at_head(0, 1);
    a.insert_at_head(0, 1);
    a.insert_at_head(0, 1);
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

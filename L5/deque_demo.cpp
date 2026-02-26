#include <iostream>
#include <deque>

// basic template definition from the standard library (as defined in <deque>):
//
// namespace std {
//     template <class T,
//               class Allocator = allocator<T> >
//     class deque {
//         // implementation-defined members
//     };
// }
//
// The class provides the usual container operations plus some deque-specific
// member functions such as push_front, pop_front, etc.

int main() {
    std::deque<int> deq{5, 6};     // {5, 6}
    std::cout << "initial: ";
    for (int v : deq) std::cout << v << ' ';
    std::cout << '\n';

    deq.push_front(3);             // {3, 5, 6}
    std::cout << "after push_front(3): ";
    for (int v : deq) std::cout << v << ' ';
    std::cout << '\n';

    deq.pop_back();                // {3, 5}
    std::cout << "after pop_back(): ";
    for (int v : deq) std::cout << v << ' ';
    std::cout << '\n';

    deq[1] = -2;                   // {3, -2}
    std::cout << "after deq[1] = -2: ";
    for (int v : deq) std::cout << v << ' ';
    std::cout << '\n';

    // other useful deque methods
    deq.push_back(10);
    deq.push_front(1);
    std::cout << "after push_back(10) and push_front(1): ";
    for (int v : deq) std::cout << v << ' ';
    std::cout << '\n';

    std::cout << "size = " << deq.size() << " front = " << deq.front()
              << " back = " << deq.back() << '\n';

    return 0;
}
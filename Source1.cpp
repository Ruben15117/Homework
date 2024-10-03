#include <iostream>
using namespace std;

struct node {
    node* next;
    node* prev;
    int val;
};

class list {
    node* head;
    node* tail;
public:
    list() {
        head = nullptr;
        tail = nullptr;
    }
    void add(int value) {
        node* newNode = new node;
        newNode->val = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    // if node is nullptr add as head;
    void addAfter(int value, node* where) {
        node* newNode = new node;
        newNode->val = value;
        if (where == nullptr) {
            newNode->next = head;
            head = newNode;
        }
        else {
            newNode->prev = where;
            newNode->next = where->next;
            where->next = newNode;
            //updating prev of the next
            if (newNode->next != nullptr) {
                newNode->next->prev = newNode;
            }
        }
        if (tail == nullptr || tail == where) {
            tail = newNode;
        }
    }
    void remove(node*);
    node* find(int value) {
        node* curNode = head;
        while (curNode != nullptr && curNode->val != value) {
            curNode = curNode->next;
        }
        return curNode;
    }

    void print();

};





int main() {
    int k;
    cin >> k;
    std::cout << "123\n";
    list a;
    a.add(10);
    list b;
    b.addAfter(10, nullptr);
    a.addAfter(10, nullptr);
    std::cout << "15\n";

    return 0;
}
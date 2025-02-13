#pragma once
#include <iostream>
#include "Mem.h"
#include "List2Abstract.h"



class List2 : public AbstractList2
{
    typedef struct Node : public GroupList::Node
    {
        Node* prev_Node;
        Node* next_Node;
    } Node;

public:
    Node* head;
    Node* tail;

    List2(MemoryManager& mem);
    ~List2();

    /*class List2Iterator : public Container::Iterator
    {
    private:
        Node* current = nullptr;

    public:
        List2Iterator(Node* head) : current(head) {}
        ~List2Iterator() {}
        void* getElement(size_t& size);
        bool hasNext();
        void goToNext();
        bool equals(Iterator* right);
    };*/

    int push_back(void* elem, size_t elemSize);
    int push_front(void* elem, size_t elemSize);
    void pop_back();
    void pop_front();
    void* front(size_t& size);
    void* back(size_t& size);
    int insert(Iterator* iter, void* elem, size_t elemSize);
    int size();
    size_t max_bytes();
    Iterator* find(void* elem, size_t size);
    Iterator* newIterator();
    void remove(Iterator* iter);
    void clear();
    bool empty();

    void prfromhead(); // my func
    void prfromtail(); // my func
};

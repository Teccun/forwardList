#include <iostream>
#include "List2.h"

List2::List2(MemoryManager& mem) : AbstractList2(mem)
{
    head = nullptr;
    tail = nullptr;
}

List2::~List2()
{
    clear();
}

int List2::push_back(void* elem, size_t elemSize)
{

    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = _memory.allocMem(elemSize);
    memcpy(newnode->data, elem, elemSize);
    newnode->data_Size = elemSize;

    if (head == nullptr && tail == nullptr)
    {
        newnode->next_Node = nullptr;
        newnode->prev_Node = nullptr;
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->prev_Node = tail;
        newnode->next_Node = nullptr;
        tail->next_Node = newnode;
        tail = newnode;
    }
    return 0;
}

int List2::push_front(void* elem, size_t elemSize)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = _memory.allocMem(elemSize);
    memcpy(newnode->data, elem, elemSize);
    newnode->data_Size = elemSize;

    if (head == nullptr && tail == nullptr)
    {
        newnode->next_Node = nullptr;
        newnode->prev_Node = nullptr;
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next_Node = head;
        newnode->prev_Node = nullptr;
        head->prev_Node = newnode;
        head = newnode;
    }

    return 0;
}

void List2::pop_back()
{
    Node* current = tail;
    if (current != nullptr)
    {
        Node* prev = current->prev_Node;
        prev->next_Node = nullptr;
        _memory.freeMem(current->data);
        delete (current);
        tail = prev;
    }
}

void List2::pop_front()
{
    Node* current = head;
    if (current != nullptr)
    {
        Node* next = current->next_Node;
        next->prev_Node = nullptr;
        _memory.freeMem(current->data);
        delete (current);
        head = next;
    }
}

void* List2::front(size_t& size)
{
    if (head == nullptr)
    {
        size = 0;
        return nullptr;
    }
    size = head->data_Size;
    return head->data;
}

void* List2::back(size_t& size)
{
    if (tail == nullptr)
    {
        size = 0;
        return nullptr;
    }

    size = tail->data_Size;
    return tail->data;
}

int List2::insert(Iterator* iter, void* elem, size_t elemSize)
{
    return 0;
}

int List2::size()
{
    int quant = 0;
    if (head == nullptr && tail == nullptr)
    {
        return quant;
    }
    Node* current = head;
    while (current != nullptr)
    {
        quant++;
        current = current->next_Node;
    }
    return quant;
}

size_t List2::max_bytes()
{
    return _memory.size();
}

GroupList::Iterator* List2::find(void* elem, size_t size)
{
    return nullptr;
}

GroupList::Iterator* List2::newIterator()
{
    return nullptr;
}

void List2::remove(Iterator* iter)
{
}

void List2::clear()
{
    Node* curr = head;
    while (curr != nullptr)
    {
        Node* next = curr->next_Node;
        _memory.freeMem(curr->data);
        delete curr;
        curr = next;
    }
    head = nullptr;
    tail = nullptr;
}

bool List2::empty()
{
    if (head == nullptr && tail == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//void* List2::List2Iterator::getElement(size_t& size)
//{
//    return nullptr;
//}
//
//bool List2::List2Iterator::hasNext()
//{
//    return false;
//}
//
//void List2::List2Iterator::goToNext()
//{
//}
//
//bool List2::List2Iterator::equals(Iterator* right)
//{
//    return false;
//}

void List2::prfromhead()
{
    Node* current = head;
    if (current == nullptr)
    {
        return;
    }
    while (current != NULL)
    {
        cout << *((int*)current->data) << " ";
        current = current->next_Node;
    }
    cout << endl;
}

void List2::prfromtail()
{
    Node* current = tail;
    if (current == nullptr)
    {
        return;
    }
    while (current != NULL)
    {
        cout << *((int*)current->data) << " ";
        current = current->prev_Node;
    }

    cout << endl;
}

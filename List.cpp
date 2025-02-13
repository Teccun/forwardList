#include "List.h"

List::List(MemoryManager& mem) : AbstractList(mem)
{
	head = nullptr;
	list_Size = 0;
}

List::~List()
{
	clear();
	
}


int List::push_front(void* elem, size_t elemSize) 
{
	//int n = filling_a_node(wdst_elem, elem, elemSize, this->head);

	void* wdst_elem = _memory.allocMem(elemSize);
	memcpy(wdst_elem, elem, elemSize);			   

	Node* new_Node = new Node(wdst_elem, elemSize);
	if (new_Node != nullptr)                       
	{											   
		new_Node->next_Node = head;				   
		head = new_Node;						   
	}										       
												   
	if (head == nullptr)                           
		return 1;                                  

	mem_Size_List += elemSize;
	list_Size++;								   
	return 0;
}

void List::pop_front() 
{
	if (empty()) return;
	
	Node* point_tmp = head;

	_memory.freeMem(point_tmp->data);

	mem_Size_List -= point_tmp->data_Size;
	head = head->next_Node;
	delete point_tmp;
	list_Size--;

}

//void* List::front(size_t&)
//{
//	return head;
//}

int List::insert(Iterator* iter, void* elem, size_t elemSize) 
{
	try {
		if (iter->prev_elem->next_Node != iter->address) throw List::IterError();
		void* wdst_elem = _memory.allocMem(elemSize);

		memcpy(wdst_elem, elem, elemSize);

		Node* new_Node = new Node(wdst_elem, elemSize);
		if (new_Node != nullptr)
		{
			if (iter->address != head)
			{
				iter->prev_elem->next_Node = new_Node;
				new_Node->next_Node = iter->address;
			}
			else
			{
				new_Node->next_Node = head;
				head = new_Node;
			}
		}

		if (head == nullptr)
			return 1;

		mem_Size_List += elemSize;
		list_Size++;
		return 0;
	}
	catch (List::IterError er)
	{
		throw er;
		return 1;
	}
}

int List::size() 
{
	return list_Size;
}


size_t List::max_bytes()
{
	return  _memory.size();
}

GroupList::Iterator* List::find(void* elem, size_t size)
{
	if (empty())
	{
		List::Iterator* it = (List::Iterator*)List::newIterator();
		if (!it)
			return nullptr;
		while (memcmp(it->getElement(size), elem, size) != 0)
		{
			if (it->hasNext() == 1)
				it->goToNext();
			else
			{
				delete it;
				return nullptr;
			}
		}

		return it;
	}
	else
		return nullptr;
}

GroupList::Iterator* List::newIterator() 
{
	if (empty())
	{
		Iterator* it = new Iterator();
		it->address = head;
		it->headInIter = head;
		return it;
	}
	else
		return nullptr;
}

void List::remove(Container::Iterator* iter)
{
	try {
		if (empty()) throw List::EmptyError();
		Iterator* iterator = dynamic_cast<Iterator*>(iter);
		if (iterator)
		{
			if ( (iterator->prev_elem == nullptr && iterator->address != head) ||
				 iterator->prev_elem->next_Node != iterator->address) throw List::IterError();
			if (iter->hasNext() == 0)
			{
				if (iterator->address == head)
					this->head = nullptr;
				else
					iterator->prev_elem->next_Node = nullptr;
			}
			else
			{
				if (iterator->address == head)
					this->head = iterator->address->next_Node;
				else
					iterator->prev_elem->next_Node = iterator->address->next_Node;
			}
			this->mem_Size_List -= iterator->address->data_Size;
			this->list_Size--;
			iter->goToNext();
			if (list_Size == 0)
				head = nullptr;
			if (iterator->prev_elem != nullptr)
			{
				_memory.freeMem(iterator->prev_elem->data);
				delete(iterator->prev_elem);
			}
			else
			{
				_memory.freeMem(iterator->address->data);
				delete(iterator->address);
			}

		}
		else
			return;
	}
	catch ( List::EmptyError )
	{
		throw;
	}
	catch (List::IterError )
	{
		throw;
	}
}

void List::clear() 
{
	while (!empty()) pop_front();
}






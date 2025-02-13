#include <iostream>
#include "List.h"
#include <chrono>
#include <ctime>

#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, LINE)
#define new DEBUG_NEW

void create(List& lst, int size)
{
	auto begin = std::chrono::steady_clock::now();

	unsigned int start_time = clock();

	for (int i = 0; i < size; i++)
		lst.push_front(&i, sizeof(i));
	
	unsigned int end_time = clock(); 
	unsigned int search_time = end_time - start_time;
	cout << search_time << " Выполнение кода\n";

	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " ms\n\n";
}

void check(List& lst)
{
	auto begin = std::chrono::steady_clock::now();

	unsigned int start_time = clock();

	Container::Iterator* it = lst.newIterator();
	int* tmp = nullptr;
	int value; size_t sizeElem;
	for (int i = lst.size() - 1; i >= 0; i-- )
	{
		tmp = (int*)(it->getElement(sizeElem));
		value = *tmp;
		if (value != i) //проверку на значение
		{
			cout << "Ne to chislo" << endl;
			break;
		}
		it->goToNext();
	}
	delete it;

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << search_time << " Выполнение кода\n";

	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " ms\n\n";
}

void del_nech_index(List& lst)
{
	auto begin = std::chrono::steady_clock::now();

	unsigned int start_time = clock();

	List::Iterator* it = lst.newIterator();
	int i;
	cout << "Amount of elements: " << lst.size() << "\n";
	for (i = lst.size() - 1; i >= 0; i--)
	{
		if (((i % 2))== 1)
			lst.remove(it);
		else
			it->goToNext();
	}
	cout << "Amount of elements: " << lst.size() << "\n";
	delete it;

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << search_time << " Выполнение кода\n";

	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " ms\n\n";
}

void show(List& lst)
{
	auto begin = std::chrono::steady_clock::now();

	unsigned int start_time = clock();

	GroupList::Iterator* it = lst.newIterator();
	int i; int* tmp = nullptr;
	int value; size_t sizeElem;
	for (i = lst.size() - 1; i >= 0; i--)
	{
		tmp = (int*)(it->getElement(sizeElem));
		value = *tmp;
		cout << value << " ";
		it->goToNext();
	}
	delete it;

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "\n";
	cout << search_time << " Выполнение кода\n";

	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " ms\n\n";
}

void check2(List& lst)
{
	auto begin = std::chrono::steady_clock::now();

	unsigned int start_time = clock();

	Container::Iterator* it = lst.newIterator();
	int* tmp = nullptr;
	int value; size_t sizeElem;
	for (int i = lst.size() - 1; i >= 0; i--)
	{
		tmp = (int*)(it->getElement(sizeElem));
		value = *tmp;
		if (value % 2 == 1) //проверку на значение
		{
			cout << "NeChetniye est" << endl;
			break;
		}
		it->goToNext();
	}
	delete it;

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << search_time << " Выполнение кода\n";

	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " ms\n\n";

}

void del_nech_with_find(List& lst)
{
	auto begin = std::chrono::steady_clock::now();

	unsigned int start_time = clock();

	List::Iterator* it = nullptr;
	for (int i = lst.size(); i >= 0; i--)
	{
		if (i % 2 == 1)
		{
			it = lst.find(&i, sizeof(i));
			lst.remove(it);
		}
	}
	delete it;

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << search_time << " Выполнение кода\n";

	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " ms\n\n";
}

void clear(List& lst)
{
	auto begin = std::chrono::steady_clock::now();
	
	unsigned int start_time = clock();

	lst.clear();

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << search_time << " Выполнение кода\n";

	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " ms\n\n";
}

//функцию insert переделать на подобие remove
//

int main()
{
	setlocale(LC_ALL, "rus");

	auto begin = std::chrono::steady_clock::now();
	
		int n = 4;
		int x = 5;

		//оптимизация - подумать, исключения - сделать
		//сделать проверку с помощью find. Ничего личного - просто проверка

		//Проверить работу итератора при удалении всего списка
		//Как себя поведт, при переходе на другой элемент при пустом списке и т.д.

		Mem mem(100000);
		List lst(mem);
		List lst2(mem);

		size_t nn = 4;
		int* tmp = nullptr;
		int value = 0;

		cout << lst.empty() << endl;

		try {
			List::Iterator* it = lst.newIterator();
			lst.remove(it);
		}
		catch (List::EmptyError)
		{
			cout << "Vse po planu\n";
		}

		
			create(lst, 3);
			//create(lst2, 100000);
			//show(lst);
			//del_nech_index(lst);
			//del_nech_with_find(lst2);
			//check2(lst);
			//check2(lst2);
			//show(lst);
			int j = 15;
			List::Iterator* it = lst.newIterator();
			List::Iterator* it2 = lst.newIterator();
		
	try {
			//show(lst);
		it->goToNext(); it2->goToNext(); it2->goToNext();
			lst.remove(it);
			lst.remove(it2);
			//lst.insert(it, &j, sizeof(j));
			//show(lst);
			//lst.remove(it2);
			//show(lst);
		}
		catch (List::IterError)
		{
			cout << "Odin ix iteratorov ne validen\n";
		}
		catch (List::EmptyError)
		{
			cout << "List is empty, but you use remove\n";
		}


		//it->goToNext();
		//lst.insert(it, &j, sizeof(j));
		//show(lst);
		//lst.remove(it);
		//show(lst);
		delete it;
		delete it2;
		clear(lst);
		//clear(lst2);

		lst.pop_front();
		cout << lst.empty() << endl;
		cout << lst2.empty() << endl;
		cout << "End" << endl;

	_CrtDumpMemoryLeaks();
	return 0;
}
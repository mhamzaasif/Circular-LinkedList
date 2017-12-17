#pragma once
template <class T>
class Circular_Que {
private:	
	struct node {
		T data;
		node *ptr;
	};
	node *head;
	node *tail;
	int count;

public:
	Circular_Que() {
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	void enque(T element) {
		node *obj = new node();
		obj->data = element;
		obj->ptr = nullptr;
		if (head == nullptr)
		{
			head = obj;
			head->ptr = head;
			tail = head;
		}
		else
		{
			tail->ptr = obj;
			tail = tail->ptr;
		}
	}
	void deque() {
		if (!is_empty())
		{
			if (head == tail)
			{
				delete head;
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				node *temp = head;
				head = head->ptr;
				delete temp;
			}

		}
	}
	T top() {
		if (!is_empty())
			return head->data;
	}

	bool is_empty()
	{
		if (head == nullptr)
			return true;
		return false;
	}
};
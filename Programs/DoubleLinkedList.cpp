#include<iostream>
using namespace std;

class Double
{
private:
	struct node
	{
		int data;
		node* next;
		node* previous;

	};

	node* head;
	node* tail;

public:

	Double()
	{
		head = NULL;
		tail = NULL;

	}

	void AddAtHead(int val)
	{
		node* newptr=new node ;
		newptr->data = val;

		if (head == NULL)
		{
			tail = newptr;
			head = newptr;
			tail->next = NULL;

			return;
		}

		newptr->previous = NULL;
		newptr->next = head;
		head->previous = newptr;
		head = newptr;
		return;


	}

	void AddAtTail(int value)
	{
		node* newptr = new node;
		newptr->data = value;

		if (head == NULL)
		{
			tail = newptr;
			head = newptr;
			cout << "if condition was called.." << endl << endl;
			return;

		}
		
		tail->next = newptr;
		newptr->previous = tail;
		tail = newptr;
		tail->next = NULL;
		
		return;

	}

	void AddNodeSpecific()
	{
		int index;
		node * newptr = new node ,* Tptr = head;
		
		cout << "Enter index = ";
		cin >> index;

		if (index == 0 && head ==NULL ) {
			cout << "Enter value: ";
			int value;
			cin >> value;

			AddAtHead(value);

			return;
		}

		if (head == NULL)
		{
			cout << "Head cant be null , list is empty.." << endl;
			return;

		}

		for (int i = 0; i < index-1; i++)
		{
			Tptr = Tptr -> next;
			cout << "mk" << endl;
		}

		if (Tptr->next == NULL)
		{
			cout << "Enter value: ";
			int value;
			cin >> value;

			AddAtTail(value);
			return;
		}

		cout << "Enter value: ";
		int value;
		cin >> value;
		newptr->data = value;

		newptr->previous = Tptr;
		newptr->next = Tptr->next;
		newptr->next->previous = newptr;
		Tptr->next = newptr;
		//return;

		//tptr.next=tptr.next.next;
		//tptr.next.prev=tptr;

		cout << "added" << endl;
		return;
	}

	void DeleteSpecific()
	{
		int index;
		node* newptr = new node, * Tptr = head;

		cout << "Enter index = ";
		cin >> index;

		if (head == NULL)
		{
			cout << "list is empty.." << endl;
			return;

		}

		for (int i = 0; i < index -1; i++)
		{
			Tptr = Tptr->next;
			cout << endl;
		}

	
		Tptr->next=Tptr->next->next;
		Tptr->next->previous =Tptr;
		return;

		cout << "Deleted" << endl;
		return;
	}


	void display()
	{
		node* ptr = head;

		while (ptr != NULL)
		{
			cout << ptr->data << ",";
			ptr = ptr->next;

		}
		
		cout << endl << endl;
		return;
	}

};

int main()
{
	Double obj;
	obj.AddAtTail(1);
	obj.AddAtTail(2);
	obj.AddAtTail(3);
	obj.AddAtTail(4);
	obj.display();

	obj.AddNodeSpecific();
	obj.display();

	obj.DeleteSpecific();
	obj.display();

	return 0;
}

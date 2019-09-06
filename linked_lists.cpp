#include<iostream>
#include<vector>

using namespace std;

class node {                         //nodes of the linked list
public:
	int data;
	node *next;
};

class LinkedList {
public: 
	void create(node **head, int val);                //for creating a new linked list
	void print(node *head);                           //for printing the linked list into the intefce
	void common(vector<int> list1,vector<int> list2);             //finding the comon elemnets in linked lists
	int duplicate(vector<int> list);                      //finding the duplicate valued in a linked list
};

void LinkedList::create(node **head, int val) {
	node *new_node = new node();
	
	node *ptr = *head;
	new_node->data = val;
	new_node->next = NULL;

	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new_node;
}

void LinkedList::print(node *head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

void LinkedList::common(vector<int> list1, vector<int> list2) {
	for (unsigned int i = 0; i < list1.size(); i++) {
		for (unsigned int j = 0; j < list2.size(); j++) {
			if (list1[i] == list2[j]) {
				cout << list1[i] << " ";
			}
		}
	}
}

int LinkedList::duplicate(vector<int> list)
{
	for (unsigned int i = 0; i < list.size(); i++) {
		for (unsigned int j = 0; j < list.size(); j++) {
			if(i!=j){
				if (list[i] == list[j]) {
					return 0;
				}
				else
				{
					return 1;
				}
			}
			
		}
	}
}


int  main()
{
	node *head =new node();
	node *head_ref = new node();


	LinkedList obj1,obj2,obj3;
	vector<int> list1;
	vector<int> list2;
	
	int num,num2;
	int elements,elements2;

	cout << "Enter the elements of the Linked List: ";
	cin >> num;

	for (int i = 1; i <= num; i++) {
		cout << "Enter the element "<<i<<" : ";
		cin >> elements;
		list1.push_back(elements);
		obj1.create(&head, elements);
		
	}

	cout << "Enter amount of elements in the 2nd list : ";
	cin >> num2;

	for (int i = 1; i <= num2; i++) {
		cout << "Enter the element " << i << " : ";
		cin >> elements2;
		list2.push_back(elements2);
		obj2.create(&head_ref, elements2);
		
	}
	cout << "\n" << endl;
	
	if (obj3.duplicate(list1) == 0 || obj3.duplicate(list2)==0) {
		cout << "errror! duplicate values are here!" << endl;
	}
	else if(obj3.duplicate(list1)==1 || obj3.duplicate(list2)==1)
	{
		obj3.common(list1, list2);
		
	}


	system("pause");
	return 0;
}
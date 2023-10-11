#include <iostream>
using namespace std;
// class of node which contains the data and the address of next node in it
class Node
{
public:
    int data;
    Node *next;
    // Parameterized Constructor
    Node(int data) : data(data), next(nullptr) {}
};
// class of linkedlist which links the nodes and perform the different functions on the linked list
class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }
    // insert the node at the start of the list
    void InsertAtStart(int data)
    {
        if (head == NULL)
        {
            head = new Node(data);
        }
        else
        {
            Node *NewNod = new Node(data);
            NewNod->next = head;
            head = NewNod;
        }
        cout << "Node with data " << data << " is added at the start of the linked list" << endl;
    }
    // insert the at the end of the  list
    void InsertAtEnd(int data)
    {
        if (head == NULL)
        {
            cout << "LIST IS EMPTY" << endl;
            head = new Node(data);
        }
        else
        {
            Node *NewNode = new Node(data);
            Node *temp;
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NewNode;
        }
        cout << "Node with data " << data << " is added at the end of the linked list" << endl;
    }
    // insert the node at the middle or at the entered index
    void InsertAtMiddle(int index, int data)
    {
        Node *NewNode = new Node(data);
        if (head == NULL)
        {
            if (index == 1)
                head = NewNode;
        }
        else if (head != NULL && index == 1)
        {
            NewNode->next = head;
            head = NewNode;
        }
        else
        {
            int i = 1;
            Node *temp = head;
            while (i < index - 1 && temp != NULL)
            {
                temp = temp->next;
                i++;
            }
            if (temp != NULL)
            {
                NewNode->next = temp->next;
                temp->next = NewNode;
            }
        }
        cout << "Node with data " << data << " is added at the index " << index << " of the linked list" << endl;
    }
    // insert the node after the entered dat
    void InsertAfter(int before_data, int after_data)
    {
        Node *NewNode = new Node(after_data);
        Node *temp = head;
        while (temp != NULL && temp->data != before_data)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            NewNode->next = temp->next;
            temp->next = NewNode;
        }
        cout << "New node with new data " << after_data << " is added after the old node " << before_data << endl;
    }
    // sorting functions to sort the linked list in ascending and also in descending order
    void SortAscend()
    {
        Node *temp, *temp2;
        int temp1;
        temp = head;
        while (temp->next != NULL)
        {
            temp2 = temp->next;
            while (temp2 != NULL)
            {
                if (temp->data > temp2->data)
                {
                    temp1 = temp->data;
                    temp->data = temp2->data;
                    temp2->data = temp1;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }
    void SortDescend()
    {
        Node *temp, *temp2;
        int temp1;
        temp = head;
        while (temp->next != NULL)
        {
            temp2 = temp->next;
            while (temp2 != NULL)
            {
                if (temp->data < temp2->data)
                {
                    temp1 = temp->data;
                    temp->data = temp2->data;
                    temp2->data = temp1;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }
    // function to find the index of the required data
    void Find(int data)
    {
        Node *temp;
        temp = head;
        int i = 1;
        // checking if there is any other same data in list
        while (temp != NULL)
        {
            if (temp->data == data)
                cout << "Your required data " << data << " is at index " << i << endl;
            temp = temp->next;
            i++;
        }
    }
    // function to modify the data of the already present node
    void Modify(int previous_data, int new_data)
    {
        Node *temp;
        temp = head;
        int i = 1;
        while (temp != NULL && temp->data != previous_data)
        {
            temp = temp->next;
            i++;
        }
        if (temp->data == previous_data)
            temp->data = new_data;
        cout << "Your previous data " << previous_data << " is modified with new data " << new_data << endl;
    }
    void DeleteAtStart()
    {
        if (head == NULL)
            cout << "List is Empty" << endl;
        else
        {
            Node *del;
            del = head;
            head = head->next;
            delete del;
        }
    }
    void DeleteAtEnd()
    {
        if (head == NULL)
            cout << "List is empty" << endl;
        else if (head->next == NULL)
            delete head;
        else
        {
            Node *del;
            del = head;
            while (del->next->next != NULL)
            {
                del = del->next;
            }
            delete del->next;
            del->next = NULL;
        }
    }
    void DeleteAtIndex(int index)
    {
        if (head == NULL)
            cout << "List is empty" << endl;
        else if (index == 1)
        {
            Node *del;
            del = head;
            head = head->next;
            delete del;
        }
        else
        {
            Node *previous;
            Node *current;
            previous = head;
            current = head;
            int i = 1;
            while (i < index)
            {
                previous = current;
                current = current->next;
                i++;
            }
            previous->next = current->next;
            delete current;
        }
        cout << "Your node at index " << index << " is deleted " << endl;
    }
    void DeleteByValue(int data)
    {
        if (head == NULL)
            cout << "List is empty" << endl;
        else
        {
            Node *previous;
            Node *current;
            previous = head;
            current = head;
            while (current->data != data)
            {
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
            delete current;
        }
        cout << "Your node with value(data) " << data << " is deleted " << endl;
    }
    // display function to show the linked list
    void Display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            Node *dis;
            dis = head;
            cout << "\t\t\t";
            while (dis != NULL)
            {
                cout << dis->data << " ";
                dis = dis->next;
            }
            cout << endl;
        }
    }
    void reverseDisplay()
    {
        cout << "Linked list in reverse order: ";
        reverseDisplayRecursive(head);
        cout << endl;
    }
    // reverse the singly linked list
    void reverseDisplayRecursive(Node *current)
    {
        if (current == nullptr)
        {
            return;
        }
        reverseDisplayRecursive(current->next);
        cout << current->data << " ";
    }
    bool TwoSum()
    {
        int t, i = 0, j = 1;
        cout << "Enter the target: ";
        cin >> t;
        Node *temp = head, *temp2 = temp->next;
        while ((temp) && (temp2) != NULL)
        {
            if ((temp->data) + (temp2->data) == t)
            {
                cout << "[" << i << "," << j << "]";
                return true;
            }
            else if ((temp->data) + (temp2->data) != t)
            {
                cout << "Error";
                return false;
            }
            else
            {
                i = i + 2;
                j = j + 2;
            }
            temp = temp->next->next;
            temp2 = temp2->next->next;
        }
    }
};
// driver of the program
int main()
{
    LinkedList list;
    list.InsertAtStart(2);
    list.InsertAtStart(7);
    list.InsertAtStart(11);
    list.InsertAtStart(10);
    list.Display();
    list.TwoSum();
}
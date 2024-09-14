/******************************************************************************
Date: June 16, 2023
Course: SYDE 223
Assignment #1
Program Description: This is a program that implements a circular linked list 
to store and manipulate a collection of integers. It includes features such as
insertion, deletion, display, and searching.
*******************************************************************************/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

typedef Node *NodePtr;
class CircularLinked
{
public:
    NodePtr head;
    CircularLinked() : head(nullptr){};
    void insert(int insertData);
    void deleteNode(int deleteData);
    void display();
    int search(int target);
};

int main()
{
    CircularLinked linklist;
    int searchValue;

    linklist.insert(4);
    linklist.insert(5);
    linklist.insert(6);

    linklist.display();

    // search value 
    cout << "What value would you like to search for?" << endl;
    cin >> searchValue;
    int a = linklist.search(searchValue);
    cout << "The value you would like to search for is at index " << a << " of the linked list" << endl;

    linklist.deleteNode(5);
    linklist.display();
}

void CircularLinked::insert(int insertData)
{
    NodePtr newNode = new Node;
    newNode->data = insertData;

    // if the list is empty (there is no node in the linked list)
    if (head == NULL)
    {
        newNode->next = newNode; // Make the new node point to itself
        head = newNode;          // Make the head point to the new node
    }

    else
    { // if the list is not empty, we start adding
        NodePtr temp = head;

        while (temp->next != head)
        { // while the pointer is not pointing to the last node
            temp = temp->next;
        }

        // once you are at the end of the list:
        temp->next = newNode;
        newNode->next = head;
    }
};

void CircularLinked::deleteNode(int deleteData)
{
    // if list is empty, immediately return
    if (!head)
    {
        cout << "Circular linked list is empty. Deletion failed." << endl;
        return;
    }

    // pointers to find the last occurrence of given integer value
    NodePtr current = head;
    NodePtr prev = nullptr;
    NodePtr lastOccurrence = nullptr;
    NodePtr lastOccurrencePrev = nullptr;

    // traverse through entire list
    do
    {
        // keep track of the last occurrence of node to delete and its previous node
        if (current->data == deleteData)
        {
            lastOccurrence = current;
            lastOccurrencePrev = prev;
        }

        // update pointers
        prev = current;
        current = current->next;
    } while (current != head);

    // if given integer does not exist in list
    if (!lastOccurrence)
    {
        cout << deleteData << " does not exist in the circular linked list. Deletion failed." << endl;
        return;
    }

    // if node to be deleted is head
    if (lastOccurrence == head)
    {
        // traverse to actual last node
        while (current->next != head)
        {
            current = current->next;
        }
        // update pointers
        current->next = head->next;
        head = head->next;
    }
    else
    {
        lastOccurrencePrev->next = lastOccurrence->next;
    }
    delete lastOccurrence;
    cout << "Last occurrence of " << deleteData << " deleted successfully." << endl;
}

void CircularLinked::display()
{
    // Implement a function to display the contents of the circular linked list in a clockwise direction.
    NodePtr temp = head;

    if (temp == nullptr)
    {
        cout << "Circular linked list is empty." << endl;
        return;
    }

    while (true)
    {
        cout << temp->data << " ";
        temp = temp->next;

        if (temp == head)
            break;
    }
};

int CircularLinked::search(int target) // search function
{
    NodePtr temp = head;    // creating a temp pointer that points to head - this pointer will be iterating through the linked-list
    int counter = 0; // initialize the index for each node

    if (temp == NULL) // if the head is pointing to nothing, return 0
    {
        cout << "Circular linked list is empty. Search failed." << endl;
        return -1;
    }
    else
    {
        while (temp->data != target) // if the data that is stored does not equal the target value, the loop continues
        {
            temp = temp->next; // temporary pointer move to next node
            counter++;         // counter increase index as pointer moves to the next node
            if (temp == head)  // if the temporary pointer returns to the head pointer due to circular linked-list, break the loop
            {
                break;
            }
        };

        if (temp->data == target) // if the temporary pointer found the target value, return the current position (index value)
        {
            return counter;
        }

        else // if the value does not exist, return 0
        {
            return 0;
        }
    }
}
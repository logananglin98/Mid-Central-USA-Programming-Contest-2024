#include <iostream>
using namespace std;

class Node {
    private:
        int data; //data in the beginning node
        Node *next; //pointer to the next node

    public:
        Node(int initdata) {
            data = initdata; //the initialized data is set as the head
            next = NULL; //the next node is set as NULL, as there is no next node yet.
        }

        int getData() { //function that return data of a given node.
            return data;
        }

        Node *getNext() {
            return next;
        }

        void setData(int newData) {
            data = newData;
        }

        void setNext(Node *newnext) {
            next = newnext;
        }
};   
    
class UnorderedList {
    public:
        Node *head;

        UnorderedList() {
               head = NULL;
        }

        void add(int new_data) {
            if (head != NULL) {
                Node *curr = head;
                while (curr->getNext() != NULL) {
                    curr = curr->getNext();
                } 
                curr->setNext(new Node(new_data));
            } else {
                head = new Node(new_data);
            }
        }

        void printList() {
            Node *curr = head;
            if (curr == NULL) {
                cout << "No nodes in list\n";
            } else {
                cout << "Data in each node: ";
                int count = 0;
                while (curr != NULL) {
                    cout << curr->getData() << " ";
                    curr = curr->getNext();
                    count++;
                }
                cout << "\nNumber of nodes: " << count << "\n";
            }
        }

        int size() const {
            int count = 0;
            Node *curr = head;
            while (curr != NULL) {
                count++;
                curr = curr->getNext();
            }
            return count;
        }


        bool search(int data) {
            Node *curr = head;
            while (curr != NULL) {
                if (curr->getData() == data) {
                    return true;
                }
                curr = curr->getNext();
            }
            return false;
        }


        void remove(int data){
            if (head != NULL) {
                Node *last = NULL;
                Node *curr = head;
                while (curr->getNext() != NULL && curr->getData() != data) {
                    last = curr;
                    curr = curr->getNext();
                }
                if (curr->getData() == data) {
                    if (last != NULL && curr->getNext() != NULL) {
                        last->setNext(curr->getNext());
                        delete curr;
                    } else if (last != NULL) {
                        last->setNext(NULL);
                        delete curr;
                    } else if (head->getNext() != NULL) {
                        head = head->getNext();
                        delete curr;
                    } else {
                        head = NULL;
                        delete curr;
                    }
                }
            }
        }

        ~UnorderedList() {
            Node* curr = head;
            while (curr != NULL) {
                Node* nextNode = curr->getNext();
                delete curr;
                curr = nextNode;
            }
        }
        
};

int main() {
    
    UnorderedList myList;

    myList.add(12);

    myList.printList();

    myList.remove(12);

    myList.printList();

    myList.add(23);

    myList.printList();

    myList.add(5);

    myList.printList();

    cout << "Is 5 in the list: " << myList.search(5) << "\n";

    cout << "Is 42 in the list: " <<myList.search(42) << "\n";

    myList.add(60);

    myList.add(69);

    myList.printList();
    
    myList.remove(23);

    myList.printList();

    return 0;
}
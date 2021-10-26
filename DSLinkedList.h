//
// Created by dalla on 10/20/2021.
//

#ifndef INC_21F_FLIGHT_PLANNER_DSLINKEDLIST_H
#define INC_21F_FLIGHT_PLANNER_DSLINKEDLIST_H
#include <iostream>
#include <algorithm>
using namespace std;

template <typename DT> class Node {

private:
    DT data;
    Node<DT> *prev; //pointer to previous node
    Node<DT> *next; //pointer to next node
    template<typename D2> friend
    class DSLinkedList; //friend class of DSLinkedList now
public:
    Node() {
        prev = nullptr;
        next = nullptr;
    }
};

template<typename DT>class DSLinkedList{
private:
    Node<DT>* head;
public:
    DSLinkedList() {
        head = nullptr;
    }
    DSLinkedList(const DSLinkedList<DT>& copylist) {
        const Node<DT> *cpCurrent = copylist.head;
        Node<DT>* lscurrent = nullptr;
        if (cpCurrent != nullptr) {
            head = new Node<DT>;
            head->data = cpCurrent->data;
            cpCurrent = cpCurrent->next;
        }
        while (cpCurrent != nullptr) {
            Node<DT>* newNode = new Node<DT>;
            newNode->data = cpCurrent ->data;
            lscurrent->next = newNode;
            lscurrent = lscurrent->next;
            cpCurrent = cpCurrent->next;
        }
    }
    DSLinkedList<DT>& operator =(const DSLinkedList<DT>& rhs) {
        DSLinkedList<DT> temp(rhs);
        swap(temp.head, head);
        return *this;
    }
    ~DSLinkedList() {
        Node<DT>* curr = head;
        while (head != nullptr) {
            head = head->next;
            delete[] curr;
            curr = head;
        }
    }
    void append(DT data) {
        Node<DT>* node = new Node<DT>[1];
        node->data = data;
        if(head == nullptr){ //check if list empty
            head = node;
            cout<<"new node added(firstnode) !"<<endl;
            return;
        }//if not empty, new node added to end
        Node<DT>* temp = head;
        Node<DT>* prev;
        while(temp->next != nullptr){
            prev = temp;
            temp = temp->next; //list traversed to the end
        }
        temp->next = node;
        temp->prev = prev; //once at end, final data value is linked
        cout<<"new node added at back!"<<endl;
    }
    void prepend(DT item){
        Node<DT>* node = new Node<DT>[1];
        node->data = item;
        if(head == nullptr){ //list checked if empty
            head = node;
            cout<<"new node added(firstnode) !"<<endl;
            return;
        } //if list not empty, list traversed
        head->prev = node;
        node->next = head;
        head = node;
        cout<<"new node added at front !"<<endl;
    }
    int length(){
        int len = 0;
        Node<DT>* temp = head;
        while(temp != nullptr){ //iterates to end and increments length for length
            len++;
            temp = temp->next;
        }
        return len;
    }

    void insert(int index, DT item){
        if(index > length() || index < 0){ //checks if index out of bounds
            cout<<"index out of bound !"<<endl;
            return;
        }
        Node<DT>* node = new Node<DT>[1]; //temporary iterator created
        node->data = item;
        int count = 0;
        Node<DT>* temp = head;
        while(temp != nullptr && count < index){
            if(count == index-1){
                if(temp->next != nullptr){
                    node->next = temp->next;
                }
                temp->next = node;
                node->prev = temp;
                cout<<"new node added at index "<<index<<" !"<<endl;
                break;
            }
            count++;
            temp = temp->next;
        }

    }
    void displayAll(){
        if(head == nullptr){
            cout<<"linked list is empty"<<endl;
            return;
        }
        cout<<endl<<"---DSlink list items-----"<<endl;
        Node<DT>* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" | ";
            temp = temp->next;
        }
        cout<<endl<<"--------------------------"<<endl;
    }
    void pop(){
        if(head == nullptr){ //checks if list already empty
            cout<<"linked list is empty !"<<endl;
            return;
        }
        if(head->next == nullptr){ //checks if list has one item
            head = nullptr;
            cout<<"last item removed"<<endl;
            return;
        }
        Node<DT>* temp = head;
        while(temp != nullptr){ //iterates to end and deletes last node of list
            if(temp->next->next == nullptr){
                temp->next = nullptr;
                cout<<"end item removed"<<endl;
                break;
            }
            temp = temp->next;
        }
    }
    void removeFront(){
        if(head == nullptr){ //checks if list empty
            cout<<"linked list is empty !"<<endl;
            return;
        }
        head = head->next;
        head->next->prev = head;
        cout<<"front item removed"<<endl; //iterates to front, removes front node
    }

    DT get(int index){
        if(head == nullptr){ //checks if linkedlist empty
            cout<<"linked list is empty !"<<endl;
            DT useless;
            return useless;
        }
        if(index >= length() || index < 0){ //checks if invalid index,
            cout<<"index out of bound !"<<endl;
            DT useless;
            return useless;
        }
        if(index == 0){
            return head->data;
        }
        int count = 0;
        DT res;
        Node<DT>* temp = head;
        while(temp != nullptr){
            if(count++ == index){
                res = temp->data;
                break;
            }
            temp = temp->next;
        }
        return res;
    }
    void removeat(int index){
        if(head == nullptr){
            cout<<"linked list is empty !"<<endl;
            return;
        }
        if(index >= length() || index < 0){
            cout<<"index out of bound !"<<endl;
            return;
        }
        if(index == 0){
            removeFront();
            cout<<"item removed at index "<<index<<endl;
            return;
        }
        int count = 0;
        Node<DT>* temp = head;
        while(temp != nullptr){
            if(count == index - 1){
                temp->next = temp->next->next;
                cout<<"item removed at index "<<index<<endl;
                break;
            }
            count++;
            temp = temp->next;
        }
    }


};

#endif //INC_21F_FLIGHT_PLANNER_DSLINKEDLIST_H

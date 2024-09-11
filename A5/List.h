#ifndef LIST_H
#define LIST_H

class Participant;

template <class T>
class List
{
  class Node
  {
    public:
       T data;
      Node*    next;
      
  };

  public:
    List();
    ~List();
    bool operator+=(T);
    void convertToArray(T* arr, int& size);
   

  private:
    Node* head;
};

#endif


template <class T>
List<T>::List() : head(nullptr) { }


template <class T>
List<T>::~List()
{
  Node* currNode = head;
  Node* nextNode;

  while (currNode != nullptr) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

template <class T>
bool List<T>::operator+=(T t){

    
  Node* newNode;
  Node* currNode;
  Node* prevNode;

  newNode = new Node;

  newNode->data = t;
  newNode->next = nullptr;

  currNode = head;
  prevNode = nullptr;

  while (currNode != nullptr) {
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == nullptr) {
    head = newNode;
  }
  else {
    prevNode->next = newNode;
  }

  newNode->next  = currNode;

  currNode = head;
  prevNode = nullptr;

  while (currNode != nullptr) {
    prevNode = currNode;
   
    currNode = currNode->next;
  }

  return true;
}


template <class T>
void List<T>::convertToArray(T* arr, int& size){

  int count =0;

  Node* currNode;
  Node* prevNode;

  currNode = head;
  prevNode = nullptr;

  while (currNode != nullptr) {

    arr[count] = currNode->data;
    count ++;
    prevNode = currNode;
    currNode = currNode->next;
    }


    size = count;

}


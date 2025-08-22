#include <iostream>
using namespace std;

class node{

  public:
    node(int value){
      val = value;
    }
    int val = 0;
    node* next;

};

class List{

    public:

      node* firstNode, *lastNode;
      List() : firstNode(0), lastNode(0){}
      
      ~List(){

        if(isEmpty()){
       
          cout << "List is already empty.\n";
        
        }else{

          node* currentNode = firstNode;
          node* tempNode;

          do{

            tempNode = currentNode;

            cout << "Deleting " << tempNode->val << endl;

            currentNode = currentNode->next;

            delete tempNode;

          }while(currentNode != 0);//do while

          cout << "List cleaned.\n";
        }//else 


      }//destructor

      bool isEmpty(){return firstNode ==0;}

      node* getNewNode(int val){return new node(val);}

      void addToHead(int val){

        node* newNode = getNewNode(val);

        if(isEmpty()){
          firstNode = lastNode = newNode;
        }else{

          newNode->next = firstNode;
          firstNode = newNode;

        }

      }//addToHead
   
    void addToTail(int val){

      node* newNode = getNewNode(val);

      if(isEmpty()){
      
         firstNode = lastNode = newNode;  

      }else{

        lastNode->next = newNode;
        lastNode = newNode;

      }

    
    }//addToTail

    void print(){
      if(isEmpty()){
        cout << "No nodes in the list.\n";
      }else{
        node* currentNode = firstNode;

        while(currentNode != 0){
  
          cout << currentNode->val << endl;
          currentNode = currentNode->next;

        }//while 

      }//else
    
    }//print()


}; //class

int pop(List* list){

      if (list->isEmpty()){
       
        cout << "list is empty.\n";

      }else{

        node* currentNode = list->firstNode;
        int val = currentNode->val;
        list->firstNode = list->firstNode->next;
        
        delete currentNode;
        return val;
      }

      return -1;

    }


int main (int argc, char *argv[]) {
 
  List myList;

  myList.addToTail(3);
  myList.addToHead(5);

  myList.print();

  int a = pop(&myList);

  cout << a <<" deleted\n";

  myList.print();

  return 0;
}

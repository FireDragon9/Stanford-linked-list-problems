#include <iostream>
using namespace std;
/*
 *
 *  STANFORD LINKED LIST PROBLEM: 
 *  1 - GetNTH
 *
 * */

class node{

  private:
    node(int value){
      val = value;
    }
    friend class List;
    int val = 0;
    node* next;

};

class List{

    private:
      node* firstNode, *lastNode;

      bool isEmpty(){return firstNode ==0;}

      node* getNewNode(int val){return new node(val);}

    public:
      List() : firstNode(0), lastNode(0){}

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

   void getNth(int val){

      node* currentNode = firstNode;
      int pos = 0;

      while(currentNode != 0){

        if(currentNode->val == val){
          cout << "Found! There's a " << val << "in pos: " << pos << endl;
        }

        pos++;

        currentNode = currentNode->next;

      }//while

   }//getNth 

}; //class



int main (int argc, char *argv[]) {
  
  List myList;

  myList.addToHead(8);
  myList.addToHead(3);
  myList.addToHead(3);
 
  myList.print();

  myList.getNth(5);

  return 0;
}

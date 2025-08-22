#include <iostream>
using namespace std;

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


int main (int argc, char *argv[]) {
 
  List list;
  list.addToHead(3);
  list.addToTail(5);

  list.print();


  return 0;
}

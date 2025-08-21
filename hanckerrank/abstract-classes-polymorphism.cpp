#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache: public Cache{
private:
    int size; // current size of the cache
public:
    LRUCache(int capacity)
    {   
        cp = capacity;
        size = 0;
        tail = nullptr;
        head = nullptr;
    }
    
    void set(int key, int value){
        if (mp.count(key) == 0){// key not found
            if (size == cp){ // cache is full
                Node* tail_prev = tail->prev; // get the previous node of tail
                tail_prev->next = nullptr; // remove the tail from the list
                mp.erase(tail->key); // remove from map
                delete tail;
                tail = tail_prev; // update tail
                size--;
            }
            if (tail == nullptr && head == nullptr){ // empty cache
                head = new Node(key, value);
                tail = head;
            }else{ // cache is not empty
                Node* tmp = new Node(nullptr, head, key, value);
                head->prev = tmp;
                head = tmp;
            }
            mp[key] = head; // add to map
            size++;
        }else{ // key found
            mp[key]->value = value;
        }
        
    }
    
    int get(int key){
        if (mp.count(key) == 0){
            return -1;
        }
        else{
            return mp[key]->value;
        }
    }
    
};


int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

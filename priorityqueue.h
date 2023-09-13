// priorityqueue.h
//
// priortiyqueue is based priorities that are inserted from enqueue
// this program takes values and priorities that are associated with the values 
// and does whatever operations we are to fill out, such as insert/remove and seeing if other pq's are equal to each other, etc..........

#pragma once

#include <iostream>
#include <sstream>
#include <set>

using namespace std;

template<typename T>
class priorityqueue {
private:
    struct NODE {
        int priority;  // used to build BST
        T value;  // stored data for the p-queue
        bool dup;  // marked true when there are duplicate priorities
        NODE* parent;  // links back to parent
        NODE* link;  // links to linked list of NODES with duplicate priorities
        NODE* left;  // links to left child
        NODE* right;  // links to right child
    };
    NODE* root;  // pointer to root node of the BST
    int size;  // # of elements in the pqueue
    NODE* curr;  // pointer to next item in pqueue (see begin and next)

    void toStringHelper(NODE *node, ostream &output){ // helper function for tostring
        if(node == nullptr){
            return; // base case
        }
        else{
            toStringHelper(node->left, output); // traverse thru left
            output << node->priority << " value: " << node->value << endl; // output
            if(node->dup == true){ // if theres a dup
                NODE *temp = node;
                while(node->link != nullptr){ // link thru dup
                    NODE *temp2 = node->link;
                    output << temp2->priority << " value: " << temp2->value << endl; // output dups
                    node = temp2;
                }
                node = temp;
            }
            toStringHelper(node->right, output); // traverse thru right
        }
    }
    
    void clearHelper(NODE *node){ // clear helper function
        if(node == nullptr){
            return; // base case
        }
        else{ // post order traversal
            clearHelper(node->left); // traverse left
            clearHelper(node->right); // traverse right
            if(node->dup == true){ // if theres dups
                while(node->link != nullptr){ // if theres dups go thru linked list
                    NODE *temp = node->link;
                    delete node; // delete the dups
                    node = temp;
                }
            }
        }
        delete node;
    }

    void operatorEqualsHelper(NODE *node){ // operator equal= helper 
        if(node == nullptr){
            return; // base case
        }
        else{ // pre order traversal
            this->enqueue(node->value, node->priority); // enqueue nodes
            operatorEqualsHelper(node->left); // recurse thru left
            operatorEqualsHelper(node->right); // recurse thru right
            operatorEqualsHelper(node->link); // recurse thru linked list of dups
        }
    }

    void NextHelper(NODE *node, T& value, int &priority){
        if(node == nullptr){ 
            return; // base case
        }
        else{ // in order traversal
            NextHelper(node->left, value, priority); // traverse left
            while(node != nullptr){
                if(node->dup == true){
                    while(node->link != nullptr){

                    }
                }
            }
            NextHelper(node->right, value, priority); // traverse right
        }
    }

    bool doubleEqualsHelper(NODE *temp, NODE *other) const { // double =='s helper
        if(temp == nullptr && other == nullptr){
            return true; // an empty bst is a valid one
        }
        else if ((temp == nullptr) && (other != nullptr)){
            return false; // one cant be null while the other isnt
        }
        else if((other == nullptr) && (temp != nullptr)){
            return false; // one cant be null while the other isnt
        }
        else{
            if(doubleEqualsHelper(temp->link, other->link) && doubleEqualsHelper(temp->left, other->left) && temp->value == other->value && temp->priority == other->priority 
            && doubleEqualsHelper(temp->right, other->right)){
                return true; // if everything is equal
            }
            else{
                return false; // if everything isnt equal
            }
        }
    }
    
public:
    //
    // default constructor:
    //
    // Creates an empty priority queue.
    // O(1)
    //
    priorityqueue() {
        root = nullptr;
        curr = nullptr;
        size = 0;
    }
    //
    // operator=
    //
    // Clears "this" tree and then makes a copy of the "other" tree.
    // Sets all member variables appropriately.
    // O(n), where n is total number of nodes in custom BST
    //
    priorityqueue& operator=(const priorityqueue& other){
        this->clear(); // clear the tree
        operatorEqualsHelper(other.root); // call helper function
        return *this;
    }
    
    //
    // clear:
    //
    // Frees the memory associated with the priority queue but is public.
    // O(n), where n is total number of nodes in custom BST
    //
    void clear() { 
        clearHelper(root); // call helper function
        curr = nullptr; // default value
        root = nullptr; // default value
        size = 0; // default value
    } 
    
    //
    // destructor:
    //
    // Frees the memory associated with the priority queue.
    // O(n), where n is total number of nodes in custom BST
    //
    ~priorityqueue() {    
        this->clear();    
    }
    
    //
    // enqueue:
    //
    // Inserts the value into the custom BST in the correct location based on
    // priority.
    // O(logn + m), where n is number of unique nodes in tree and m is number of
    // duplicate priorities
    //
    // value = key
    
    void enqueue(T value, int priority) { // insert function

        NODE *current = root; // create new node that is the root

        NODE *temp = new NODE; // create new node and set default values
        temp->left = nullptr;
        temp->right = nullptr;
        temp->parent = nullptr;
        temp->link = nullptr;
        temp->value = value;
        temp->priority = priority;

        if(current == nullptr){ // base case
           root = temp;
        }
        else{ // if currenet isnt nullprt
            NODE *prev = new NODE; 
            while(current != nullptr){
                prev = current; // keep track of a prev
                if(priority == current->priority){ // if theres a duplicate
                    temp->dup = true; // theres a dup node
                    prev = current; // keep track of prev
                    break;
                }
                if(priority < current->priority){ // if inserted node is less than curr node
                    current->parent = prev; 
                    current = current->left; // go left
                }
                else if(priority > current->priority) { // if inserted node is bigger than curr node
                    current->parent = prev;
                    current = current->right; // go right
                }
            }
            if(temp->dup == true){ // if theres a dup
                prev->dup = true; // keep track of prev dub
                if(prev->link == nullptr){ 
                    prev->link = temp; 
                }
                else{
                    while(prev->link != nullptr){
                        prev = prev->link; // traverse through linked list of dups
                    } 
                    prev->link = temp; 
                    temp->link = nullptr;
                    temp->parent = prev;
                }
            }
            else if(priority < prev->priority){ 
                prev->left = temp;
                temp->parent = prev;
            }
            else if(priority > prev->priority){
                prev->right = temp;
                temp->parent = prev;
            }
        }
        curr = root;
        size++; // increment size when inserting
    }
    //
    // dequeue:
    //
    // returns the value of the next element in the priority queue and removes
    // the element from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number of
    // duplicate priorities
    //
    T dequeue() {
        T valueOut;
        NODE *temp = root;
        NODE *prev = nullptr;
        if(temp == nullptr || size == 0){
            return valueOut;
        }
        while(temp->left != nullptr){ // traverse
            prev = temp; // keep track of a prev
            temp = temp->left; // go all the way left
        }
        if(temp->right){ 
            valueOut = temp->value; // set value to curr value
            prev->left = temp->right; // if theres a right sub tree, set prev's left to the right child
            temp->right->parent = prev; // the parent of the right child is prev
            temp->right = nullptr; // get rid of link
            delete temp; // delete node
            size--;
        }
        else{  
            valueOut = temp->value; // set value to the curr value
            prev->left = nullptr; // get rid of the link from prev
            delete temp; // delete curr node
            size--;
        }
        
        // if(temp->dup == true){ // handle dups

        // }
        // handle dups in root and normal 
        // handle deleting root // if prev is nullptr

        return valueOut;

    }
    
    //
    // Size:
    //
    // Returns the # of elements in the priority queue, 0 if empty.
    // O(1)
    //
    int Size() {
        return size;
    }
    
    //
    // begin
    //
    // Resets internal state for an inorder traversal.  After the
    // call to begin(), the internal state denotes the first inorder
    // node; this ensure that first call to next() function returns
    // the first inorder node value.
    //
    // O(logn), where n is number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (tree.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    void begin() {
        NODE *temp = root;
        if(temp == nullptr || size == 0){
            return;
        }
        while(temp->left != nullptr){ // traverse
            temp = temp->left; // go all the way left
        }
    }
    
    //
    // next
    //
    // Uses the internal state to return the next inorder priority, and
    // then advances the internal state in anticipation of future
    // calls.  If a value/priority are in fact returned (via the reference
    // parameter), true is also returned.
    //
    // False is returned when the internal state has reached null,
    // meaning no more values/priorities are available.  This is the end of the
    // inorder traversal.
    //
    // O(logn), where n is the number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (pq.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    //
    bool next(T& value, int &priority) {
        node *temp = curr;
        if(temp != nullptr){
            
        }
    }
    
    //
    // toString:
    //
    // Returns a string of the entire priority queue, in order.  Format:
    // "1 value: Ben
    //  2 value: Jen
    //  2 value: Sven
    //  3 value: Gwen"
    //
    string toString(){ 
        stringstream ss; 
        NODE *temp = root; 
        // inorder traversal
        toStringHelper(temp, ss); // call helper function
        temp = root;
        
        return ss.str();  
    }
    
    //
    // peek:
    //
    // returns the value of the next element in the priority queue but does not
    // remove the item from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number of
    // duplicate priorities
    //
    T peek() {
        T valueOut;
        NODE *temp = root;  
        while(temp->left != nullptr){ // traverse thru tree
            temp = temp->left; // keep going left
        }
        valueOut = temp->value; // find the value of the lowest prio
        return valueOut;
    }
    //
    // ==operator
    //
    // Returns true if this priority queue as the priority queue passed in as
    // other.  Otherwise returns false.
    // O(n), where n is total number of nodes in custom BST
    //
    bool operator==(const priorityqueue& other) const {

        if(this->size != other.size){
            return false;
        }
        else{
            return doubleEqualsHelper(this->root, other.root); // call helper function
        }
    }
    
    //
    // getRoot - Do not edit/change!
    //
    // Used for testing the BST.
    // return the root node for testing.
    //
    void* getRoot() {
        return root;
    }
};

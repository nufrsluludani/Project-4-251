// #include <gtest/gtest.h> // does not work
#include "priorityqueue.h"
#include <map>
#include <vector>


// TO DO: write lots of tests here.
// UNIT TESTS SINCE GOOGLE TESTS ARE NOT WORKING

// enqueue
void testEnqueue(){
    map<int, vector<int> > map;
    int n = 7;
    int vals[] = {15, 5, 9, 7, 17, 11, 20};
    int prs[] = {5, 3, 4, 1, 8, 6, 9};
    priorityqueue<int> pq;

    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    if(pq.Size() == n){
        cout << "Testing size" << endl;
        cout << "N: size " << n << endl; 
        cout << "PQ size: " << pq.Size() << endl;
        cout << "testEnqueue works" << endl << endl;
    }
    else{
        cout << "testEnqueue failed" << endl << endl;
    }
}

void testEnqueue2(){
    map<int, vector<int> > map;
    int n = 7;
    int vals[] = {15, 5, 9, 7, 17, 11, 20};
    int prs[] = {5, 3, 1, 1, 8, 6, 9};
    priorityqueue<int> pq;

    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    
    cout << "handling duplicates.... " << endl;
    cout << pq.toString();
    cout << "testEnqueue2 works" << endl << endl;
    if(pq.Size() != n){
        cout << "testEnqueue2 failed" << endl << endl;
    }
}

void testEnqueue3(){
    map<int, vector<int> > map;
    int n = 7;
    int vals[] = {15, 5, 9, 7, 17, 11, 21};
    int prs[] = {5, 3, 1, 10, 8, 6, 9};
    priorityqueue<int> pq;

    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    cout << "testing if PQ is enqueing values" << endl;
    cout << pq.toString();
    cout << "testEnqueue3 works" << endl << endl;
    if(pq.Size() != n){
        cout << "testEnqueue3 failed" << endl << endl;
    }
}

void testEnqueue4(){
    map<int, vector<string> > map;
    int n = 4;
    string vals[] = {"daniel", "louis", "roe", "martin"};
    int prs[] = {5, 3, 1, 10,};
    priorityqueue<string> pq;

    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    cout << "testing enqueue for type string PQ: " << endl;
    cout << pq.toString();
    cout << "testEnqueue4 works" << endl << endl;
    if(pq.Size() != n){
        cout << "testEnqueue4 failed" << endl << endl;
    }
}

void testEnqueue5(){
    map<int, vector<string> > map;
    int n = 4;
    string vals[] = {"daniel", "louis", "roe", "martin"};
    int prs[] = {5, 1, 1, 10,};
    priorityqueue<string> pq;

    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    cout << "testing enqueue for type string PQ: " << endl;
    cout << "testing duplicates" << endl;
    cout << pq.toString();
    cout << "testEnqueue5 works" << endl << endl;
    if(pq.Size() != n){
        cout << "testEnqueue5 failed" << endl << endl;
    }
}

void testEnqueue6(){
    map<int, vector<double> > map;
    int n = 7;
    double vals[] = {15.101, 5.99, 9.81, 7.65, 17.12, 11.43, 21.1231};
    int prs[] = {5, 3, 1, 10, 8, 6, 9};
    priorityqueue<double> pq;

    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    cout << "testing size for type double PQ: " << endl;
    cout << pq.toString();
    cout << "testEnqueue6 works" << endl << endl;
    if(pq.Size() != n){
        cout << "testEnqueue6 failed" << endl << endl;
    }
}

////////////////////////////////////////////////////////////////////
// constructor
void testDefaultConstructor(){
    priorityqueue<int> pq;
    if(pq.Size() == 0){
        cout << "testDefaultConstructor works" << endl << endl;
    }
    else{
        cout << "testDefaultConstructor failed" << endl << endl;
    }
}

/////////////////////////////////////////////////////////////////////
// size

void testSize(){
    map<int, vector<string> > map;
    int n = 3;
    string vals[] = {"daniel", "jack", "martin"};
    int prs[] = {5, 3, 1};
    priorityqueue<string> pq;

    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    cout << "testing size for type string PQ: " << endl;
    if(pq.Size() == n){
        cout << "Testing size" << endl;
        cout << "N: size " << n << endl; 
        cout << "PQ size: " << pq.Size() << endl;
        cout << "testSize works" << endl << endl;
    }
    else{
        cout << "testSize failed" << endl << endl;
    }
}

void testSize2(){
    map<int, vector<int> > map;
    int n = 7;
    int vals[] = {15, 5, 9, 7, 17, 11, 21};
    int prs[] = {5, 3, 1, 10, 8, 6, 9};
    priorityqueue<int> pq;

    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    cout << "testing size for type int PQ: " << endl;
    if(pq.Size() == n){
        cout << "Testing size" << endl;
        cout << "N: size " << n << endl; 
        cout << "PQ size: " << pq.Size() << endl;
        cout << "testSize2 works" << endl << endl;
    }
    else{
        cout << "testSize2 failed" << endl << endl;
    }
}

void testSize3(){
    map<int, vector<double> > map;
    int n = 7;
    double vals[] = {15.101, 5.99, 9.81, 7.65, 17.12, 11.43, 21.1231};
    int prs[] = {5, 3, 1, 10, 8, 6, 9};
    priorityqueue<double> pq;

    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    cout << "testing size for type double PQ: " << endl;
    if(pq.Size() == n){
        cout << "Testing size" << endl;
        cout << "N: size " << n << endl; 
        cout << "PQ size: " << pq.Size() << endl;
        cout << "testSize3 works" << endl << endl;
    }
    else{
        cout << "testSize3 failed" << endl << endl;
    }
}

//////////////////////////////////////////////////////////////////////////
// test toString

void testToString(){
    map<int, vector<int> > map;
    int n = 7;
    int vals[] = {15, 5, 9, 7, 17, 11, 20};
    int prs[] = {5, 3, 1, 1, 8, 6, 9};
    priorityqueue<int> pq;

    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    cout << "testing toString of type int" << endl;
    cout << pq.toString();
    cout << "testToString works" << endl << endl;
    if(pq.Size() != n){
        cout << "testToString  failed" << endl << endl;
    }
}

void testToString2(){
    map<int, vector<string> > map;
    int n = 3;
    string vals[] = {"daniel", "jack", "martin"};
    int prs[] = {5, 3, 1};
    priorityqueue<string> pq;

    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    cout << "testing toString of type string" << endl;
    cout << pq.toString();
    cout << "testToString2 works" << endl << endl;
    if(pq.Size() != n){
        cout << "testToString2  failed" << endl << endl;
    }
}

void testToString3(){
    map<int, vector<double> > map;
    int n = 7;
    double vals[] = {15.101, 5.99, 9.81, 7.65, 17.12, 11.43, 21.1231};
    int prs[] = {5, 3, 1, 10, 8, 6, 9};
    priorityqueue<double> pq;

    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    cout << "testing toString of type double" << endl;
    cout << pq.toString();
    cout << "testToString3 works" << endl << endl;
    if(pq.Size() != n){
        cout << "testToString3 failed" << endl << endl;
    }
}

//////////////////////////////////////////////////////////////////////////
// test clear

void testClear(){
    map<int, vector<int> > map;
    int n = 7;
    int vals[] = {15, 5, 9, 7, 17, 11, 20};
    int prs[] = {5, 3, 1, 1, 8, 6, 9};
    priorityqueue<int> pq;

    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    cout << "before clear()" << endl;
    cout << pq.toString();
    cout << "after clear()" << endl;
    pq.clear();
    cout << pq.toString();
    if(pq.Size() == 0){
        cout << "testClear works" << endl << endl;
    }
}

//////////////////////////////////////////////////////////////////////////
// test equals

void testEquals(){
    map<int, vector<int> > map;
    
    int n = 7;
    int vals[] = {15, 5, 9, 7, 17, 11, 20};
    int prs[] = {5, 3, 1, 1, 8, 6, 9};
    priorityqueue<int> pq;
    priorityqueue<int> dq;
    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    dq = pq;
    cout << "Pq :" << endl;
    cout << pq.toString();
    cout << "dq :" << endl;
    cout << dq.toString();
    if(pq.Size() == dq.Size()){
        cout << "testEquals works" << endl << endl;
    }
    else{
        cout << "testEquals failed" << endl << endl;
    }
}

void testEquals2(){
    map<int, vector<double> > map;
    int n = 7;
    double vals[] = {15.101, 5.99, 9.81, 7.65, 17.12, 11.43, 21.1231};
    int prs[] = {5, 3, 1, 10, 8, 6, 9};
    priorityqueue<double> pq;
    priorityqueue<double> dq;
    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    dq = pq;
    cout << "Pq :" << endl;
    cout << pq.toString();
    cout << "dq :" << endl;
    cout << dq.toString();
    if(pq.Size() == dq.Size()){
        cout << "testEquals works" << endl << endl;
    }
    else{
        cout << "testEquals failed" << endl << endl;
    }
}

void testEquals3(){
    map<int, vector<string> > map;
    int n = 3;
    string vals[] = {"daniel", "jack", "martin"};
    int prs[] = {5, 3, 1};
    priorityqueue<string> pq;
    priorityqueue<string> dq;

    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    dq = pq;
    cout << "Pq :" << endl;
    cout << pq.toString();
    cout << "dq :" << endl;
    cout << dq.toString();
    if(pq.Size() == dq.Size()){
        cout << "testEquals works" << endl << endl;
    }
    else{
        cout << "testEquals failed" << endl << endl;
    }
}

////////////////////////////////////////////////////////////////
// test begin
void testBegin(){
    map<int, vector<int> > map;
    int n = 7;
    int vals[] = {15, 5, 9, 7, 17, 11, 20};
    int prs[] = {5, 3, 1, 1, 8, 6, 9};
    priorityqueue<int> pq;
    priorityqueue<int> dq;
    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    pq.begin();
    
}

////////////////////////////////////////////////////////////////
// test Dequeue

void testDequeue(){
    map<int, vector<int> > map;
    int n = 7;
    int vals[] = {15, 5, 9, 7, 17, 11, 20};
    int prs[] = {5, 3, 1, 2, 8, 6, 9};
    priorityqueue<int> pq;
    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    cout << "before dequeue" << endl;
    cout << pq.toString();
    cout << pq.Size() << endl;
    cout << "dequeuing.....removing: " << pq.dequeue() << endl;
    cout << "after dequeue" << endl;
    cout << pq.toString();
    if(pq.Size() < n){
        cout << "testDequeue works" << endl << endl;
    }
    else{
        cout << "testDequeue failed" << endl << endl;
    }
}

void testDequeue2(){
    map<int, vector<string> > map;
    int n = 3;
    string vals[] = {"daniel", "jack", "martin"};
    int prs[] = {5, 3, 1};
    priorityqueue<string> pq;       
    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    cout << "before dequeue" << endl;
    cout << pq.toString();
    cout << pq.Size() << endl;
    cout << "dequeuing.....removing: " << pq.dequeue() << endl;
    cout << "after dequeue" << endl;
    cout << pq.toString();
    if(pq.Size() < n){
        cout << "testDequeue works" << endl << endl;
    }
    else{
        cout << "testDequeue failed" << endl << endl;
    }
}

void testDequeue3(){
    map<int, vector<double> > map;
    int n = 7;
    double vals[] = {15.101, 5.99, 9.81, 7.65, 17.12, 11.43, 21.1231};
    int prs[] = {5, 3, 1, 10, 8, 6, 9};
    priorityqueue<double> pq;
    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    cout << "before dequeue" << endl;
    cout << pq.toString();
    cout << pq.Size() << endl;
    cout << "dequeuing.....removing: " << pq.dequeue() << endl;
    cout << "after dequeue" << endl;
    cout << pq.toString();
    if(pq.Size() < n){
        cout << "testDequeue works" << endl << endl;
    }
    else{
        cout << "testDequeue failed" << endl << endl;
    }
}

///////////////////////////////////////////////////////////////////
// test peek

void testPeek(){
    map<int, vector<int> > map;
    int n = 7;
    int vals[] = {15, 5, 9, 7, 17, 11, 20};
    int prs[] = {5, 3, 1, 2, 8, 6, 9};
    priorityqueue<int> pq;
    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    cout << pq.toString();
    cout << "Peek: " << pq.peek() << endl;
    cout << "testPeek works" << endl << endl;
}

///////////////////////////////////////////////////////////////////
// test ==

void testDoubleEquals(){
    map<int, vector<int> > map;
    int n = 7;
    int vals[] = {15, 5, 9, 7, 17, 11, 20};
    int prs[] = {5, 3, 1, 2, 8, 6, 9};
    priorityqueue<int> pq;
    priorityqueue<int> dq;
    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        map[prs[i]].push_back(vals[i]);
    }
    dq = pq;
    if(pq == dq){
        cout << "equal" << endl << endl;
    }
    else{
        cout << "isnt equal" << endl << endl;
    }
}

int main()
{
    // test enqueue
    testEnqueue();
    testEnqueue2();
    testEnqueue3();
    testEnqueue4();
    testEnqueue5();
    testEnqueue6();

    // test default constructor
    testDefaultConstructor();

    // test size
    testSize();
    testSize2();
    testSize3();

    // test toString
    testToString();
    testToString2();
    testToString3();

    // test clear
    testClear();

    // test equals
    testEquals();
    testEquals2();
    testEquals3();

    // test begin

    // test dequeue
    testDequeue();
    testDequeue2();
    testDequeue3();

    //test peek
    testPeek();

    //test doubleEquals
    testDoubleEquals();
}
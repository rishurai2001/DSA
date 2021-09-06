#include <bits/stdc++.h>
using namespace std;

//max-heap/priority queue array based implementation

/*
class priorityQueue{
    int heap[100];
    int heap_size=-1;
    int parent();
    int leftChild();
    int rightChild();
    int getMax();               //O(1)
    void PercolateUp();         // O(log(n))
    void percolateDown();       // O(log(n))
    int extractMax();           // O(log(n))
    void insert();              // O(log(n))
    void changePriority();      // O(log(n))
}
*/

class PriorityQueue{

    int heap[100];                      //this array stores data according to priority
    int heap_size=-1;

                                //root node is at 0-th index
    int parent(int i){
        return (i-1)/2;
    }
    int leftChild(int i){
        return (2*i+1);
    }
    int rightChild(int i){
        return (2*i+2);
    }
    public:
    // this is done after :
    //1. inserting any node at the end of array(or after lowest node of binary heap) 
    //2. increasing the priority of any node

    void percolateUp(int i){
        //if(heap_size==100) return;
        //int i=heap_size;
        while(i>0 && heap[i]>heap[parent(i)]){

            swap(heap[i],heap[parent(i)]);
            i=parent(i);
        }

    }
    //this is done after :
    //1. popping the root of binary heap, or decreasing priority of any node;
    //2. decreasing the priority of any node;
    //this function is same as heapify of heap sort
    void percolateDown(int i){
        int l=leftChild(i);
        int r=rightChild(i);
        int maxIndex=i;

        //if  node "i" is smaller than left children 
        if(l<=heap_size && heap[maxIndex]<heap[l]){
            maxIndex=l;
        }

        //if  node "i" is smaller than right children 
        if(r<=heap_size && heap[maxIndex]<heap[r]){
            maxIndex=r;
        }

        //if both left,right children are greater than current node we prefer the maximum of two children to swap with current node
        if(maxIndex!=i) {
            swap(heap[maxIndex],heap[i]);
            percolateDown(maxIndex);
        }
       
    }


    int getMax(){
        if(heap_size==-1) return -1;
        return heap[0];
    }

    
    void insert(int x){
        if(heap_size==99) return;
        heap_size++;
        heap[heap_size]=x;
    }
    int extractMax(){
        int x=heap[0];
        heap[0]=heap[heap_size];
        heap_size--;
        percolateDown(0);
        return x;
    }
    void changePriority(int i,int p){
        int oldP=heap[i];
        heap[i]=p;
        if(oldP>heap[i]){
            percolateDown(i);
        }
        else percolateUp(i);
    }

};

signed main(){
    PriorityQueue obj;

    return 0;
}

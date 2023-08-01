#include<iostream>
#include<vector>
using namespace std;
//heap is best dealt with array
//heap is of min/max type
//heap has functions like insertion with rearrangement
//deletion of elements
//heapify and much more
//here we can use basic array to implement but can make a pseudo vector in c to accomodate all elements
//its a bianry tree with complete binary tree property as well as its own heap order property


//if used in a array. the level order traversal takes o(n) time
//where in linked nodes , its fking idiotism
//VIUALIZE IT AS A TREE but process it in array
//in array, the Oth index is reserved, root is at 1 index
//for a node at i index,, the left and right childrens are respectively 2i and 2i+1

//doing insertion in heap represented in array with take o(1)
//while doing level order search in node tree is very tedious


//in a nutshell
//use array or get smarter
//in array first n/2+1 element are 2nd order node (are fathers of some nodes) 

class Heap{
        vector<int> v;
        bool isminheap;
    
    private:

        bool compare(int a,int b){
            return isminheap?a<b:b>a;
        }
        void swap(int i,int j){
            int temp=v[i];
            v[i]=v[j];
            v[j]=temp;
        }
        void heapify(int I){
            int left=2*I;
            int right=left+1;
            int high_priority=I;
            int last=v.size()-1;
            
            if(left<=last && compare(v[left],v[high_priority]))
            high_priority=left;
            if(right<=last && compare(v[right],v[high_priority]))
            high_priority=right;

            if(high_priority!=I){
                swap(I,high_priority);
                heapify(high_priority);//fix the effected sub-heap;
            }
        }

        void buildheapfromarray(){//O(nlogn)
            for(int i=1;i<v.size();i++){
                int idx=i;
                int parent=i/2;
                while(idx>0 && v[idx]>v[parent]){
                    swap(v[idx],v[parent]);
                    idx=parent;
                    parent=idx/2;
                }
            }
        }

        void heapifyPRO(){//O(n)
            for(int i=(v.size()-1)/2;i>0;i--){
                heapify(i);
            }
        }

    public:

        Heap(bool type=0,int defaultsize=10){
            v.reserve(defaultsize);
            isminheap=type;
            v.push_back(-1);
        }

        void push(int d){
            v.push_back(d);
            int idx=v.size()-1;
            int parent=idx/2;
            while(idx>=0 && compare(v[idx],v[parent])){
                swap(idx,parent);
                idx=parent;
                parent=idx/2;
            }
        }

        int top(){
            return v[1];
        }

        void pop(){
            int last=v.size()-1;
            swap(1,last);
            v.pop_back();
            heapify(1);
        }
        
        bool empty(){
            return v.size()==1;
        }
};


int main(){
    Heap h;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        h.push(no);
    }
    while(!h.empty()){
        cout<<h.top()<<endl;
        h.pop();
        //test
    }
} 
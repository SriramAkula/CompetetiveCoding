#include <iostream>
using namespace std;


class MinHeap{
    public:
        int arr[100];
        int size;
        MinHeap(){
            size=0;
        }
        void insert(int x){
            size++;
            arr[size-1]=x;
            int i=size-1;
            heapifyUp(i);
        }
        int extractMin(){
            if(size<=0){
                return -1;
            }
            int minVal=arr[0];
            swap(arr[0],arr[size-1]);
            size--;
            heapifyDown(0);
            return minVal;
        }
        void heapifyUp(int i) {
            while (i > 0) {
                int parent = (i - 1) / 2;
                if (arr[parent] > arr[i]) {
                    swap(arr[parent], arr[i]);
                    i = parent;
                } else {
                    break;
                }
            }
        }
        void heapifyDown(int i){
    
            while(2*i+1<size){

                int left=2*i+1;
                int right=2*i+2;
                int smallest=i;
                if(left<size && arr[left]<=arr[smallest]){
                    smallest=left;
                }
                if(right<size && arr[right]<=arr[smallest]){
                    smallest=right;
                }
                if(smallest!=i){
                    swap(arr[i],arr[smallest]);
                    i=smallest;
                }else{
                    break;
                }

            }


        }
        void deleteEl(int x){
            int i=0;
            for(i=0;i<size;i++){
                if(arr[i]==x){
                    break;
                }
            }
            if(i==size){
                cout<<"No Element Found"<<endl;
                return;
            }
            arr[i]=arr[size-1];
            size--;
            int parent = (i - 1) / 2;
            if (i > 0 && arr[i] < arr[parent]) {
                heapifyUp(i);
            } else {
                heapifyDown(i);
            }
        }
        void print(){
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main() {
    MinHeap h;
    h.insert(20);
    h.insert(7);
    h.insert(10);
    h.insert(40);
    h.insert(5);
    h.insert(70);
    h.insert(50);
    h.print();
    cout<<h.extractMin()<<endl;
    h.print();
    h.deleteEl(20);
    h.print();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
//using max priority queue to sort in the increasing order
void heap_sort(vector<int>&arr,int n){
    for(int i=1;i<n;i++){
        int child=i;

        while(child>0){
        int parent=(child-1)/2;            
            if(arr[parent]<arr[child]){
                int temp=arr[child];
                arr[child]=arr[parent];
                arr[parent]=temp;
                child=parent;
            }
            else{
                break;
            }
        }
    }
    int s=n;
    while(s>1){
    int temp=arr[s-1];
    arr[s-1]=arr[0];
    arr[0]=temp;
    s--;
    
    for(int j=0;j<s;j++){
        int parent=j;
        int max1=-1;
        while(parent<s){
            int child1=2*parent+1;
            int child2=2*parent+2;
            if(child1<s && child2<s){
                if(arr[child1]>arr[child2]){
                    max1=child1;
                }
                else if(arr[child1]<arr[child2]){
                    max1=child2;
                }
            }
            else if(child1<s){
                max1=child1;
            }
            else{
                break;
            }
         if(arr[max1]>arr[parent]){
            int temp1=arr[max1];
            arr[max1]=arr[parent];
            arr[parent]=temp1;
            parent=max1;
        }
         else{
            break;
        }
        }
        
    }
    }

}
int main(){
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        arr.push_back(j);
    }
    heap_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
//Write a program to implement insertion sort with time complexity
//Write a program to implement heap tree for insertion and deletion 
//Write a program to implement heap sort
#include <bits/stdc++.h>
using namespace std;
void insert_heap(vector<int> &arr,int x){
        
    arr.push_back(x);
    int child=arr.size()-1;

       
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
void delete_heap(vector<int> &arr){
    int s=arr.size();
    int del=arr[0];
    int temp=arr[arr.size()-1];
    arr[0]=temp;
    s--;
    int parent=0;

    while(parent<s){
        int min_index=-1;
        int child1=2*parent+1;
        int child2=2*parent+2;

        if(child1<s && child2<s){
            if(arr[child1]<arr[child2]){
                min_index=child1;
            }
            else if(arr[child1]>arr[child2]){
                min_index=child2;
            }
        }
        else if(child1<s){
            min_index=child1;
        }
        else{
            break;
        }

        if(arr[min_index]<arr[parent]){
            int temp=arr[parent];
            arr[parent]=arr[child1];
            arr[child1]=temp;
            parent=min_index;
        }
        else{
            break;
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
        insert_heap(arr,j);
    }
    delete_heap(arr);
        for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
    }

    return 0;
}
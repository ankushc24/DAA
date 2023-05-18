#include<bits/stdc++.h>
using namespace std;
int main()
{ int n;
 clock_t start_t,end_t;
 double total_t;
 start_t=clock();
 cout<<" enter the no. of elements n: ";
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++){
 cout<< i <<" Enter the element : ";
 cin>>arr[i];}
for(int i=0;i<n;i++){
 for(int j=i+1;j<n;j++){
 if(arr[i]>arr[j]){
 int temp=arr[i];
 arr[i]=arr[j];
 arr[j]=temp;
 cout<<" the array after swap: ";
 for(int a=0;a<n;a++){
     cout<<arr[a]<<" ";}
    cout<<endl;}}}
    for(int i=0;i<n;i++){
        cout<< arr[i] <<" ";}
    end_t=clock();
 cout<<endl;
 cout<<" total time taken: "<<(double)(end_t-start_t)/CLOCKS_PER_SEC;
 int p;
 int size=sizeof(int);
 cout<<endl;
 cout<<" the memory occupied is: "<<size*(n+5);
 return 0;
}
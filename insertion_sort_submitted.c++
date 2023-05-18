#include <iostream>
#include <time.h>
using namespace std;

int bytes;

void printArray(int array[], int size) 
{
  int i;
  for (i = 0; i < size; i++) 
  {
    cout << array[i] << " ";
  }
  cout << endl;
  bytes+=sizeof(i);
}

void insertionSort(int array[], int size) 
{
  int step,key,j;
  int k=1;
  for (step = 1; step < size; step++) 
  {
    key = array[step];
    j = step - 1;
    while (key < array[j] && j >= 0)
    {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
    cout<<"PASS"<<k<<"-->";
    printArray(array, size);
    k++;
  }
  bytes+=sizeof(step)+sizeof(key)+sizeof(j);
}

int main() 
{
  clock_t begin=clock();
  int e,f;
  cout<<"Enter number of elements to sort : ";
  cin>>e;
  int data[e];
  cout<<"Enter elements to sort : ";
  for (f = 0; f < e; ++f)
  {
      cin >> data[f];
  }
  int size = sizeof(data) / sizeof(data[0]);
  insertionSort(data, size);
  cout << "Sorted array : ";
  printArray(data, size);
  bytes+=sizeof(e)+sizeof(f)+sizeof(data)+sizeof(size);
  cout<<"Number of bytes : "<<bytes<<endl;
  clock_t end=clock();
  cout<<"Execution time : "<<(double)(end-begin)/CLOCKS_PER_SEC<<endl;
}
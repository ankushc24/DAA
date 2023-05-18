int  partition(int input[],int start,int end)
{
   int piviot=input[start];
   int count=0;
   for(int i=start+1;i<=end;i++)
   {
	   if(piviot>=input[i])
	   {
          count++;
	   }
   }
   int position=start+count;
   int temp = input[position];
   input[position] =piviot;
   input[start] = temp;
   int i=start,j=end;
   while(i<j)
   {
	   while(input[i]<=piviot)
	   {
          i++;
	   }
	   while(input[j]>piviot)
	   {
		   j--;
	   }
           if (i < j) 
		   {
             int temp = input[i];
             input[i] = input[j];
             input[j] = temp;
			 i++;
			 j--;
           }
   }
   return position;
}
void quickSort1(int input[], int start, int end) {
  // your code goes here
  if(start>=end)
  {
	  return;
  }
  int c=partition(input,start,end);
  quickSort1(input,start,c-1);
  quickSort1(input,c+1,end);
}

void quickSort(int input[], int size) 
{ 
	quickSort1(input, 0, size - 1); 
}
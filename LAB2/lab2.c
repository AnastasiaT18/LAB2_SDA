#include <stdio.h>

//the function which checks whether there are duplicate elements or not in the array
int check(int A[], int n){
 int status = 1;
for(int i=0; i<n-1;i++){
    int check=A[i];
    for(int j=i+1;j<n;j++){
        if (A[j] ==check){
            status=0;
            return status;
        }
    }
    }
    return status;
    
}

//the function which rearranges the elements of the array according to the condition:
//so that every second element is bigger than its neighbors
void rearrange(int arr[], int n){
    int small[10], big[10], max,k,j,i, maxind;
    int maxelements=n/2; //calculates the number second-positions in the array


    //this block of code finds the maximum element of the array
    j = 0;  
    max = arr[0];
    for(int i=0;i<n;i++){
      if (arr[i]>max){
        max = arr[i];
        maxind=i;
      }
    }
    
    //here, in the array "big", the biggest elements of the array are stored
    //the number of the biggest elements is equal to the maxelements variable
    big[j]=max; //the first element of the "big" array is the maximum element of the original array

    
    //the loop finds the other biggest elements and fills in the "big" array
    for(j=1;j<maxelements;j++){
      i=0;
      max = arr[0];
      while(max>=big[j-1]){
         i++;
         max=arr[i];
      }    
      for(int i=0;i<n;i++){
        if(arr[i]>max && arr[i]<big[j-1]){
            max = arr[i];
            maxind=i;
        }
      }
      big[j]=max;
    }

    
    int jbig=j; //jbig variable represents the number of elements of the "big" array

    //here the "small" array is initialized, it contains all the other elements of the 
    //array, the ones smaller than the elements in the "big" array
    j=0;
    for(i=0;i<n;i++){
      if(arr[i]<big[jbig-1]){
        small[j]=arr[i];
        j++;
      }
    }
    int jsmall=j; //jsmall variable represents the number of elements of the "small" array

//finally, the array is updated: at every second position an element of the "big" array is inserted
j=0;
for(i=1;i<n;i+=2){    
  arr[i]=big[j];
  j++;}

//at all the other positions left, an element of the "small" array is inserted
j=0;
for(i=0;i<n;i+=2){
  arr[i]=small[j];
  j++;}

}

//function which prints the array
void display(int a[], int n){
  for(int i=0;i<n;i++){
     printf("%d  ", a[i]);
  }
  printf("\n");
}

//function which swaps values
void swap(int *a, int *b){
  int t=*a;
  *a=*b;
  *b=t;
}

//function essential for the quick sort method, it specifies the pivot is at the end and 
//traverses the array, compares values with the pivot and makes necessary swaps
int partition(int arr[], int start, int end, int type){
 int pivot = arr[end];
 int i=start-1;
 int j,t;
 
 if (type==1){ //type = 1 so the sorting will be ascending
  for(j=start;j<end;j++){
  if(arr[j]<=pivot){
    i++;
    swap(arr+i, arr+j);
  }
 }
 swap(arr+end, arr+i+1);

return i+1;
 }

 else{ //type = 0 so the sorting will be descending
  for(j=start;j<end;j++){
  if(arr[j]>=pivot){
    i++;
    swap(arr+i, arr+j);
  }
 }
 swap(arr+end, arr+i+1);

return i+1;
 }

 
}

//function essential for the quick sort method, partitions the array according to the pivot and 
//recursively calls the quicksort function until the array is fully sorted
void quicksort(int arr[], int start, int end, int type){
   if(start<end){
     int pivot = partition(arr,start, end, type);
     quicksort(arr,start, pivot-1, type);
     quicksort(arr, pivot+1, end, type);
   }
   
}

//function which performs shellsort
void shellsort(int arr[], int n, int type){
  int t,i,j;
  for(int interval=n/2;interval>0;interval/=2){
    for( i=interval;i<n;i++){
      t = arr[i];
      if (type==1){ //type = 1 so the sorting will be ascending
        for(j=i;j>=interval && arr[j-interval]>t;j-=interval){
          arr[j]=arr[j-interval];
      }}
      else{ //type = 0 so the sorting will be descending
        for(j=i;j>=interval && arr[j-interval]<t;j-=interval){
          arr[j]=arr[j-interval];
      }
      }
       arr[j]=t;
      }
     
    }
  }


int main(){
//varianta 23
int A[50], n,i,j, status, copy[50];

status = 0;

//a loop which doesn't allow the user to proceed unless 
//the array has distinct elements
while(status==0){ 
   printf("Enter n:"); scanf("%d", &n); //reading the number of elements of the vector
    for(i=0;i<n;i++){                   //reading the vector elements
       scanf("%d", &A[i]);
}

   status = check(A,n); //here the condition which guides the iteration is checked 
    if (status == 1){
    printf("There are no duplicate elements.");
   }else{
    printf("There are duplicate elements. Read elements again.");
   }
}


for(i=0;i<n;i++){ //creating a copy of the original vector A
    printf("%d  ", A[i]);
    copy[i]=A[i];
}
printf("\n");

//Task 1: the rearranging of the elements of the vector
rearrange(copy,n);

//Task 2: displaying the original array and the modified array
printf("Original array:");
display(A,n);

printf("Modified array:");
display(copy,n);

//Task 3: sorting (both ascendingly and descendingly) using Quick Sort and displaying the original vector 
printf("Ascending sorting of original vector (QuickSort):");
int type = 1; //this variable indicates whether the sort will be ascending(1) or descending(0)
quicksort(A,0,n-1, type);
display(A,n);  
printf("\n");

printf("Descending sorting of original vector (QuickSort):");
type = 0; //indicates the descending sort
quicksort(A,0,n-1, type);
display(A,n); 
printf("\n");

//Task 4: sorting (both ascendingly and descendingly) using Shell Sort and displaying the modified vector 
printf("Ascending sorting of modified vector (ShellSort):");
type = 1; 
shellsort(copy,n, type);
display(copy,n);
printf("\n");

printf("Descending sorting of modified vector (ShellSort):");
type = 0; 
shellsort(copy,n, type);
display(copy,n);
printf("\n");



return 0;
}
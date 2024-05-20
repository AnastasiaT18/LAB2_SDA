#include <stdio.h>

//function which checks whether all the elements of the vector are positive
int checkpositive(int arr[], int n){
    for(int i=0;i<n;i++){
        if(arr[i]<=0){
            return 0;
        }
    }
    return 1;
}

//function which checks the triangle inequality
int condition(int a, int b, int c){
    if (a+b>c && a+c>b && b+c>a){
        return 1;
    }
    else{
        return 0;
    }
}

//function which checks if every 3 consecutive elements of the vector can represent lengths of a triangle
//the "condition" function is called here too
void checktriangles(int arr[],int results[], int n){
    for(int i=0;i<n;i++){
        if (i==0 || i==n-1){
            results[i]=0;
        } else if (condition(arr[i-1], arr[i], arr[i+1])==1){
            results[i]=1;
        }
        else{
            results[i]=0;
        }
    }
}

//function which prints the array
void display(int a[], int n){
  for(int i=0;i<n;i++){
     printf("%d  ", a[i]);
  }
  printf("\n");
}

//function which performs the counting sort of an array
void counting(int arr[], int n){
    int i,max,count[50], final[50];

    max=arr[0];
    for(i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }

    for(i=0;i<max+1;i++){
        count[i]=0;
    }

    for(i=0;i<n;i++){
        count[arr[i]]++;
    }

    for(i=1;i<max+1;i++){
        count[i]+=count[i-1];
    }

    for(i=n-1;i>=0;i--){
       final[count[arr[i]]-1]=arr[i];
       count[arr[i]]--;
    }

    for(i=0;i<n;i++){
        arr[i] = final[i];
    }
}

//function which recursively divides the initial array into smaller subarrays so that it can be sorted using Merge Sort
void dividemerge(int arr[], int a, int b, int type){
    int m;
    if (a<b){
      m=(a+b)/2;
      dividemerge(arr, a, m, type);
      dividemerge(arr,m+1,b, type);
      mergesort(arr, a,m,b, type);
    }
} 

//function essential for the Merge Sort
void mergesort(int arr[], int a, int m, int b, int type){
    int n1,n2,i,j,k;
    n1=m-a+1;
    n2=b-m;
    int L[n1], R[n2];

    for(i=0;i<n1;i++){
        L[i]=arr[a+i];
    }
    
    for(j=0;j<n2;j++){
        R[j]=arr[m+1+j];
    }

    i=0;j=0;k=a;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            if(type==1){
                arr[k]=L[i];
                i++;
            }
            else{
               arr[k]=R[j];
                j++; 
            }
            
        }
        else{
             if(type==1){
                arr[k]=R[j];
                j++; 
            }
            else{
               arr[k]=L[i];
                i++; 
            }  
        }
        k++;
    }

    while(i<n1){
        arr[k]=L[i];
        k++;
        i++;
    }

    while(j<n2){
        arr[k]=R[j];
        k++;
        j++;
    }
    

}

int main(){
//varianta 23 - modified version
int A[50], n,i,j, status, results[50];

status = 0;

//a loop which doesn't allow the user to proceed unless 
//the array has positive elements
while(status==0){
   printf("\nEnter n:"); scanf("%d", &n);  //reading the number of elements of the vector
    for(i=0;i<n;i++){
       scanf("%d", &A[i]);      //reading the vector elements
       results[i]=A[i];         //creating a copy of the original vector A
}
  
   status = checkpositive(A,n);   //here the condition which guides the iteration is checked 
   if (status == 1){
    printf("There are only positive elements.");
   }else{
    printf("There are nonpositive elements. Read elements again.");
   }
}

//Task 1: the "checktriangles" function is called and the "results" array is filled
checktriangles(A, results,n);

//Task 2: displaying the original array and the modified array
printf("Original array:");
display(A,n);

printf("Modified array:");
display(results,n);

//Task 3: sorting the original vector using Counting Sort in an ascending manner
printf("Ascending sorting of original vector using counting sort:");
counting(A,n);
display(A,n);


//Task 4: Sorting the modified vector using Merge Sort, both ascendingly and descendingly
int type=1;
printf("Ascending sorting of modified vector using merge sort:");
dividemerge(results,0,n-1, type);
display(results,n);

type=0;
printf("Descending sorting of modified vector using merge sort:");
dividemerge(results, 0,n-1,type);
display(results, n);



}


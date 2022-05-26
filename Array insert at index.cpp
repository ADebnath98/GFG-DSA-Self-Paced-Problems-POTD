// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

    // You need to insert the given element at the given index. 
    // After inserting the elements at index, elements
    // from index onward should be shifted one position ahead
    // You may assume that the array already has sizeOfArray - 1
    // elements.
    void insertAtIndex(int arr[], int sizeOfArray, int index, int element)
    {
        //Your code here
        for(int i = sizeOfArray - 1; i>index; i--){
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        
        
        
    }

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);//Input testcases
    while(t--)
    {
        
        int sizeOfArray; 
        
        //input size of Array
        scanf("%d", &sizeOfArray);
        
        int arr[sizeOfArray];
        
        //input elements in the Array
        for(int i = 0; i < sizeOfArray-1; i++)
            scanf("%d", &arr[i]);
        
        int index;
        //input index
        scanf("%d", &index);
        int element;
        //input element
        scanf("%d", &element);
        //calling insertAtIndex() function
        insertAtIndex(arr, sizeOfArray, index, element); //Complete this function
        
        for(int i = 0; i < sizeOfArray; i++)//Printing the array for verification
            printf("%d ", arr[i]);
        
        printf("\n");
        
    }
    
	return 0;
}  // } Driver Code Ends
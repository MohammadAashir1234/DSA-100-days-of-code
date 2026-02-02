/**Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.
Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)
Output:
- Print the updated array with (n-1) elements, space-separated
Example:
Input:
5
10 20 30 40 50
2
Output:
10 30 40 50
Explanation: Delete position 2 (element 20), remaining elements shift left**/

#include <stdio.h>                              // including standard input-output header file
#define maxsize 100                             // defining maximum size of the array
int main() {                                    // main function
    int n, arr[ maxsize ],pos;                  // declaring variables
    scanf("%d",&n);                             // reading size of the array
    for (int i=0;i<n;i++) {                     // loop to read array elements
        scanf("%d",&arr[i]);                    // reading each element
    } 
    scanf("%d",&pos);                           // reading position to delete
    pos--;                                      // converting to 0-based index
    for (int i=pos;i<n-1;i++){                  // loop to shift elements left
        arr[i]=arr[i+1];                        // shifting element
    } 
    n--;                                        // reducing size of array
    for(int i=0;i<n;i++){                       // loop to print updated array
        printf("%d",arr[i]);                    // printing each element
        if (i<n-1){                             // condition to avoid trailing space
            printf(" ");                        // printing space
        }  
    }
    return 0;                                   // returning 0 to indicate successful execution
    }

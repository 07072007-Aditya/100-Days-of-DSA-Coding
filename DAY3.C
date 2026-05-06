/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)*/
#include<stdio.h>
int main(){
    int n;
    printf("enter no. of Elements  ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter elements: ");
        scanf("%d",&arr[i]);
    }
    int s,count=1;
    printf("Enter key to search: ");
    scanf("%d",&s);
    for(int i=0;i<n;i++){
        if(arr[i]==s){
            printf("%d found at %d\n",s,i+1);
            printf("comparisons= %d",count);
            break;}
        count+=1;
        
        
    }
    return 0;
}
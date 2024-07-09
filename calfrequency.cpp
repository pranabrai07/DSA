#include <bits/stdc++.h>
using namespace std;

int main() 
{ 
    int size;
    cout << "enter the size of the array: ";
    cin>> size; 
    int arr[size]; 
    for (int i = 0; i < size; i++) { 
        cout << "Enter the element: "; 
        scanf("%d", &arr[i]); 
    } 
    
    int n = sizeof(arr)/sizeof(arr[0]); 

    int visited[n];

    for(int i=0; i<n; i++)
    {
        if(visited[i]!=1)
        {
           int count = 1;
           for(int j=i+1; j<n; j++)
            {
              if(arr[i]==arr[j])
              {
                 count++;
                 visited[j]=1;
              }
            }
            cout<<"frequency of "<<arr[i]<<" = "<<count<<endl;
        }
     }

    return 0; 
}


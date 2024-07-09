 #include <iostream>
 #include <conio.h>
#include <stdlib.h>
 using namespace std;
 #define size 5
 int main()
 {
    int arr[size],top=-1,ch,n,i;
    
    for(;;)
    {
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Display\n";
        cout<<"4. Exit\n";
        cout<<"Enter Choice: ";
        cin>>ch;
        
        switch(ch)
        {
            case 1:
                if(top==size-1)
                {
                    cout<<"Stack is full";
                    getch();
                }
                else
                {
                    cout<<"Enter a number ";
                    cin>>n;
                    top++;
                    arr[top]=n;
                }
                break;
                
            case 2:
                if(top==-1)
                {
                    cout<<"Stack is empty";
                    getch();
                }
                else
                {
                    cout<<"Number Popped = "<<arr[top];
                    top--;
                    getch();
                }
                break;
                
            case 3:
                if(top==-1)
                {
                    cout<<"Stack is empty";
                    getch();
                }
                else
                {
                    for(i=top; i>=0; i--)
                    {
                        cout<<arr[i]<<endl;
                    }
                    getch();
                }
                break;
                
            case 4:
                exit(0);
                break;
                
            default:
                cout<<"Wrong Choice";
                getch();
         }
    }
    return 0;
 }

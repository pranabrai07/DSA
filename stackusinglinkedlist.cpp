 #include <iostream>
 #include <conio.h>
 #include <stdlib.h>
 #include <malloc.h>
 using namespace std;
 #define size 5
 typedef struct node
 {
    int data;
    struct node *next;
 } node;
int main()
 {
    node *start=NULL,*temp;
    int top=0,ch,n;
    
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
                if(top==size)
                {
                    cout<<"Stack is full";
                    getch();
                }
                else
                {
                    cout<<"Enter a number ";
                    cin>>n;
                    
                    
                    temp=new node;
                    temp->data=n;
                    temp->next=NULL;
                    
                    if(start==NULL)
                    {
                        start=temp;
                    }
                    else
                    {
                    
                        temp->next=start;
                        start=temp;
                    }
                    top++;
                }
                break;
                
            case 2:
                if(start==NULL)
                {
                    cout<<"Stack is empty";
                    getch();
                }
                else
                {
                    cout<<"Number Popped = "<<start->data;
                    temp=start;
                    start=start->next;
                    delete temp;
                    top--;
                    getch();
                }
                break;
                
            case 3:
                if(start==NULL)
                {
                    cout<<"Stack is empty";
                    getch();
                }
                else
                {
                    temp=start;
                    
                    
                    while(temp!=NULL)
                    {
                        cout<<temp->data<<endl;
                        temp=temp->next;
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

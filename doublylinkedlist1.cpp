 #include <iostream>
 #include <conio.h>
 #include <stdlib.h>
 #include <malloc.h>
 using namespace std;
 typedef struct node
 {
    int data;
    struct node *prev;
    struct node *next;
 } node;
 int main()
 {
    node *start=NULL,*newnode,*temp,*rn;
    int ch,n,x,c,f;
    
    for(;;)
    {
        cout<<"1. Add\n";
        cout<<"2. Display\n";
        cout<<"3. Insert Before\n";
        cout<<"4. Insert After\n";
        cout<<"5. Delete first node\n";
        cout<<"Enter Choice: ";
        cin>>ch;
        
        switch(ch)
        {
            case 1:
            
                cout<<"Enter a number ";
                cin>>n;
                
                newnode=new node;
                newnode->data=n;
                newnode->prev=NULL;
                newnode->next=NULL;
                
                if(start==NULL)
                {
                    start=newnode;
                }
                else
                {
                    rn=start;
                    
                    
                    while(rn->next!=NULL)
                    {
                        rn=rn->next;
                    }
                    rn->next=newnode;
                    newnode->prev=rn;
                }
                break;
                
            case 2:
                if(start==NULL)
                {
                    cout<<"List is empty";
                    getch();
                }
                else
                {
                    rn=start;
                    
                    
                    while(rn!=NULL)
                    {
                        cout<<rn->data<<" ";
                        rn=rn->next;
                    }
                    getch();
                }
                
                break;
                
            case 3:
                f=0;
                if(start==NULL)
                {
                    cout<<"List is empty";
                    getch();
                }
                else
                {
                    cout<<"Insert Number ";
                    cin>>n;
                    cout<<"Insert Before ";
                    cin>>x;
                    
                    
                    newnode=new node;
                    newnode->data=n;
                    newnode->prev=NULL;
                    newnode->next=NULL;
                    
                    
                    rn=start;
                    while(rn!=NULL)
                    {
                        if(start==rn && rn->data==x)
                        {
                            newnode->next=rn;
                            rn->prev=newnode;
                            start=newnode;
                            f=1;
                            break;
                        }
                        else if(start!=rn && rn->data==x)
                        {
                            newnode->next=rn;
                            newnode->prev=rn->prev;
                            newnode->prev->next=newnode;
                            rn->prev=newnode;
                            f=1;
                            break;
                        }
                        rn=rn->next;
                    }
                    
                    if(f==0)
                    {
                        cout<<"Number not found";
                        delete newnode;
                        getch();
                    }
                }
                break;
                
            case 4:
                f=0;
                if(start==NULL)
                {
                    cout<<"List is empty";
                    getch();
                }
                else
                {
                    cout<<"Insert Number ";
                    cin>>n;
                    cout<<"Insert After ";
                    cin>>x;
                    
                    
                    newnode=new node;
                    newnode->data=n;
                    newnode->prev=NULL;
                    newnode->next=NULL;
                    
                    
                    rn=start;
                    while(rn!=NULL)
                    {
                        if(rn->data==x && rn->next==NULL)
                        {
                            newnode->prev=rn;
                            rn->next=newnode;
                            f=1;
                            break;
                        }
                        else if(rn->data==x && rn->next!=NULL)
                        {
                            newnode->next=rn->next;
                            newnode->next->prev=newnode;
                            newnode->prev=rn;
                            rn->next=newnode;
                            f=1;
                            break;
                        }
                        rn=rn->next;
                    }
                    
                    if(f==0)
                    {
                        cout<<"Number not found";
                        
                        
                        delete newnode;
                        
                        getch();
                    }
                }
                break;
                
            case 5:
            
                if(start==NULL)
                {
                    cout<<"List is empty";
                    getch();
                }
                else
                {
                    rn=start;
                    while(rn!=NULL)
                    {
                    
                        if(rn->next==NULL)
                        {
                            rn->prev->next=NULL;
                            delete rn;
                            f=1;
                            cout<<"Number Deleted Successfully";
                            break;
                        }
                        rn=rn->next;
                    }
                    getch();
                }
                break;
                
                
                
            default:
                cout<<"Wrong Choice";
                getch();
                
        }
    }
    
    
    
    return 0;
}
 

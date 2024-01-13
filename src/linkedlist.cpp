#include <iostream>
using namespace std;
#include <string>

// a node struct
struct Node{
    string url;
    struct Node *next;
};

// add a new URL to the linking list
void append (struct Node** head, string newurl)  {  
    struct Node* newNode1 = new Node;  
    struct Node *last = *head;  
    newNode1 -> url = newurl;  
    newNode1 -> next = NULL;  
    // check if its the first URL
    if ( *head == NULL )  {  
        *head = newNode1;  
        return;  
    }  
    while ( last -> next != NULL )  
    last = last -> next;  
    last -> next = newNode1;    
}  

void displayList(struct Node *node)  
{  
   while ( node != NULL )  
   {  
      cout << node -> url << "-->";  
      node = node -> next;  
   }  
   if ( node== NULL)  {
    cout <<"null" << endl;
   }   
}  
bool isUrlExists(struct Node *node,string urlCheck){
    while (node != NULL)
    {
        if(node -> url.compare(urlCheck) == 0){
            return true;
        }
        node = node ->next;
    }
    return false;
}

int main ()   
{  
struct Node* head = NULL;  
append ( &head, "aa" );   
append ( &head, "25" );   
append ( &head, "35" );   
append ( &head, "45" ); 
cout << "Final linked list: " << endl;  
displayList (head);  
cout << isUrlExists(head,"aa") << endl;   
cout << isUrlExists(head,"25") << endl;
cout << isUrlExists(head,"200") << endl;    
return 0;  
}  

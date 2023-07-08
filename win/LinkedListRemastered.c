#include<stdio.h>
#include<stdlib.h>
////////////////////////////////////////////////////////////
typedef struct node node_t;
typedef node_t* node;
////////////////////////////////////////////////////////////
struct node {
    int data;
    node next;
};
////////////////////////////////////////////////////////////
node createnode_t(int data,node next){
     node ptr=(node)malloc(sizeof(node_t));
     ptr->data=data;
     ptr->next=next;
     return ptr;
}
////////////////////////////////////////////////////////////
void printlist(node head){
    printf("LIST: ");
    while(head!=NULL){
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
/////////////////////////////////////////////////////////////
void addatptr(node*head,int data){
    *head=createnode_t(data,*head);
}
/////////////////////////////////////////////////////////////
void addatlast(node* head,int data){
    if(*head==NULL)
    {addatptr(head,data);return;}
    node temp=*head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=createnode_t(data,temp->next);
    }
////////////////////////////////////////////////////////////
void addatith(node*head,int data,int pos){
    if(pos==-1){addatlast(head,data);return;}
    else if(pos==0){addatptr(head,data);return;}
    else if(*head==NULL){printf("-----------------------------------------\n\004 Error, The List is empty , so try index=0 to add first data node\n");return;}
    node temp=*head;
    int poss=pos;
    pos--;
    while(temp->next!=NULL && pos){
      temp=temp->next;
      pos--;
    }
    if(pos==0)addatptr(&temp->next,data);
    else
    printf("-----------------------------------------\n\004 Error, Unable to add %d at index=%d,that index does not exists\n",data,poss);
    }
//////////////////////////////////////////////////////////// 
void deleteptr(node*head){
    if(*head==NULL){printf("-----------------------------------------\n\004 Error,Cant find element to delete at head, list is empty!!!!!\n");return;}
    node next=(*head)->next;
    free(*head);
    *head=next;
}
////////////////////////////////////////////////////////////
void deletelast(node*head){
    if(*head==NULL){printf("-----------------------------------------\n\004 Error,No item to delete,list is empty\n");return;}
    if((*head)->next==NULL){deleteptr(head);return;}
    node temp=*head;
    while(temp->next->next!=NULL)
    temp=temp->next;
    deleteptr(&(temp->next));
    }
////////////////////////////////////////////////////////////
void deleteatith(node*head,int pos){
    if(pos==0){deleteptr(head);return;}
    else if(pos==-1){deletelast(head);return;}
    else if(*head==NULL){printf("-----------------------------------------\n\004 Error, Unable to delete element at index=%d, that index does not exists\n",pos,pos);return;}
    int poss=pos;
    pos--;
    node temp=*head;
    while((temp->next)!=NULL && pos){
      temp=temp->next;
      pos--;
    }
    if(pos==0 && temp->next!=NULL)deleteptr(&(temp->next));
    else
    printf("-----------------------------------------\n\004 Error, Unable to delete element at index=%d, that index does not exists\n",poss,poss);
}
/////////////////////////////////////////////////////////////
void deleteatmid(node*head){
    node ptr=*head;
    node ptrfast=*head;
    node prev=*head;
    node prev2=*head;
    if(*head==NULL){printf("-----------------------------------------\n\004 Error,no middle element to delete\n");return;}
    if((*head)->next==NULL){printf("-----------------------------------------\n\004 Error,no middle element to delete, the list contain 1 node only\n");return;}
    else if((*head)->next->next==NULL){deleteptr(head);return;}
    while(ptrfast!=NULL && ptrfast->next!=NULL){
     prev2=prev;
     prev=ptr;
     ptr=ptr->next;
     ptrfast=ptrfast->next->next;
    }
    deleteptr(&(prev2->next));

}
/////////////////////////////////////////////////////////////
void reverselist(node *head , int t){
    if(*head==NULL){printf("-----------------------------------------\n\004 Error,List is empty, no need to reverse!!!\n");return;}
    //printf("The old List was:");printlist(*head);
    node curr=*head;
    node prev=curr;
    for(int i=0;i<t && prev!=NULL;i++)
    prev=prev->next;
    node next=NULL;
    while (t-- && curr != NULL){
      // store the next node
      next = curr -> next;
      // reverse the pointer of the current node
      curr ->next = prev;
      // move prev pointer to the current node
      prev = curr;
      // move current to its next node
      curr = next;
    }
    *head=prev;
}
/////////////////////////////////////////////////////////////
void isPalindrome(node *head){
    node ptr=*head;
    node ptrfast=*head;
    node prev=*head;
    node prev2=*head;
    if(*head==NULL){printf("-----------------------------------------\n\004 Error,List is empty, cant check for palindrome\n");return;}
    if((*head)->next==NULL){printf("-----------------------------------------\n\004 Conclusion: The list is a palindrome, the list contain 1 node only\n");return;}
    else if((*head)->next->next==NULL){
        if((*head)->data==(*head)->next->data)printf("-----------------------------------------\n\004 Conclusion: The list is a palindrome\n");
        else printf("-----------------------------------------\n\004 Conclusion: The list is NOT a palindrome\n");
        return;
    }
    int t=0;
    while(ptrfast!=NULL && ptrfast->next!=NULL){
        t++;
     prev2=prev;
     prev=ptr;
     ptr=ptr->next;
     ptrfast=ptrfast->next->next;
    }
    node head2,head1=*head;
    if(ptrfast==NULL){
    reverselist(&(prev->next),100);
    head2=prev->next;}
    else
    {reverselist(&(prev->next->next),100);
    head2=prev->next->next;}
     while(head2!=NULL){
         if(head2->data!=head1->data){printf("-----------------------------------------\n\004 Conclusion: The list is NOT a palindrome\n");break;}
         head1=head1->next;
         head2=head2->next;
     }
     if(head2==NULL)printf("-----------------------------------------\n\004 Conclusion: The list is a palindrome\n");
     if(ptrfast==NULL){
    reverselist(&(prev->next),100);}
    else
    {reverselist(&(prev->next->next),100);}

}
/////////////////////////////////////////////////////////////
int getch();
/////////////////////////////////////////////////////////////
void Kreverse(node *head,int t){
    int tt=t;
    if(*head==NULL)return;
    reverselist(head,t);
    while(tt-- && (*head)!=NULL){
        head=&((*head)->next);
    }
    Kreverse(head,t);
}
/////////////////////////////////////////////////////////////
void insertt(node*t1,node*t2){
    if(*t2==NULL)return;
   node temp=*t1;
   while(temp->next!=*t2)
   temp=temp->next;
   node temp2=temp->next;
   temp->next=temp->next->next;
   temp2->next=*t1;
   *t1=temp2;    
}
/////////////////////////////////////////////////////////////
void mergee(node *head1,int l,int mid,int r){
    if(l==r)return;
 node *h1=head1;
 for(int i=0;i<l;i++){
    h1=&(*h1)->next;
 }
 node *h2=h1;
 for(int i=l;i<=mid;i++){
    h2=&(*h2)->next;
 }
 printf("%d,%d\n",(*h1)->data,(*h2)->data);
 int i1=l,i2=mid+1;
while(i1<=mid && i2<=r){
    printf("checking %d,%d\n",(*h1)->data,(*h2)->data);
    if((*h1)->data<(*h2)->data){
        h1=&(*h1)->next;
        i1++;
    }
    else{
        insertt(h1,h2); 
        h1=&(*h1)->next;
        i2++;  
    }
    printlist(*head1);
}
}
////////////////////////////////////////////////////////////
void mergesortt(node *head1,int l,int r){
    if(r==-1)return;
int mid=(l+r)/2;
    if(l<r){
        mergesortt(head1,l,mid);
        mergesortt(head1,mid+1,r);
        mergee(head1,l,mid,r);
    }
    
}
///////////////////////////////////////////////////////////
void mergesort(node *head1){
    int i;
    node *temp=head1;
    for(i=-1;*head1!=NULL;i++){
     head1=&(*head1)->next;
    }
    printf("count->>%d",i);
    mergesortt(temp,0,i);
}
///////////////////////////////////////////////////////////
int main(){
    node head=NULL;
    int data,index;
    char ch='0';
    addatlast(&head,1);
    addatlast(&head,2);
    addatlast(&head,3);
    addatlast(&head,4);
    addatlast(&head,5);
    addatlast(&head,6);
    addatlast(&head,1);
    addatlast(&head,2);
    addatlast(&head,3);
    addatlast(&head,4);
    addatlast(&head,4);
    addatlast(&head,12);
    addatlast(&head,13);
    addatlast(&head,14);
    addatlast(&head,15);
    addatlast(&head,16);
    node *h2=&head->next->next->next->next;
            node *h1=&head;

    while(1){
        printf("-----------------------------------------\n");
        printlist(head);
        printf("-----------------------------------------\nCommands:\n1 .Add at Start\n2 .Add at Last\n3 .Add at nth index\n4 .Delete first element\n5 .Delete last element\n6 .Delete nth index's element\n7 .Delete middle element\n8 .Reverse the list\n9 .Check if list is Palindrome or not\na .Reverse in groups of k\nb b.MergeSort\n   Enter any other key to exit.\nEnter Your choice\n");
        fflush(stdin);
        ch=getch();
        switch (ch)
        {
        case '1':
            printf("Enter data(integer) that is to be stored\n");
            scanf("%d",&data);
            system("clear");
            addatptr(&head,data);
            break;
        case '2':
            printf("Enter data(integer) that is to be stored\n");
            scanf("%d",&data);
            system("clear");
            addatlast(&head,data);
            break;
        case '3':
            printf("Enter data(integer) that is to be stored\n");
            scanf("%d",&data);
            printf("At which index you want the data to be stored. (index works just like in array, i.e. for first node the index is 0)\n");
            scanf("%d",&index);
            system("clear");
            addatith(&head,data,index);
            break;
        case '4':
            system("clear");
            deleteptr(&head);
            break;
        case '5':
            system("clear");
            deletelast(&head);
            break;
        case '6':
            printf("At which index you want get deleted. (index works just like in array, i.e. for first node the index is 0)\n");
            scanf("%d",&index);
            system("clear");
            deleteatith(&head,index);
            break;
        case '7':
            system("clear");
            deleteatmid(&head);
            break;
        case '8':
            system("clear");
            reverselist(&head,100);
            break;
        case '9':
            system("clear");
            isPalindrome(&head);
            break;
        case 'a':
            printf("Reverse in groups of?\n");
            scanf("%d",&index);
            system("clear");
            Kreverse(&head,index);
            break;
        case 'b':
            mergesort(&head);
            break;
        default:
            printf("Exiting!!!!!");
            exit(1);
        }
    }
}
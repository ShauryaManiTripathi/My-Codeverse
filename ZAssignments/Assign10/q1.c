#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
typedef struct node {int d;struct node* left;struct node* right;} node_t,*Node;

int poww(int a,int b){
    int temp=a;
    for(int i=1;i<b;i++)
    temp*=a;
    return temp;
}

int height(Node root){
    if(root->left==NULL && root->right==NULL)return 0;
        int a,b;
        if(root->left!=NULL) a=1+height(root->left); else a=0;
        if(root->right!=NULL) b=1+height(root->right); else b=0;
        return a>b?a:b;
    
}
int heightV2(Node root){
    if(root==NULL)return 0;
    int lheight=heightV2(root->left),rheight=heightV2(root->right);
    return lheight>rheight?lheight+1:rheight+1;
}

void preorder(Node root){
    printf("%d ",root->d);
    if(root->left!=NULL)preorder(root->left);
    if(root->right!=NULL)preorder(root->right);
}
void inorder(Node root){
    if(root->left!=NULL)inorder(root->left);
    printf("%d ",root->d);
    if(root->right!=NULL)inorder(root->right);
}
void postorder(Node root){
    if(root->left!=NULL)postorder(root->left);
    if(root->right!=NULL)postorder(root->right);
    printf("%d ",root->d);
}

Node construct(int t){
    Node n=(Node)calloc(1,sizeof(node_t));
    n->d=t;
    n->left=NULL;
    n->right=NULL;
    return n;
}

Node constructV2(int t,Node l,Node r){
    Node n=(Node)calloc(1,sizeof(node_t));
    n->d=t;
    n->left=l;
    n->right=r;
    return n;
}
void treeconstruct(int i[],int p[],int n,Node* father){
    if(n==0)return;//this works only if each node is represented by unique value
    int PosInIn;//position(index) in inorder array
    for(PosInIn=0;PosInIn<n;PosInIn++)
    if(i[PosInIn]==p[n-1])break;
    *father=construct(p[n-1]);
    treeconstruct(i,p,PosInIn,&((*father)->left));//left tree
    treeconstruct(i+PosInIn+1,p+PosInIn,n-PosInIn-1,&((*father)->right));//right tree
}
void DecodeTreeIntoArray(int *arr,int index,Node curr){
    arr[index]=curr->d;
    if(curr->left==NULL)arr[2*index+1]=0;
    else DecodeTreeIntoArray(arr,2*index+1,curr->left);
    if(curr->right==NULL)arr[2*index+2]=0;
    else DecodeTreeIntoArray(arr,2*index+2,curr->right);
}
void DisplayLinkedTree(Node root){
    int n=height(root);
    int ele_count=poww(2,n+2)-1; 
    int *arraytree=(int *)calloc(ele_count,sizeof(int));
    DecodeTreeIntoArray(arraytree,0,root);
    int f=1,count=0;
    ele_count+=1;
    ele_count/=2;
    ele_count-=1;
    for(int i=0;i<ele_count;i++){
        count++;
        printf("%d ",arraytree[i]);
        if(count==f){puts("");count=0;f*=2;}
    }
    
    free(arraytree);
}

int findclosestancester(Node root,int a,int b){
    if(!root)return 0;
    if(root->d==a)return a;
    if(root->d==b)return b;
    int aa=findclosestancester(root->left,a ,b);
    int bb=findclosestancester(root->right,a,b);
    if(aa==a&&bb==b ||aa==b&&bb==a)return root->d;
    if(aa)return aa;
    if(bb)return bb;
    return 0;
    
}

void insertBST(Node *root,int t){
   if(*root==NULL)
   {
    *root=construct(t);return;
   }
   if((*root)->d==t)
   {
    (*root)->left=constructV2(t,(*root)->left,NULL);return;
   }
   if(t<(*root)->d)
        if((*root)->left)
            insertBST(&(*root)->left,t);
        else
            (*root)->left=construct(t);
   else
        if((*root)->right)
            insertBST(&(*root)->right,t);
        else
            (*root)->right=construct(t);
}
/////////////////////////////////////////////
void swap(int *a,int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}
/////////////////////////////////////////////This completely heapifies the whole tree, the tree must be complete/
void heapify(Node root);
void maximizenodesofIthlevel(Node root,int level){
    if(root==NULL)return;//no need as it is used for heapify, thus parents are never null
    if(level==1){
        //printf("%d %d\n",root->d,level);
        int *largest,*l,*r;
        int temp=INT_MIN;
        //getting l and r
       if(root->left)l=&root->left->d;
       else l=&temp;
       if(root->right)r=&root->right->d;
       else r=&temp;
       //checking for largest's address
       if(root->d>*l){
        if(root->d>*r)largest=&root->d;
        else largest=r;
       }
       else{
        if(*l>*r)largest=l;
        else largest=r;
       }
       if(largest!=&root->d){
       swap(largest,&root->d);
       heapify((Node)largest);
       }
       //if(root->left && root->right)
       //if(root->left->d<root->right->d)swap(&root->right->d,&root->left->d);   
    }
    else if(level>1){
        maximizenodesofIthlevel(root->left,level-1);
        maximizenodesofIthlevel(root->right,level-1);
    }
}
void heapify(Node root){
    int h = heightV2(root);
    int i;
    for (i = h-1; i >0; i--)
        maximizenodesofIthlevel(root,i);
}
///////////////////////////////////////////
void heapifymin(Node root);
void maximizenodesofIthlevelmin(Node root,int level){
    if(root==NULL)return;//no need as it is used for heapify, thus parents are never null
    if(level==1){
        //printf("%d %d\n",root->d,level);
        int *largest,*l,*r;
        int temp=INT_MAX;
        //getting l and r
       if(root->left)l=&root->left->d;
       else l=&temp;
       if(root->right)r=&root->right->d;
       else r=&temp;
       //checking for largest's address
       if(root->d<*l){
        if(root->d<*r)largest=&root->d;
        else largest=r;
       }
       else{
        if(*l<*r)largest=l;
        else largest=r;
       }
       if(largest!=&root->d){
       swap(largest,&root->d);
       heapifymin((Node)largest);
       }
       //if(root->left && root->right)
       //if(root->left->d<root->right->d)swap(&root->right->d,&root->left->d);   
    }
    else if(level>1){
        maximizenodesofIthlevelmin(root->left,level-1);
        maximizenodesofIthlevelmin(root->right,level-1);
    }
}
void heapifymin(Node root){
    int h = heightV2(root);
    int i;
    for (i = h-1; i >0; i--)
        maximizenodesofIthlevelmin(root,i);
}
/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
/////////////////////////////////////////////////////breadth-first search recursive and decent complexity
//Print nodes at a current level
void printCurrentLevel(Node root, int level){
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d, ",root->d);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
// Function to print level order traversal a tree
void printLevelOrder(Node root)
{
    int h = heightV2(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

int checksameTree(Node root,Node root2){
    if(root==NULL && root2==NULL)return 1;
    if(root==NULL || root2==NULL)return 0;
    if(root->d!=root2->d)return 0;
    int a,b;
        a=checksameTree(root->left,root2->left);
        b=checksameTree(root->right,root2->right);
    printf("%d,%d\n",a,b);
    return a && b;
}
int b=0;
void inorderArrayFill(Node root,int *a){
    if(root->left!=NULL)inorderArrayFill(root->left,a);
    {a[b]=root->d;
    b++;}
    if(root->right!=NULL)inorderArrayFill(root->right,a);
}
int flag=1;
int a=INT_MIN;
void inorderScanCheckBST(Node root){
    if(root->left!=NULL)inorderScanCheckBST(root->left);
    if(a>root->d){flag=0;return;}
    else a=root->d;
    //printf("WOW,%d %d %d\n",root->d,a,flag);
    if(root->right!=NULL)inorderScanCheckBST(root->right);
}

void create_binary_tree(Node *root){
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d",&x);
    if(x==-1)return;
    *root=(Node)malloc(sizeof(struct node));
    (*root)->d=x;
    (*root)->left=NULL;
    (*root)->right=NULL;
    printf("Enter left child of %d:\n",x);
    create_binary_tree(&(*root)->left);
    printf("Enter right child of %d:\n",x);
    create_binary_tree(&(*root)->right);
}
 
int main(){
     Node root=NULL;
    create_binary_tree(&root);
    DisplayLinkedTree(root);
    puts("inorder->");
    inorder(root);
    inorderScanCheckBST(root);
    if(flag)puts("\nIts a bst");
    else puts("\nIts not a bst");
}


#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *left,*right;
};

node* create()
{
    int x;
    cout<<"Enter data (-1 for no node): ";
    cin>>x;
    if(x==-1)
        return 0;
    else
    {
        node *newnode=new node;
        newnode->data=x;
        cout<<"Enter left child of "<<x;
        newnode->left=create();
        cout<<"Enter right child of "<<x;
        newnode->right=create();
        return newnode;
    }
}
void displayInorder(node *root)
{
    if(root==0)
        return;
    displayInorder(root->left);
    cout<<root->data<<" ";
    displayInorder(root->right);
}
int main()
{
    node *root=create();
    displayInorder(root);
    return 0;
}
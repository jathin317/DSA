#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next=nullptr;
};
void insertAtBegginning(int value, node **head,node **tail)
{
    node *newnode = new node();
    newnode->data = value;
    *head->next=
}
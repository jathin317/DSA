#include <iostream>
/*I should do leftist tree posted in google classroom also in this week*/
using namespace std;

struct Node
{
    int key;
    int degree;
    Node *parent;
    Node *child;
    Node *sibling;

    Node(int key)
    {
        this->key = key;
        this->degree = 0;
        this->parent = nullptr;
        this->child = nullptr;
        this->sibling = nullptr;
    }
};

Node *mergeTrees(Node *T1, Node *T2)
{
    if (T1->key > T2->key)
    {
        swap(T1, T2);
    }
    T2->parent = T1;
    T2->sibling = T1->child;
    T1->child = T2;
    T1->degree += 1;
    return T1;
}

Node *mergeTreeLists(Node *H1, Node *H2)
{
    if (H1 == NULL)
        return H2;
    if (H2 == NULL)
        return H1;
    if (H1->degree < H2->degree)
    {
        H1->sibling = mergeTreeLists(H1->sibling, H2);
        return H1;
    }
    else
    {
        H2->sibling = mergeTreeLists(H1, H2->sibling);
        return H2;
    }
}

Node *mergeHeaps(Node *H1, Node *H2)
{
    if (H1 != NULL)
    {
    }
}

// Sample Output:
// After merging two binomial heaps:
// Binomial Heap:
// B0
// Root: 10
// B1
// Root: 5
// Children: 15
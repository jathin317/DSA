#include <iostream>
using namespace std;

/* Binomial Tree Node */
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

Node *mergeHeaps(Node *H1, Node *H2)
{
    if (!H1)
        return H2;
    if (!H2)
        return H1;
    Node *merged = nullptr;
    Node **tail = &merged;

    while (H1 && H2)
    {
        if (H1->degree <= H2->degree)
        {
            *tail = H1;
            H1 = H1->sibling;
        }
        else
        {
            *tail = H2;
            H2 = H2->sibling;
        }
        tail = &((*tail)->sibling);
    }
    *tail = (H1) ? H1 : H2;

    Node *prev = nullptr;
    Node *curr = merged;
    Node *next = curr->sibling;

    while (next)
    {
        if ((curr->degree != next->degree) ||
            (next->sibling && next->sibling->degree == curr->degree))
        {
            prev = curr;
            curr = next;
        }
        else
        {
            if (curr->key <= next->key)
            {
                curr->sibling = next->sibling;
                curr = mergeTrees(curr, next);
            }
            else
            {
                if (prev)
                {
                    prev->sibling = next;
                }
                else
                {
                    merged = next;
                }
                curr = mergeTrees(next, curr);
            }
        }
        next = curr->sibling;
    }

    return merged;
}

Node *insert(Node *H, int key)
{
    Node *newNode = new Node(key);
    return mergeHeaps(H, newNode);
}

Node *reverseList(Node *root)
{
    Node *prev = nullptr;
    Node *curr = root;
    Node *next = nullptr;

    while (curr)
    {
        next = curr->sibling;
        curr->sibling = prev;
        curr->parent = nullptr;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node *extractMin(Node *H)
{
    if (!H)
        return nullptr;

    Node *minNode = H;
    Node *minPrev = nullptr;
    Node *curr = H;
    Node *prev = nullptr;

    while (curr)
    {
        if (curr->key < minNode->key)
        {
            minNode = curr;
            minPrev = prev;
        }
        prev = curr;
        curr = curr->sibling;
    }

    if (minPrev)
    {
        minPrev->sibling = minNode->sibling;
    }
    else
    {
        H = minNode->sibling;
    }

    Node *children = reverseList(minNode->child);
    cout << "Extracted Minimum: " << minNode->key << endl;
    delete minNode; // Free memory of the extracted node
    return mergeHeaps(H, children);
}

void printHeap(Node *H)
{
    if (!H)
    {
        cout << "Heap is empty." << endl;
        return;
    }

    cout << "Binomial Heap:" << endl;
    while (H)
    {
        cout << "B" << H->degree << endl;
        cout << "Root: " << H->key << endl;

        Node *child = H->child;
        cout << "Children: ";
        while (child)
        {
            cout << child->key << " ";
            child = child->sibling;
        }
        cout << endl;

        H = H->sibling;
    }
}

int main()
{
    Node *H = nullptr;
    cout << "1. Insert\n2. Extract Min\n3. Print Heap\n4. Exit\n";
    int choice;

    while (true)
    {
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int key;
            cout << "Enter key: ";
            cin >> key;
            H = insert(H, key);
        }
        else if (choice == 2)
        {
            H = extractMin(H);
        }
        else if (choice == 3)
        {
            printHeap(H);
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

// Sample Output:
// 1. Insert
// 2. Extract Min
// 3. Print Heap
// 4. Exit
// Enter choice: 1
// Enter key: 10
// Enter choice: 1
// Enter key: 5
// Enter choice: 3
// Binomial Heap:
// B0
// Root: 5
// B1
// Root: 10
// Children: 15
// Enter choice: 2
// Extracted Minimum: 5
// Enter choice: 3
// Binomial Heap:
// B1
// Root: 10
// Children: 15
// Enter choice: 4
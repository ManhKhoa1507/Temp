#include <iostream>
using namespace std;

const int arraySize = 1000;

struct Node
{
    int data;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

void EnqueueArray(int &n, int a[])
{
    // Insert the element into the end of array
    if (n == arraySize)
    {
        cout << "Danh sach da day";
    }

    else
    {
        int x;
        cout << "\nnhap vao phan tu : ";
        cin >> x;

        a[n] = x;
        n++;
    }
}

void DeleteElement(int &n, int a[])
{
    // Delete element in the head
    for (int i = 0; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
}

int DequeueArray(int &n, int a[])
{
    // Get the head element and Delete it
    int result = -1;
    if (n != 0)
    {
        int result = a[0];
        return result;
    }
    return -1;
}

void DeleteAllArray(int &n, int a[])
{
    // Delete all elements in the array
    while (n != 0)
    {
        DeleteElement(n, a);
    }
}

void GetArray(int a[])
{
    // Create the first element
    int n = 0;
    int index = 0;

    while (true)
    {
        // Get the queue List

        int menu;
        cout << "\nEnqueue(1) Dequeue(2) IsEmpty(3) Count(4) DeleteAll(5) Exit(6)";
        cin >> menu;

        if (menu == 1)
        {
            EnqueueArray(n, a);
        }

        else if (menu == 2)
        {
            int top = DequeueArray(n, a);

            if (top == -1)
            {
                cout << "\nDanh sach rong\n";
            }
            else
            {
                cout << "\n"
                     << top << "\n";
                DeleteElement(n, a);
            }
        }

        else if (menu == 3)
        {
            if (n == 0)
                cout << "Rong";
            else
                cout << "Khong rong";
        }

        else if (menu == 4)
        {
            cout << "\nSo luong: " << n << endl;
        }

        else if (menu == 5)
        {
            DeleteAllArray(n, a);
        }
        else
        {
            break;
        }
    }
}

void CreateList(List &L)
{
    // Create the List
    L.pHead = NULL;
    L.pTail = NULL;
}

Node *CreateNode(int x)
{
    // Create Node
    Node *P = new Node;

    P->data = x;
    P->pNext = NULL;

    return P;
}

bool IsEmptyList(List L)
{
    // Check if list if empty or not
    // Return 0 : not empty
    // Return 1 : empty
    if (L.pHead == NULL)
        return 1;
    else
        return 0;
}

void AddTailList(List &L, Node *P)
{
    // Add Node in the tail
    if (IsEmptyList(L) == 1)
    {
        L.pHead = L.pTail = P;
    }
    else
    {
        L.pTail->pNext = P;
        L.pTail = P;
    }
}

void EnqueueList(List &L, Node *P)
{
    // Add node to the queue list
    AddTailList(L, P);
}

int DequeueList(List &L)
{
    // Get the head node
    // Update the L.pHead
    int result = -1;

    if (IsEmptyList(L) == 0)
    {
        int result = L.pHead->data;
        L.pHead = L.pHead->pNext;
    }
    return result;
}

void DeleteAllList(List &L)
{
    // Delete all node in queue
    Node *P = L.pHead;
    while (P != NULL)
    {
        DequeueList(L);
        P = P->pNext;
    }
}

int CountQueueList(List L)
{
    // Count number of node in queue
    int count = 0;
    Node *P = L.pHead;
    while (P != NULL)
    {
        count++;
        P = P->pNext;
    }
    return count;
}

void GetList(List &queue)
{
    while (true)
    {
        // Get the queue List
        int menu;
        cout << "\nEnqueue(1) Dequeue(2) IsEmpty(3) Count(4) DeleteAll(5) Exit(6)";
        cin >> menu;

        if (menu == 1)
        {
            int n;

            cout << "\nNhap vao phan tu : ";
            cin >> n;

            Node *P = CreateNode(n);
            EnqueueList(queue, P);
        }

        else if (menu == 2)
        {
            int top = DequeueList(queue);

            if (top != -1)
            {
                cout << "\n"
                     << top << "\n";
            }

            else
            {
                cout << "Danh sach rong";
            }
        }

        else if (menu == 3)
        {
            if (IsEmptyList(queue) == 1)
                cout << "\nRong";
            else
                cout << "\nKhong rong";
        }

        else if (menu == 4)
        {
            int count = CountQueueList(queue);
            cout << "\nSo luong: " << count << endl;
        }

        else if (menu == 5)
        {
            DeleteAllList(queue);
        }
        else
        {
            break;
        }
    }
}

void CreateMenu(List &queueList, int queueArray[])
{
    int n;
    cout << "Nhap menu: ";
    cout << "\nmang(1) danh sach lien ket(2) Exit(3): ";
    cin >> n;

    if (n == 1)
    {
        GetArray(queueArray);
    }

    else if (n == 2)
    {
        GetList(queueList);
    }
}

int main()
{
    int queueArray[arraySize];
    List queueList;

    CreateList(queueList);
    CreateMenu(queueList, queueArray);
}
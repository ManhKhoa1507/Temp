#include <iostream>
using namespace std;

const int arraySize = 1000;

struct Node
{
    int tu;
    int mau;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

void PushArray(int &n, int a[])
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
    // Delete element in the end 

    for (int i = n - 1; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
}

int PopArray(int &n, int a[])
{
    // Get the end element and Delete it
    int result = -1;
    if (n != 0)
    {
        int result = a[n - 1];
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
        // Get the stack List

        int menu;
        cout << "\nPush(1) Pop(2) IsEmpty(3) Count(4) DeleteAll(5) Exit(6)";
        cin >> menu;

        if (menu == 1)
        {
            PushArray(n, a);
        }

        else if (menu == 2)
        {
            int top = PopArray(n, a);

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

Node *CreateNode(int tu, int mau)
{
    // Create Node
    Node *P = new Node;

    P->tu = tu;
    P->mau = mau;
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

void AddHeadList(List &L, Node *P)
{
    // Add Node in the tail
    if (IsEmptyList(L) == 1)
    {
        L.pHead = L.pTail = P;
    }
    else
    {
        P->pNext = L.pHead;
        L.pHead = P;
    }
}

void PushList(List &L, Node *P)
{
    // Add node to the stack list
    AddHeadList(L, P);
}

void PopList(List &L)
{
    // Get the head node
    // Update the L.pHead
    int result = -1;

    if (IsEmptyList(L) == 0)
    {
        cout << L.pHead->tu<<"/"<<L.pHead->mau<<"\n";
        L.pHead = L.pHead->pNext;
    }
    else
    {
        cout << "Danh sach rong";
    }
}

void DeleteAllList(List &L)
{
    // Delete all node in stack
    Node *P = L.pHead;
    while (P != NULL)
    {
        PopList(L);
        P = P->pNext;
    }
}

int CountStackList(List L)
{
    // Count number of node in stack
    int count = 0;
    Node *P = L.pHead;
    while (P != NULL)
    {
        count++;
        P = P->pNext;
    }
    return count;
}

void GetList(List &stack)
{
    CreateList(stack);
    while (true)
    {
        // Get the stack List
        int menu;
        cout << "\nPush(1) Pop(2) IsEmpty(3) Count(4) DeleteAll(5) Exit(6)";
        cin >> menu;

        if (menu == 1)
        {
            int tu, mau;

            cout << "\nNhap vao tu : ";
            cin >> tu;
            cout<<"\nNhap vao mau: ";
            cin >> mau;

            Node *P = CreateNode(tu, mau);
            PushList(stack, P);
        }

        else if (menu == 2)
        {
            PopList(stack);
        }

        else if (menu == 3)
        {
            if (IsEmptyList(stack) == 1)
                cout << "\nRong";
            else
                cout << "\nKhong rong";
        }

        else if (menu == 4)
        {
            int count = CountStackList(stack);
            cout << "\nSo luong: " << count << endl;
        }

        else if (menu == 5)
        {
            DeleteAllList(stack);
        }
        else
        {
            break;
        }
    }
}

void CreateMenu(List &stackList, int stackArray[])
{
    int n;
    cout << "Nhap menu: ";
    cout << "\nmang(1) danh sach lien ket(2) Exit(3): ";
    cin >> n;

    if (n == 1)
    {
        GetArray(stackArray);
    }

    else if (n == 2)
    {
        GetList(stackList);
    }
}

int main()
{
    int stackArray[arraySize];
    List stackList;

    CreateMenu(stackList, stackArray);
}
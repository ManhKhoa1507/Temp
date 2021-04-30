#include <iostream>
using namespace std;

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

void CreateList(List &L)
{
    // Tao 1 list
    L.pHead = NULL;
    L.pTail = NULL;
}

bool IsEmpty(List L)
{
    // Kiem tra danh sach co rong hay khong
    if (L.pHead == NULL)
        return 1;
    else
        return 0;
}

Node *CreateNode(int x)
{
    // Tao 1 node
    Node *P = new Node;

    P->data = x;
    P->pNext = NULL;

    return P;
}

void AddHead(List &L, Node *P)
{
    // Them vao dau danh sach
    if (IsEmpty(L) == 1)
    {
        L.pHead = L.pTail = P;
    }
    else
    {
        P->pNext = L.pHead;
        L.pHead = P;
    }
}

void Push(List &L, int x)
{
    // Chuyen doi x sang node va them vao dau danh sach
    Node *P = CreateNode(x);
    AddHead(L, P);
}

int Pop(List &L)
{
    // Lay gia tri o node Head va thay doi node Head
    int result;
    if (IsEmpty(L) == 0)
    {
        result = L.pHead->data;
        L.pHead = L.pHead->pNext;
    }
    return result;
}

string GetResult(List &L)
{
    // Lay ket qua vua chuyen doi
    string result = "";
    while (IsEmpty(L) == 0)
    {
        result += to_string(Pop(L));
    }
    return result;
}

string ConvertToBin(int n)
{
    // Chuyen doi sang he nhi phan
    int re = 0;
    int temp = n;

    List stack;
    CreateList(stack);

    while (temp != 0)
    {
        int re = temp % 2;
        Push(stack, re);
        temp = temp / 2;
    }
    string result = GetResult(stack);
    return result;
}

void GetInput(int &n)
{
    // Ham nhap vao so he 10
    cout << "Nhap n: ";
    cin >> n;
}

void PrintResult(string result)
{
    // Ham xuat ket qua sau khi chuyen sang he nhi phan
    cout << "Result: " << result;
}

int main()
{
    string Binary = "";
    int n = 0;

    GetInput(n);
    Binary = ConvertToBin(n);
    PrintResult(Binary);

    return 0;
}
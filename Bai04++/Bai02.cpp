#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Node
{
    string name;
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

Node *CreateNode(int x, string name)
{
    // Tao 1 node
    Node *P = new Node;

    P->data = x;
    P->name = name;
    P->pNext = NULL;

    return P;
}

void AddTail(List &L, Node *P)
{
    // Them vao cuoi danh sach
    if (IsEmpty(L) == 1)
    {
        L.pHead = L.pTail = P;
    }
    else
    {
        L.pTail->pNext = P;
        L.pTail = P;
    }
}

int Dequeue(List &L)
{
    // Lay gia tri cua node Head va xoa node Head
    int result = L.pHead->data;
    L.pHead = L.pHead->pNext;
    return result;
}

void TaoChoNgoi(List &A)
{
    // Tao so luong cho ngoi va them vao List A 
    int n;
    cout << "\nNhap vao so luong cho ngoi : ";
    cin >> n;

    for (int i = 0; i < n ; i++)
    {
        Node *P = CreateNode(i, "");
        AddTail(A, P);
    }
}

void KhoiTaoQueue(List &A, List &B, List &C)
{
    // Khoi tao List 
    CreateList(A);
    CreateList(B);
    CreateList(C);
}

void XepHang(List &B)
{
    // Them node vao B
    Node *P = new Node;

    // Neu node rong thi so thu tu la 1
    if (IsEmpty(B) == 1)
    {
        P->data = 1;
    }

    // Nguoc lai la so thu tu tiep theo 
    else
    {
        P->data = B.pTail->data + 1;
    }

    AddTail(B, P);
}

void LayTenKhach(List &A, List &C)
{
    // Lay thong tin khach hang xoa ghe ngoi o list A va them vao C
    string name;
    cout << "\nTen: ";
    cin >> name;

    // Lay so ghe o list A
    int soGhe = Dequeue(A);
    Node *P = CreateNode(soGhe, name);

    // Them node do vao C
    AddTail(C, P);
}

void MuaVe(List &A, List &B, List &C)
{
    // Mua ve xem phim
    // Neu co khach hang va con ghe 
    if (IsEmpty(B) == 0 && IsEmpty(A) == 0)
    {
        Dequeue(B);
        LayTenKhach(A, C);
    }

    // Neu khong con ghe
    else if (IsEmpty(A) == 1)
    {
        cout << "\n Khong co cho ngoi";
    }

    // Neu khong co khach
    else if (IsEmpty(B) == 1)
    {
        cout << "\n Khong co khach";
    }
}

void HuyVe(List &A, List &C)
{
    // Huy ve 
    
    // Lay so ghe hien tai o list C add vao list A
    int soGhe = Dequeue(C);
    Node *P = CreateNode(soGhe, "");

    AddTail(A, P);
}

void HienThiThongTin(List C)
{
    // Hien thi thong tin o list C
    Node *P = C.pHead;

    while (P != NULL)
    {
        cout << "\nTen: " << P->name;
        cout << "\nSo ghe: " << P->data;

        P = P->pNext;
    }
}

void TaoMenu(List &A, List &B, List &C)
{
    while (true)
    {
        int menu;
        cout << "\nLay so (1) Mua ve (2) Huy ve (3) Hien thi(4) Thoat(5): ";
        cin >> menu;

        if (menu == 1)
        {
            XepHang(B);
        }
        else if (menu == 2)
        {
            MuaVe(A, B, C);
        }
        else if (menu == 3)
        {
            HuyVe(A, C);
        }
        else if (menu == 4)
        {
            HienThiThongTin(C);
        }
        else
        {
            break;
        }
    }
}

int main()
{
    List A, B, C;

    KhoiTaoQueue(A, B, C);
    TaoChoNgoi(A);
    TaoMenu(A, B, C);

    return 0;
}
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <queue>
using namespace std;

bool visited[1001];
int forward_point[1001];

bool kiemtraFiletontai(ifstream& fi) 
{
    bool cotontai = true;
    bool khongtontai = fi.fail();
    if (khongtontai == true) 
	{
        cotontai = false;
    }
    return cotontai;
}

void docfile(ifstream& fi, int** a, int n)
{
    int x, i;
    while (!fi.eof())
    {
        fi >> i;
        while (true)
        {
            fi >> x;
            if (x > 0)
                a[i][x] = 1;
            if (fi.eof())
                break;
            char c;
            fi.get(c);
            char ch[2] = { c };
            if (strcmp(ch, " ") != 0)
            {
                break;
            }
        }
    }
}

void xuatmatranke(int** a, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) 
		{
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void init(int** a, int n) 
{
    for (int i = 0; i <= n; i++) 
	{
        visited[i] = false;
        forward_point[i] = 0;
    }
}

bool kiemtradothi(int** a, int n)
{
    for (int i = 1; i <= n; i++) 
	{
        for (int j = 1; j <= n; j++) 
		{
            if (a[i][j] != a[j][i]) 
			{
                return true; // Do thi co huong
            }
        }
    }
    return false; // Do thi vo huong
}

void BFS(int** a, int u, int n)
{
    //cout << "BFS(" << u << "): ";
    queue<int> Q;
    Q.push(u);
    visited[u] = true;
    while (!Q.empty())
    {
        int s = Q.front();
        //cout << s << " ";
        Q.pop();
        for (int t = 1; t <= n; t++)
        {
            if (visited[t] == false && a[s][t] == 1)
            {
                Q.push(t);
                visited[t] = true;
                forward_point[t] = s;
            }
        }
    }
}


void DFS(int** a, int u, int n)
{
    stack<int> st;
    st.push(u);
    visited[u] = true;
    while (!st.empty())
    {
        int s = st.top();
        st.pop();
        for (int t = 1; t <= n; t++)
        {
            if (visited[t] == false && a[s][t] == 1)
            {
                forward_point[t] = s;
                visited[t] = true;
                st.push(s);
                st.push(t);
                break;
            }
        }
    }
}

void PrintPath(int s, int e)
{
    if (forward_point[e] == 0)
        cout << "Khong co duong di tu dinh " << s << " den dinh " << e << endl;
    else
    {
        cout << "Duong di: ";
        cout << e;
        int u = forward_point[e];
        while (u != s)
        {
            cout << " <- " << u;
            u = forward_point[u];
        }
        cout << " <- " << s;
    }
}

void menu1(int** a, int n) 
{

    int start, end;
    init(a, n);
    cout << "Nhap dinh bat dau: ";
    cin >> start;
    cout << "Nhap dinh ket thuc: ";
    cin >> end;
    DFS(a, start, n); // van de nam o cho forward_point luon bang 0; da giai quyet
    /*for (int i = 0; i <= n; i++) 
	{
        cout << forward_point[i];
    }*/
    PrintPath(start, end);
}

void menu2(int** a, int n) 
{

    int start, end;
    init(a, n);
    cout << "Nhap dinh bat dau: ";
    cin >> start;
    cout << "Nhap dinh ket thuc: ";
    cin >> end;
    BFS(a, start, n); // van de nam o cho forward_point luon bang 0; da giai quyet
    /*for (int i = 0; i <= n; i++) 
	{
        cout << forward_point[i];
    }*/
    PrintPath(start, end);
}

void Menu() 
{
    cout << "==============TIM DUONG DI GIUA CAC DINH=============\n";
    cout << "1. Tim duong di bang BFS\n";
    cout << "2. Tim duong di bang DFS\n";
    cout << "3. Thoat!!!\n";
    cout << "=====================================";
}

int ChonMenu()
{
    int n = 0;
    cout << "\n\nMoi chon menu: ";
    cin >> n;
    if (n > 0 || n <= 3)
        return n;
    else return ChonMenu();
}

void XuLyMenu(int** a, int n)
{
    int chon = ChonMenu();
    switch (chon)
    {
    case 1:
        cout << "1. Tim duong di bang BFS\n";
        menu1(a, n);
        break;
    case 2:
        cout << "2. Tim duong di bang DFS\n";
        menu2(a, n);
        break;
    case 3:
        cout << "Thoat!!!\n";
        exit(1);
        break;
    }
}

int main()
{
    ifstream fi("TH03_input.txt");
    kiemtraFiletontai(fi);
    if (kiemtraFiletontai(fi) == true) 
	{
        cout << "File ton tai\n";
    }
    else 
	{
        cout << "Loi. File khong ton tai!\n";
    }

    int n = 0;
    fi >> n;
    string s;
    getline(fi, s);

    int** a = new int* [n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = new int[n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = 0;

    docfile(fi, a, n);
    cout << "Xuat ma tran ke cua do thi la: " << endl;
    xuatmatranke(a, n);

    //thucthi(a);
    fi.close();
    if (kiemtradothi(a, n) == false) 
	{
        cout << "Ket luan: Do thi vo huong\n";
    }
    else 
	{
        cout << "Ket luan: Do thi co huong\n";
    }


    Menu();
    while (true)
    {
        XuLyMenu(a, n);
    }

    for (int i = 1; i <= n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}


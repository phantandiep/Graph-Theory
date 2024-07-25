#include<iostream>
#include<conio.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX  1000
using namespace std;

//ma tran trong so
int a[100][100];
//so dinh
int n;
// so canh
int m;
//so canh cua cay khung cuc tieu
int edge;
//do dai cay khung cuc tieu
int w;
//mang danh dau danh sach dinh da them vao
int chuaxet[100];
//danh sach canh cay khung nho nhat
int mst[100][3];


void docFile(void) 
{
    int i, j, k;
#pragma warning (disable : 4996)
    freopen("TH07_input.txt", "r", stdin);
    cin >> n >> m;
    cout << "So dinh cua do thi: " << n << endl;
    cout << "So canh cua do thi: " << m << endl;

    // khoi tao ma tran trong so do thi a[i][j] = MAX
    for (i = 1; i <= n; i++) 
	{
        chuaxet[i] = 1;
        for (j = 1; j <= n; j++)
            a[i][j] = MAX;
    }

    //doc danh sach canh
    for (int p = 1; p <= m; p++) 
	{
        cin >> i >> j >> k;
        a[i][j] = k;
        a[j][i] = k;
    }
}

void Prim(void) 
{
    int k, top, min, l, t, u;
    // mang chua cac dinh cua cay khung nho nhat
    int s[100];
    edge = 0; w = 0; u = 1;
    top = 1;
    // them dinh u bat ky vao mang s[]
    s[top] = u;
    chuaxet[u] = 0;
    while (edge < n - 1) 
	{
        min = MAX;
        // tim canh co do dai nho nhat voi cac dinh trong mang s[]
        for (int i = 1; i <= top; i++) 
		{
            t = s[i];
            for (int j = 1; j <= n; j++) 
			{
                if (chuaxet[j] && min > a[t][j]) 
				{
                    min = a[t][j];
                    k = t;
                    l = j;
                }
            }
        }
        edge++;
        w = w + min;
        // them vao danh sach canh cua cay khung
        mst[edge][1] = k;
        mst[edge][2] = l;
        chuaxet[l] = 0;
        top++;
        s[top] = l;
    }
}

void Result(void) 
{
    cout << "Do dai ngan nhat:" << w << endl;
    cout << "Cac canh cua cay khung nho nhat" << endl;
    for (int i = 1; i <= edge; i++)
        cout << mst[i][1] << " " << mst[i][2] << endl;
}

int main(void) 
{
    cout << "---- TH07_Thuat toan Prim\n";
    docFile();
    Prim();
    Result();
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>

#define fi "TH06_input.txt"
//#define fo "KRUSKAL.OUT"

const int MAXN = 10000;
const int MAXM = 1000;
/// #define MAXN 10000

using namespace std;

struct edge 
{
    // Dinh dau
    int u;
    // Dinh cuoi
    int v;
    // Do dai
    int w;
};

int n, m;
edge a[MAXM];
int parent[MAXN];
fstream f;

void docFile() 
{
    f.open(fi, ios::in);
    f >> n >> m;
    int i, j;
    for (i = 1; i <= m; i++)
        f >> a[i].u >> a[i].v >> a[i].w;
    f.close();
}

void SapXep() 
{
    edge tmp;
    int i, j;
    for (i = 1; i <= m - 1; i++)
        for (j = i + 1; j <= m; j++)
            if (a[i].w > a[j].w) 
			{
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
}

int root(int x) 
{
    if (parent[x] == -1)
        return x;
    else
        return root(parent[x]);
}

void unify(int r1, int r2) 
{ /// r1 khac r2
    if (r1 < r2)
        parent[r2] = r1;
    else /// r1 > r2
        parent[r1] = r2;
}

void Kruskal() 
{
    SapXep();
    int i;
    for (i = 1; i <= n; i++)
        parent[i] = -1;
    int dem = 0;
    int tong = 0;
    int x, y;
    int r1, r2;
    //f.open(fo, ios::out);
    for (i = 1; i <= m; i++) 
	{
        if (dem == n - 1) break;
        x = a[i].u;
        y = a[i].v;

        r1 = root(x);
        r2 = root(y);

        if (r1 != r2) 
		{
            cout << x << "   " << y << endl; /// end line
            dem++;
            tong = tong + a[i].w;
            unify(r1, r2);
        }
    }
    cout << "===> Gia tri cua cay khung be nhat la: " << tong;

}


int main() 
{
    cout << "----TH06_Thuat toan Kruskal\n";
    docFile();
    Kruskal();
    return 0;
}

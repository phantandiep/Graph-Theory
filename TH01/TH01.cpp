#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

bool kiemtraFiletontai(ifstream& fi) 
{
    bool cotontai = true;
    bool khongtontai = fi.fail();
    if (khongtontai == true) {
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
            if ( strcmp(ch, " ") != 0)
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
            cout << a[i][j] << " ";
        cout << endl;
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
                return false;
            }
        }
    }
    return true;
}

void demsobac(int** a, int n) 
{
    if (kiemtradothi(a, n)) 
	{
        cout << "Ket luan: Do thi vo huong\n";
        int sobac = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == 1) 
				{
                    sobac++;
                }
            }
            cout << "Dinh " << i << " co " << sobac << " bac" << endl;
        }
    }
    else 
	{
        cout << "Ket luan: Do thi co huong\n";

        for (int i = 1; i <= n; i++)
        {
            int bacra = 0, bacvao = 0;
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == 1)
                    bacra++;
                if (a[j][i] == 1)
                    bacvao++;
            }
            cout << "Dinh " << i << " co " << bacvao << "bac vao va " << bacra << "bac ra\n";
        }
    }
}

int main()
{
    cout << "BT1: Bieu dien do thi\n";
    ifstream fi("TH01_input.txt");
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
        for (int j = 1; j <= n; j++) a[i][j] = 0;

    docfile(fi, a, n);
    cout << "Xuat ma tran ke cua do thi la: " << endl;
    xuatmatranke(a, n);
    fi.close();
    demsobac(a, n);

    for (int i = 1; i <= n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

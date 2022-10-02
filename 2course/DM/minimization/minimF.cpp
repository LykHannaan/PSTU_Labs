#include <iostream>
#include <vector>
#include <windows.h>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

string tr[16] = { "0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111" };
string trr[16] = { "!x!y!w!z","!x!y!wz","!x!yw!z",
                  "!x!ywz","!xy!w!z","!xy!wz","!xyw!z",
	              "!xywz","x!y!w!z","x!y!wz","x!yw!z",
	              "x!ywz","xy!w!z","xy!wz","xyw!z","xywz" };

void printsdnf(vector <string> s)
{
	cout << endl;
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
		if (i != s.size() - 1)cout << " U ";
	}
	cout << endl;
}
vector <vector <string>> sort(vector <string> sdnf)
{
	vector <vector <string>> sc;
	for (int i = 0; i < 5; i++)
	{
		vector <string> s;
		sc.push_back(s);
	}
	for (int i = 0; i < sdnf.size(); i++)
	{
		int d = 0;
		for (int j = 0; j < sdnf[i].size(); j++)
		{
			if (sdnf[i][j] == '1')
			{
				d++;
			}
		}
		sc[d].push_back(sdnf[i]);
	}
	return sc;
}
void check(vector <string>& scdnf1, vector <vector <string>>& scdnf, int u, int j, int k, bool& flag)
{
	int pos, e = 0, z = 0;
	for (int i = 0; i < scdnf[u][j].size(); i++)
	{
		if (scdnf[u][j][i] == scdnf[u + 1][k][i])
			z++;
		if ((scdnf[u][j][i] == '0' && scdnf[u + 1][k][i] == '1')
			|| (scdnf[u][j][i] == '1' && scdnf[u + 1][k][i] == '0'))
		{
			e++;
			pos = i;
		}
	}
	if (e == 1 && z >= 3)
	{
		if (scdnf[u][j].back() != '*')
			scdnf[u][j].push_back('*');
		if (scdnf[u + 1][k].back() != '*')
			scdnf[u + 1][k].push_back('*');
		string a = scdnf[u][j];
		a[pos] = '-';
		scdnf1.push_back(a);
		flag = 1;
	}
}
void check2(vector <string>& sc1, vector <vector <string>>& sc)
{
	for (int i = 0; i < sc.size() - 1; i++)
	{
		for (int j = 0; j < sc[i].size(); j++)
		{
			if (sc[i][j].back() != '*')
			{
				sc1.push_back(sc[i][j]);
			}
		}
	}
}
vector <string> rep(vector <string> a)
{
	set<string> s;
	for (int i = 0; i < a.size(); i++)
	{
		s.insert(a[i]);
	}
	a.clear();
	for (auto it = s.begin(); it != s.end(); ++it)
		a.push_back(*it);
	return a;
}
bool imp(string a, string b)
{
	int g = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if ((a[i] == b[i]) || (b[i] == '-'))
		{
			g++;
		}
	}
	if (g == 4)
		return 1;
	else
		return 0;
}

set <int> search_matr(vector <vector <bool>> matrix)
{
	vector <bool> fl;
	set <int> f2;
	for (int i = 0; i < matrix[1].size(); i++)
	{
		fl.push_back(0);
	}
	for (int i = 0; i < matrix[1].size(); i++)
	{
		int k = 0, pos;
		for (int j = 0; j < matrix.size(); j++)
		{
			if (matrix[j][i] == 1)
			{
				k++;
				pos = j;
			}
		}
		if (k == 1)
		{
			f2.insert(pos);
			for (int s = 0; s < matrix[pos].size(); s++)
			{
				if (matrix[pos][s] == 1)
					fl[s] = 1;
			}
		}
	}
	cout << endl;
	vector<int>x;
	for (int i = 0; i < fl.size(); i++)
	{
		if (fl[i] == 0)
		{
			x.push_back(i);
		}
	}
	if (!x.empty())
	{
		bool flag = 0;
		int y = x[0], i = 0;
		x.erase(x.begin());
		while (!flag && (i < matrix.size()))
		{
			if (matrix[i][y] == 1)
			{
				int q = 0;
				for (int j = 0; j < x.size(); j++)
				{
					if (matrix[i][x[j]] == 1)
					{
						q++;
					}
					if (q == x.size())
					{
						flag = 1;
						f2.insert(i);
					}
				}
			}
			i++;
		}
	}
	return f2;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool x = 0, y = 0, w = 0, z = 0;
	unsigned int n = 16, num;
	vector<unsigned int> F;
	unordered_set<int> mem;
	cout << "Введите вектор логической функции (по окончанию ввода, нажмите q):  ";
	while (cin >> num){
		if ((num != 0) && (num != 1))
			cout << "Недопустимое значение! Введите другое :  ";
		else
		 F.push_back(num);
    }

    cout << endl;
    cout << "  x  " << " y  " << " w  " << " z  " << "      F ";
    cout << "\n";
    cout << "-----------------------------------------------\n";
    for (int i = 0; i < F.size(); i++) {
        n--;
        cout << "| " << x << " | " << y << " | " << w << " | " << z << " | -> | " << F[i];
        cout << " |\n";
        {
            if (n > 8) x = 0;
            else x = 1;
        }
        {
            if (n > 12 || (n < 9 && n > 4)) y = 0;
            else y = 1;
        }
        {
            if (n > 14 || (n < 13 && n > 10) || (n < 9 && n > 6) || (n < 5 && n > 2)) w = 0;
            else w = 1;
        }
        {
            if (n % 2 == 0) z = 0;
            else z = 1;
        }
       
    }
    cout << "-----------------------------------------------\n";
    system("pause");
	cout << endl;

	vector <string> sdnf;
	vector <string> print_sdnf;
	for (int i = 0; i < F.size(); i++)
	{
		if (F[i] == 1)
		{
			sdnf.push_back(tr[i]);
			print_sdnf.push_back(trr[i]);
		}
	}
	cout << "СДНФ: ";
	printsdnf(print_sdnf);
	vector <vector <string>> scdnf, scdnf2;
	vector <string> scdnf1;
	scdnf = sort(sdnf);
	bool flag = 1;
	while (flag)
	{
		flag = 0;
		for (int i = 0; i < scdnf.size() - 1; i++)
		{
			for (int j = 0; j < scdnf[i].size(); j++)
			{
				for (int k = 0; k < scdnf[i + 1].size(); k++)
				{
					check(scdnf1, scdnf, i, j, k, flag);
				}
			}
		}
		if (flag)
		{
			check2(scdnf1, scdnf);
			for (int i = 0; i < scdnf1.size(); i++)
			{
				if (scdnf1[i].back() == '*')
					scdnf1[i].pop_back();
			}
			scdnf.clear();
			scdnf = sort(rep(scdnf1));
			scdnf1.clear();
		}
	}
	for (int i = 0; i < scdnf.size() - 1; i++)
	{
		for (int j = 0; j < scdnf[i].size(); j++)
		{
			scdnf1.push_back(scdnf[i][j]);
		}
	}
	scdnf.clear();
	cout << endl;
	cout << "Сокращенная ДНФ: " ;
	printsdnf(scdnf1);
	vector <vector <bool>> matrix;
	for (int i = 0; i < scdnf1.size(); i++)
	{
		vector <bool> a;
		for (int j = 0; j < sdnf.size(); j++)
		{
			a.push_back(imp(sdnf[j], scdnf1[i]));
		}
		matrix.push_back(a);
	}
	cout << endl;
	cout << "Импликантная матрица: " << endl;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	set<int> f = search_matr(matrix);
	cout << "Минимальная ДНФ: ";
	for (auto i = f.begin(); i != f.end(); i++)
	{
		cout << scdnf1[*i];
		if (*i != *f.rbegin())cout << " U ";
	}
	cout << endl;




    return 0;
}

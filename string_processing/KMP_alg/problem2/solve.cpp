#include <iostream>
#include <vector>
#include <string>


using namespace std;

typedef long long LL;
typedef vector<int> vi;

#define F first
#define S second
#define endl "\n"
#define PB push_back
#define LOOP(i, start, end) for (int i = start; i < end; i++)
template <typename T>
void readInput(T &container, int start, int end)
{
    for(int i = start; i < end; i++){cin >> container[i];}
}

#define READ(T, s, e) readInput(T,s, e)

template <typename T>
void printInput(T &container, int start, int end)
{
    for(int i = start; i < end; i++){cout << container[i] << " ";} cout << endl;
}

#define PRINT(T, s, e) printInput(T,s, e)



vi creaPatern(string &std)
{
    int j = 0;
    vi pa(std.size());
    LOOP(i, 1, std.size())
    {
        while (j > 0 && std[j] != std[i])
        {
            j = pa[j - 1];
        }
        if (std[j] == std[i])
            j++;
        pa[i] = j;
    }
    return (pa);
}



int main()
{
    int test;
    while (cin >> test)
    {

        int flag = 0;
        string s , p;  cin >> p >> s;
        vi pa = creaPatern(p);
        vi ans ;
        for (int j = 0, i = 0; i < s.size(); )
        {
            if (p[j] == s[i])
            {
                i++;
                j++;
            }
            if (j == p.size())
            {
                cout << i - j << endl;
                j = pa[j - 1];
                flag = 1;
            }
            else if (i < s.size() && p[j] != s[i])
            {
                if (j != 0)
                    j = pa[j - 1];
                else 
                    i++;
            }
        }
            if (flag == 0)
                cout << endl;
    }
    
}
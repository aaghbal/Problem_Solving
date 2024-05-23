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
    for (int i = 1; i < std.size(); i++)
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
    int test; cin >> test;
    while (test--)
    {
    string s , p;  cin >> s >> p;
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
                ans.push_back(i - j + 1);
                j = pa[j - 1];
            }
            else if (i < s.size() && p[j] != s[i])
            {
                if (j != 0)
                    j = pa[j - 1];
                else 
                    i++;
            }
        }
        if (ans.empty())
            cout << "Not Found";
        else
        {
            cout << ans.size() << endl;
            for(auto c : ans)
            {
                cout << c << " ";
            }
        }
        cout << endl;
    }
    
}

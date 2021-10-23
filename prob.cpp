#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector < int > v;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int nr_sf;
int snflk;
int cazuri;
int cur_pack;
int max_pack;
int s_st, s_dr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>cazuri;

    while(cazuri--)
    {
        cin>>nr_sf;
        set < int > s;

        for(int i = 0; i < nr_sf; i++)
            {
                cin>>snflk;
                v.push_back(snflk);
            }
        cur_pack = v.size();
        max_pack = 0;
        s_st = 0;
        s_dr = 0;

        while(s_st <= s_dr && s_dr < cur_pack)
        {
            if(!s.count(v[s_dr]))
            {
                s.insert(v[s_dr++]);
            }
            else
            {
                max_pack = max(max_pack, s_dr - s_st);
                s.erase(v[s_st]);
                s_st++;
            }
            if(s_dr == cur_pack)
            {
                max_pack = max(max_pack, s_dr - s_st);
            }
        }

    cout<<max_pack<<"\n";

    }

    return 0;
}
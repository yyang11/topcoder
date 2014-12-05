#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <set>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <queue>
#include <complex>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define SZ(x) (x).size()

class AllCycleLengths {
public:
string findAll(vector<string> edges) {
    int i,j,k,p,t;
    int n=edges.size();
    int now[30];
    int next[30];
    char vstr[1000];
    //now.size()????????????????

    rep(i,n) now[i]=1<<i;
    rep(i,1000)
    {
        rep(j,n) next[j]=0;
        rep(j,n) rep(k,n) if(edges[j][k]=='Y') next[k]|=now[j];
        rep(j,n) now[j]=next[j];
        vstr[i]=0;
        rep(j,n) if(now[i]&(1<<i)) {vstr[i]=1; break;}
    }

    int rep;
    rep(rep,500) rep(p, sizeof(vstr)-rep)
    {
        int pos;
        for(pos=sizeof(vstr)-rep-1;pos>p&&vstr[pos+rep]==vstr[pos];pos--);
        if(pos==p)
        {
            string ret;
            rep(i,p+rep)
            {
                if(i==p) ret+="(";
                ret+=vstr[i];
            }
            return ret;
        }
    }
    return "";
}
};

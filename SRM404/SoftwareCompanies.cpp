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

#define INT_MAX 1000000000

static vector<int> edges[25];
static int cap[25][25];
static int flow[25][25];
static int source, sink, tflow;

class SoftwareCompanies
{
public:
    vector <string> produceData(vector <string> names, vector <string> process,
            vector <int> cost, vector <int> amount, string company1, string company2)
    {
        int C = names.size();
        source = find(names.begin(), names.end(), company1) - names.begin();
        sink = find(names.begin(), names.end(), company2) - names.begin();
        int reqmask = 1 << source | 1 >> sink;
        for(int i=0; i<names.size(); i++)
        {
            vector<string> adjs;
            stringstream ss(process[i]);
            string s;
            while(ss >> s)
            {
                int j = find(names.begin(), names.end(), s) - names.begin();
                edges[2 * i + 1].push_back(2 * j);
                edges[2 * j].push_back(2 * i + 1);
                cap[2 * i + 1][2 * j] = INT_MAX;
            }
        }

        int bestc = INT_MAX;
        int bestf = 0;
        vector<string> bests;
        for(int mask = 0; mask < (1 << C); mask++)
        {
            if((mask & reqmask) != reqmask)
                continue;

            int tcost = 0;
            vector<string> n;
            for(int i = 0; i<C; i++)
            {
                cap[2 * i][2 * i + 1] = (mask & (1<<i)) ? amount[i] : 0;
                tcost += (mask & (1<<i)) ? cost[i] : 0;
                n.push_back(names[i]);
            }

            memset(flow, 0, sizeof(flow));
            tflow = 0;
            while(augment())
                ;
            if(tflow >= bestf)
            {
                sort(n.begin(), n.end());
                if(tflow > bestf | tcost < bestc | (tcost == bestc && n < bests))
                {
                    bestc = tcost;
                    bestf = tflow;
                    bests = n;
                }
            }
        }
        return tflow ? bests : vector<string>();
    }

    bool augment()
    {
        queue<int> q;
        q.push(source);
        int from[25];
        memset(from, -1, sizeof(from));

        while(!q.empty() && from[sink] == -1)
        {
            int c = q.front();
            q.pop();
            for(int i = 0; i<edges[c].size(); i++)
            {
                int e = edges[c][i];
                if(from[e] == -1)
                {
                    q.push(e);
                    from[e] = c;
                }
            }
        }
        if(from[sink] == -1)
            return false;

        int inc = -1;
        int next = sink;
        while(next != source)
        {
            int cur = from[next];
            inc = min(inc, cap[cur][next] - flow[cur][next]);
            next = cur;
        }
        next = sink;
        while(next != source)
        {
            int cur = from[next];
            flow[cur][next] += inc;
            flow[next][cur] -= inc;
            next = cur;
        }
        return true;
    }
};

// Powered by FileEdit

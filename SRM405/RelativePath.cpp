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

class RelativePath {
public:
    string makeRelative(string path, string currentDir) {
        string ret;
        int parent = 0;
        for( ; path[parent] == currentDir[parent]; parent++)
            ;
        vector<string> back;
        stringstream ss(currentDir.substr(parent));
        string s;
        while(getline(ss, s, '/'))
        {
            back.push_back(s);
        }
        //strtok(currentDir.substr(parent), "/", back);
        for(int i = 0; i < back.size(); i++)
        {
            ret = ret + "../";
        }
        ret = ret + currentDir.substr(parent);
        return ret;
    }
};


// Powered by FileEdit

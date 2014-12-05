#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class ParticleCollision {
	public:
    vector<double> collision(int vx, int vy, int vz, int x0, int y0, int z0)
    {
    	vector<double> ret;
        double eps = 1e-9;
        int a = vx * vx + vy * vy;
        int b = vx * x0 + vy * y0;
        int c = x0 * x0 + y0 * y0 - 1;
        int d = b * b - 4 * a * c;
        if (a == 0)
        {
           if (c == 0)
           {
               if (vz != 0)
               {
               		ret.push_back(0);
               		ret.push_back(0);
               		ret.push_back(0);
                    return ret;
               } else
               {
                   if (cos(M_PI * z0) - x0 < eps)
                   {
                   		ret.push_back(x0);
                   		ret.push_back(y0);
                   		ret.push_back(z0);
                        return ret;
                   } else
                   {
                        return ret;
                   }
               }
           } else {
               return ret;
           }
        }

        if(d < 0)
        {
            return ret;
        }
        double t1 = (-b + sqrt(d)) / (2 * a);
        double t2 = (-b - sqrt(d)) / (2 * a);
        double x1 = vx * t1 + x0;
        double y1 = vy * t1 + y0;
        double z1 = vz * t1 + z0;
        bool ok1 = cos(M_PI * z1) - x1 < eps;
        double x2 = vx * t2 + x0;
        double y2 = vy * t2 + y0;
        double z2 = vz * t2 + z0;
        bool ok2 = cos(M_PI * z2) - x2 < eps;

        if(ok1 && ok2 && d != 0) {
        	ret.push_back(0);
        	ret.push_back(0);
        	ret.push_back(0);
        	return ret;
        }
        if(ok1) {
        	ret.push_back(x1);
        	ret.push_back(y1);
        	ret.push_back(z1);
        	return ret;
        }
        if(ok2) {
  	    	ret.push_back(x2);
  	    	ret.push_back(y2);
  	    	ret.push_back(z2);
  	    	return ret;
        }
        return ret;
    }
};



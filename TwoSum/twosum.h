#include <vector>
using namespace std;

#ifndef TWOSUM_H
#define TWOSUM_H

namespace baseline{
    typedef struct num{
        int n;
        int idx;
    } num;

    class sortNum{
    public:
        bool operator()(num a, num b) const {
            if (a.n < b.n) return true;
            else return false;
        }
    };

    class twosum{
    public:
        twosum(){}
        vector<int> twoSum(vector<int>& nums, int target);
    private:

    };
}

namespace optimized{
    class twosum{
    public:
        twosum(){}
        vector<int> twoSum(vector<int>& nums, int target);
    private:

    }; 
}
#endif
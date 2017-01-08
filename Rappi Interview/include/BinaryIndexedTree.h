#ifndef BINARYINDEXEDTREE_H
#define BINARYINDEXEDTREE_H

#include<vector>
//Based on chapter 2.2.4 of Competitive Programming 3

class BinaryIndexedTree
{
    public:
        BinaryIndexedTree(int n);
        long long query(int x1, int y1, int z1, int x2, int y2, int z2);
        void update(int x, int y, int z, long long W);
        long long getValue(int x, int y, int z);
        long long query(int x, int y, int z);
    private:
        std::vector< std::vector< std::vector<long long> > > biTree;
};

#endif // BINARYINDEXEDTREE_H

#ifndef BINARYINDEXEDTREE_H
#define BINARYINDEXEDTREE_H

#include<vector>
//Based on chapter 2.2.4 of Competitive Programming 3

class BinaryIndexedTree
{
    public:
        BinaryIndexedTree(int n);
        int query(int x1, int y1, int z1, int x2, int y2, int z2);
        void update(int x, int y, int z, int W);
    private:
        std::vector<int> biTree;
        int query(int x, int y, int z);
};

#endif // BINARYINDEXEDTREE_H

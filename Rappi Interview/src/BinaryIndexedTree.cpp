#include "BinaryIndexedTree.h"
#include "utils.h"

BinaryIndexedTree::BinaryIndexedTree(int n){
    biTree.resize(n+1, std::vector<std::vector<long long> >(n+1, std::vector<long long>(n+1)));
}

long long BinaryIndexedTree::query(int x1, int y1, int z1, int x2, int y2, int z2){
    long long part1 = query(x2,y2,z2)- query(x1-1,y2,z2) - query(x2,y1-1,z2) + query(x1-1,y1-1,z2);

    long long part2 = query(x2,y2,z1-1) - query(x1-1,y2,z1-1) - query(x2,y1-1,z1-1)  + query(x1-1,y1-1,z1-1);

    return part1 - part2;
}
void BinaryIndexedTree::update(int x, int y, int z, long long W){
    for( ; z < (int)biTree.size(); z+= Utils::LSOne(z)) {
        for( int y1 = y; y1 < (int)biTree.size(); y1+= Utils::LSOne(y1)) {
            for( int x1 = x; x1 < (int)biTree.size(); x1+= Utils::LSOne(x1)) {
                biTree[x1][y1][z] += W;
            }
        }
    }
}

long long BinaryIndexedTree::query(int x, int y, int z){
    long long result = 0;
    for( ; z ; z-= Utils::LSOne(z)) {
        for( int y1 = y; y1 ; y1-= Utils::LSOne(y1)) {
            for( int x1 = x; x1 ; x1-= Utils::LSOne(x1)) {
                result+= biTree[x1][y1][z];
            }
        }
    }
    return result;
}

long long BinaryIndexedTree::getValue(int x, int y, int z){
    return biTree[x][y][z];
}

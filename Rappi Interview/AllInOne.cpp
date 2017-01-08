#include<iostream>
#include<vector>
using namespace std;

class Utils {
public:
    static int LSOne(int index){
		return (index & (-index));
	}

private:
    Utils(){}
    ~Utils(){}
};


class BinaryIndexedTree
{
    public:
        BinaryIndexedTree(int n){
			 biTree.resize(n+1, std::vector<std::vector<long long> >(n+1, std::vector<long long>(n+1)));
		}

        long long query(int x1, int y1, int z1, int x2, int y2, int z2){
    long long part1 = query(x2,y2,z2)- query(x1-1,y2,z2) - query(x2,y1-1,z2) + query(x1-1,y1-1,z2);

    long long part2 = query(x2,y2,z1-1) - query(x1-1,y2,z1-1) - query(x2,y1-1,z1-1)  + query(x1-1,y1-1,z1-1);

    return part1 - part2;
}
void update(int x, int y, int z, long long W){
    for( ; z < (int)biTree.size(); z+= Utils::LSOne(z)) {
        for( int y1 = y; y1 < (int)biTree.size(); y1+= Utils::LSOne(y1)) {
            for( int x1 = x; x1 < (int)biTree.size(); x1+= Utils::LSOne(x1)) {
                biTree[x1][y1][z] += W;
            }
        }
    }
}

long long query(int x, int y, int z){
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

long long getValue(int x, int y, int z){
    return biTree[x][y][z];
}

    private:
        std::vector< std::vector< std::vector<long long> > > biTree;
};

int main(){
    int T=0;
    cin>>T;
    while(T--){
        int N=0,M=0;
        cin>>N>>M;
        BinaryIndexedTree biTree(N);
        while(M--){
            string operationName = "";
            cin>>operationName;
            if(operationName == "QUERY"){
                int x1=0, y1=0, z1=0, x2=0, y2=0, z2=0;
                cin>> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                cout<<biTree.query(x1,y1,z1,x2,y2,z2)<<endl;
            }
            else if(operationName == "UPDATE"){
                int x=0,y=0,z=0;
                long long int W=0;
                cin>> x >> y >> z >> W;
                long long partialValue = biTree.query(x,y,z,x,y,z);
                biTree.update(x,y,z,W - partialValue);
            }
        }
    }
    return 0;
}


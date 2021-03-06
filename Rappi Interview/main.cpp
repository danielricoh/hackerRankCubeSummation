#include<iostream>
#include "BinaryIndexedTree.h"
using namespace std;

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

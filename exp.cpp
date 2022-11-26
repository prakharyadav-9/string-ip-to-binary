#include<iostream>
#include<bitset>
using namespace std;

#define OCTACT 8

int main(){

    int n,ipBin[8];
    cin>>n;
    bitset<OCTACT> bits = bitset<OCTACT>(n);
    // string s1 = bitset<OCTACT>(n).to_string();
    for(int i=0,idx =0;i< OCTACT;i++){
        ipBin[idx++] = bits[7-i];
    }

    // cout<<"\n equivlanent bin:: "<<s1;
    
    cout<<"\n equivlanent bin:: ";
    for(int i= 0; i<8; i++) { cout<< ipBin[i];};
    return 0;

}
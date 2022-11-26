#include <iostream>
#include <string>

using namespace std;


string ip, mask;
string ip_string[4];
int ip_int[4], length[4];
void dec();
void enter();
void get_ip();
void ip_bin();

int main(){

    enter();
    get_ip();
    cout <<endl;
    // dec();

return 0;}

void enter(){

    cout<<"Enter ip adress: ";
    cin>>ip;
}

void get_ip(){
//splitting to sections each number between the ip dots
    for(int i = 0; i<4; i++){

        ip_int[i] = stoi(ip.substr(0, '.'));
        cout<<ip_int[i]<<" ";
        string z = to_string(ip_int[i]);
        int ln = z.length();
        ip.erase(0, ln+1);
    }
}

void  dec() {
 int bin =0;
 int i=1;
 for(int  s=0; s<4; s++)
 {
    int fullBin[8]={0},j = sizeof(fullBin)/sizeof(fullBin[0]) -1;
    while(ip_int[s] >0 ){
        bin += (ip_int[s]%2)*i;
        ip_int[s] = ip_int[s]/2;
        i*=10;
    }
 cout <<bin<<endl;
 bin = 0;
 i=1;
 }
}
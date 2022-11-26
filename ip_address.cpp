
#include<iostream>
#include<bitset>
#include <bits/stdc++.h>
#include<conio.h>
#define DELIM "."
using namespace std;
#define OCTACT 8

bool valid_part(char* );
int is_valid_ip(char* );
void ip_to_binary(string ,int [][OCTACT]);

/*
    printing any type of 2D array
*/
template<typename T>
void print2D(T mat, int ROW, int COL) {
    for(int i=0 ; i<=ROW-1 ; i++) {
        for(int j=0 ; j<=COL-1 ; j++)
            cout<< *(*(mat+i)+j)<<"";
        cout<<" ";
    }
    cout<<endl;
}

/*
    COnverts a string to binary 
    @param (string) : ip_str,
    @param int : bit_ip[][COL]
*/
void ip_to_binary(string ip_str,int bit_ip[][OCTACT]){
    int bin_ip[4] = {0};
    // string ip_str(str_ip);
    for(int i = 0; i<4; i++){
            bin_ip[i] = stoi(ip_str.substr(0, '.'));
            bitset<OCTACT> bits = bitset<OCTACT>(bin_ip[i]);
            // cout<<bin_ip[i]<<" ";
            for(int j=0,idx =0;j< OCTACT;j++){
                int temp=bits[7-j];
                // cout<<"  "<<temp;
                (bit_ip)[i][idx++] = bits[7-j];
            }
            string z = to_string(bin_ip[i]);
            int ln = z.length();
            ip_str.erase(0, ln+1);
        }
    // return bit_ip;
}


bool valid_part(char* s)
{
    int n = strlen(s);
     
    // if length of passed string is
    // more than 3 then it is not valid
    if (n > 3)
        return false;
     
    // check if the string only contains digits
    // if not then return false
    for (int i = 0; i < n; i++)
        if ((s[i] >= '0' && s[i] <= '9') == false)
            return false;
    string str(s);
     
    // if the string is "00" or "001" or
    // "05" etc then it is not valid
    if (str.find('0') == 0 && n > 1)
        return false;
    stringstream geek(str);
    int x;
    geek >> x;
     
    // the string is valid if the number
    // generated is between 0 to 255
    return (x >= 0 && x <= 255);
}
 
/* return 1 if IP string is
valid, else return 0 */
int is_valid_ip(char* ip_str)
{
    // if empty string then return false
    if (ip_str == NULL)
        return 0;
    int i, num, dots = 0;
    int len = strlen(ip_str);
    int count = 0;
     
    // the number dots in the original
    // string should be 3
    // for it to be valid
    for (int i = 0; i < len; i++)
        if (ip_str[i] == '.')
            count++;
    if (count != 3)
        return false;
     
    // See following link for strtok()
   
    char *ptr = strtok(ip_str, DELIM);
    if (ptr == NULL)
        return 0;
 
    while (ptr) {
 
        /* after parsing string, it must be valid */
        if (valid_part(ptr))
        {
            /* parse remaining string */
            ptr = strtok(NULL, ".");
            if (ptr != NULL)
                ++dots;
        }
        else
            return 0;
    }
 
    /* valid IP string must contain 3 dots */
    // this is for the cases such as 1...1 where
    // originally the no. of dots is three but
    // after iteration of the string we find
    // it is not valid
    if (dots != 3)
        return 0;
    return 1;
}


int main(){
    int bin_ip[4],ip_bits[4][OCTACT];//={0,0,0,0};
    char ip1[16] = {'1','0','.','2','1','3','.','0','.','1'};
    
    for(int i=0;i< 4;i++){
            for(int j=0;j<OCTACT;j++){
                ip_bits[i][j]=0; 
            }
        }
    cout<<" \n ip -> "<<ip1<<endl;
    // is_valid_ip(ip1)? cout<<"Valid": cout<<"Invlid";
    // getch();
    while(1){
        cout<<"\nHello World\n enterIp :: ";
        cin>>ip1;
        // ip1={'1','0',};
        string ip_str(ip1);
        int isValid= is_valid_ip(ip1);
        // cout<<"\n "<<isValid<<endl<<strcmp("exit",ip1)<<endl;
       if (strcmp("exit",ip1) == 0){
            cout<<" thank you for using the application :)\n Bye.";
            exit(0);
        }
        else if(isValid != 1 ){
            cout<<"Please Enter a valid IP... \n ";
            //  exit(-1); 
           continue;
        } 
        ip_to_binary(ip_str, ip_bits);
        cout<<endl;
        print2D(ip_bits,4,8);
        // for(int i=0;i< 4;i++){
        //     for(int j=0;j<OCTACT;j++){
        //         cout<<ip_bits[i][j]<<""; 
        //     }
        //         cout<<"  ";
        // }

    }
    return 0;

}




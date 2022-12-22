#include <iostream>
#include <stdio.h>
#include <vector>
 
using namespace std;
 
int carry(vector <int> v, int n, int arg){
    if(n == 0)
        return v[0];
    else
        printf("a = %d end;\n", arg*carry(v, n-1, arg) + v[n]);
        return arg*carry(v, n-1, arg) + v[n];
}
 
int main(){
    int n, m, mod;
    cin >> n >> m >> mod;
    vector <int> v;
    vector <int> ansver;
 
    for(int i = 0; i <= n; ++i){
        int g;
        cin >> g;
        while(g >= mod)
            g -= mod;
        cout<<endl<<"*"<<g<<"*"<<endl;
        v.push_back(g);
    }
 
    for(int i = 0; i < m; ++i){
        int g;
        cin >> g;
        while(g >= mod)
            g -= mod;
 
        g = carry(v, n, g);
        cout<<endl<<"*"<<g<<"*"<<endl;
        while(g >= mod)
            g -= mod;
        //cout<<endl<<"*"<<g<<"*"<<endl;
        ansver.push_back(g);
    }
    cout << endl;
    for(long unsigned int i = 0; i < ansver.size(); ++i)
        cout << ansver[i] << endl;
 
 
    return 0;
 
}
 
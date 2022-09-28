#include<stdio.h>
#include<iostream>
#include<set>
#include<iterator>
#include<bits/stdc++.h>
#define C 5
using namespace std;
set <char> in[C], out[C];
void check_parallel(int m, int p){
    cout << "m " <<m <<"n"<< p<<endl;
    std::vector<char> intersect1, intersect2, intersect3;
    std::vector<char> common_data;
    set_intersection(in[p].begin(), in[p].end(), out[m].begin(), out[m].end(),std::back_inserter(common_data));

    set_intersection(in[m].begin(), in[m].end(), out[p].begin(), out[p].end(),std::back_inserter(intersect2));

    set_intersection(out[m].begin(), out[m].end(), out[p].begin(), out[p].end(),std::back_inserter(intersect3));
    cout <<"condition 1 for"<<m <<" "<< p<< "  "<<common_data.empty()<< endl;
    cout <<"condition 2 for"<<m << " "<< p<< "  "<<intersect2.empty()<< endl;
    cout <<"condition 3 for"<<m<< " " <<p<<"  "<< intersect3.empty()<< endl;
    
    if(common_data.empty()){
        if(intersect2.empty()){
            if(intersect3.empty()){
                cout<< "Parallel" << m+ 1<< " " << p +1<< endl;

            }
        }
    }

}

int main(){
    int n;
    cout<< "enter the number of instructions\n";
    cin>> n;
    string P[n] ;
    for(int i = 0; i < n; i++){
        cin >> P[i];
    }
    char ch;
    int fl = 0;
    for(int i = 0; i < n; i++){
        int k = P[i].length();
        fl = 0;
        for(int j= 0; j< k; j ++){
            if(P[i][j] == '='){
                    fl = 1;
            }
            if((P[i][j] >= 'A' && P[i][j] <= 'Z') || (P[i][j] >= 'a' && P[i][j] <= 'z')){
                ch = P[i][j];
                
                if(fl == 0){
                    in[i].insert(ch);
                }
                
                else if(fl > 0 ){
                    out[i].insert(ch);
                    
                }
            }
        }
    

    }
    for(int i = 0; i < n-1; i++){
        for(int j =i+1; j <n ; j++){
            cout<< "i = " << i<<"J = "<< j<<endl;
            check_parallel(i,j);
        }
    }

    //print in out
    for (int i = 0; i < n; i++) {
        cout << "Elements at index " << i << ": ";
  
        // Print the array of sets
        for (auto x : in[i])
            cout << "in " << x << " ";
  
        cout << endl;
        
    }
    for (int i = 0; i < n; i++) {
        for (auto x : out[i])
            cout <<"out "<< x << " ";
  
        cout << endl;
    }
    

}
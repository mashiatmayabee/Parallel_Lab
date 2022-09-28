#include<stdio.h>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int vector_to_dec(vector<int>& v){
    int cv=0;
    for(int i = 1; i < 8; i++){
        // cout << v[i];
        cv = cv + (v[i]*pow(2,i-1));
    }
    return cv;
}
vector<int> dec_to_vect(int n){
    int a[9];
    vector<int> new_vec(7,0);
    for(int i=0; n>0; i++)    
    {    
        new_vec[i]=n%2;    
        n= n/2;
        
    }  
    
    for(int i=6; i>=0; i--)    
    {    
        cout<< new_vec[i]<< " ";
    }
    return new_vec;
}
int main()
{
    int maximum = 0,l;
    int matrix[3][20] = {{1,0,0,0,0,1,0,1},
                        {0,1,0,1,0,0,0,0},
                        {0,0,1,0,1,0,1,0}};
    vector <int> forbidden(9,0);
    vector <int> permissive(9,0);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 8; j++){
            if(matrix[i][j]>0){
                for(int k = j+1 ; k < 8; k++){

                    if(matrix[i][k]==1){
                        //cout << k-j;
                        forbidden[k-j]++;
                    }
                }
            }
        }
    }
    cout<< "Forbidden Latencies : ";
    for(int i = 1; i < 9; i++){

        if(forbidden[i]>0){
            cout<< i << " ";
            if(i>maximum){
                maximum = i;
            }

        }
    }
    cout<< "\nPermissible Latencies : ";
    for(int i = 1; i < 9; i++){

        if(forbidden[i]==0){
            cout<< i << " ";

        }
    }
    vector <int>collision_vector(maximum, 0);

    for(int i = 1; i<=maximum; i++){
        if(forbidden[i]>0){
            //collision_vector[(forbidden[i])] = 1;
            collision_vector[i] = 1;
        }
    }
    cout << "\nColission Vector : ";
    for(int i = maximum; i>0 ; i--){
        cout << collision_vector[i] << " ";
    } //collission vector

    vector<int> m;
    int t;
    int cv = vector_to_dec(collision_vector);
    for(int i = 1; i < 8; i++){
    
        if(collision_vector[i] == 0){
            cout<<endl<<"step-1 for ";
            cout<< i;
            t = cv>>i;
            int ans = (cv|t);
            
            cout <<endl<< "for first vector "<< endl;
            m=dec_to_vect(ans);
        }
    }
    // int inr = cv>>
    cout << endl<<cv;
    return 0;

}

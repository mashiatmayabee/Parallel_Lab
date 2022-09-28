#include<stdio.h>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
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
    int temp,counter = 1;
    l = 0;
    int matrix2[3][20];
    while(1){
        cout << "\nEnter the latency\n";
        cin >> temp;
        l=l+temp;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 8+l; j++){
                if(matrix[i][j]==1){
                    matrix[i][j+temp] += temp+1; 
                    if(matrix[i][j+temp] != 1 && matrix[i][j+temp]!= temp+1){
                        matrix[i][j+temp] -= temp+1 ;
                        cout << i+1  << "  " << j +temp + 1 << endl;                    
                    }
                }
                
                    //cout<< matrix[i][j] << " ";
            }
            // cout << endl;
        }
        
    }
    

    return 0;

}

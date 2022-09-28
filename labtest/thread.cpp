#include<stdio.h>
#include<bits/stdc++.h>
#include<pthread.h>
int ar[20], sum[4], part;
using namespace std;

void* array_sum(void* arg){
    int thread_id = part++;
    for(int i = thread_id*4; i < (thread_id + 1) * (16/4); i++){
        sum[thread_id] += ar[i];
    }
}
int main(){
    pthread_t thread[4];
    int total = 0;
    for(int i = 0; i< 16; i++){
        ar[i] = i+1;
        cout << ar[i] << " ";
    }
    for(int i = 0; i< 4;i++){
        pthread_create(&thread[i], NULL, array_sum, (void*)NULL);
    }
    cout << endl;
    for(int i = 0; i< 4;i++){
        pthread_join(thread[i], NULL);
    }
    
    for(int i = 0; i< 4;i++){
        cout<< sum[i]<< " ";
        total+=sum[i];
    }

    cout << endl;
    printf("SUm = %d\n", total);
    return 0;
}
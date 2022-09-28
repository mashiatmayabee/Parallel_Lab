#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string myText;
    ifstream MyReadFile("input.txt");
    unordered_map <char, int> m;
    getline(MyReadFile, myText);
    sort(myText.begin(), myText.end());
    
    cout << myText;

    // Close the file
    MyReadFile.close();
}
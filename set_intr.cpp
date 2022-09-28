#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
#include <set>
using namespace std;

int main() {
  set<char> s1;
  set<char> s2;

  s1.insert('1');
  s1.insert('2');
  s1.insert('3');
  s1.insert('4');

  s2.insert('f');
  s2.insert('s');
  s2.insert('b');
  s2.insert('z');
    std::vector<char> common_data;
    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(), std::back_inserter(common_data));
    if(common_data.empty()){
        cout<< "jdf";
    }
    else{
      cout<< "not";
    }
  return 0;
}
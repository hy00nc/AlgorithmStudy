#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Person{
    string name;
    int age;
};

bool cmp(const Person &a, const Person &b){
    return a.age<b.age;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    Person a[n];
    for(int i=0;i<n;i++){
        cin>>a[i].age>>a[i].name;
    }
    stable_sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        cout<<a[i].age<<" "<<a[i].name<<'\n';
    }
}
//10814 나이순 정렬
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Person{
    int age;
    string name;
    int order;
};

bool cmp(const Person &a, const Person &b){
    if(a.age == b.age){
        return a.order < b.order;
    }else{
        return a.age < b.age;
    }
}

int main(){

    int n;
    cin >> n;
    vector<Person> p(n);
    for(int i=0; i<n; i++){
        cin >> p[i].age >> p[i].name;
        p[i].order  = i;
    }

    sort(p.begin(), p.end(), cmp);
    
    for(int i=0; i<n; i++){
        cout << p[i].age << ' ' << p[i].name << '\n';
    }


}
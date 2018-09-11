#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct Student{
    string name;
    int lang;
    int eng;
    int math;
};

bool cmp(const Student &u,const Student &v){
    if(u.lang>v.lang) return true;
    else if(u.lang<v.lang) return false;
    else{
        if(u.eng<v.eng) return true;
        else if(u.eng>v.eng) return false;
        else{
            if(u.math>v.math) return true;
            else if(u.math<v.math) return false;
            else{
                if(u.name<v.name) return true;
                else return false;
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    vector <Student> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].name>>a[i].lang>>a[i].eng>>a[i].math;
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<n;i++){
        cout<<a[i].name<<'\n';
    }

}
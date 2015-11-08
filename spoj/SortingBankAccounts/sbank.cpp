#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define account first
#define frequency second

using namespace std;

bool compare(string a, string b) {
    for(int i=0;i<31 ;i++) {
        if(a.at(i)>b.at(i))
            return false;
        else if (a.at(i)<b.at(i))
            return true;
    }
    return false;
}

bool isEqual(string a, string b) {
    for(int i=0;i<31;i++) {
        if(a.at(i)!=b.at(i))
            return false;
    }
    return true;
}
int main() {
    int nTest,n;
    vector<string> accList;
    vector<pair<string,int> > unqList;
    pair<string,int> temp;
    int unqIndex=0;
    string accn;
    cin>>nTest;
    for(int test=1;test<=nTest;test++) {
        accList.clear();
        unqList.clear();
        cin>>n;
        getline(cin,accn);
        for(int i=0;i<n;i++) {
            getline(cin,accn);
            accList.push_back(accn);
        }
        sort(accList.begin(),accList.end(),compare);
        unqIndex=0;
        temp.account=accList[0];
        temp.frequency=1;
        unqList.push_back(temp);
        for(int i=1;i<accList.size();i++) {
            if(isEqual(accList[i],unqList[unqIndex].account))
                unqList[unqIndex].frequency++;
            else {
                temp.account=accList[i];
                temp.frequency=1;
                unqList.push_back(temp);
                unqIndex++;
            }
        }
        for(int i=0;i<unqList.size();i++) {
            cout<<unqList[i].account<<" "<<unqList[i].frequency<<endl;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main(){

int n,m;

cout<<"Enter total no of processes: ";
cin>>n;

cout<<"Enter total no of resources: ";
cin>>m;

int allocated[n][m],maxneed[n][m],available[m];

for(int i=0;i<n;i++){
    cout << "Enter the allocated number of resources to Process "<<i+1<<": ";
    for(int j=0;j<m;j++){
        cin>>allocated[i][j];
    }
}
cout<<endl;
for (int i = 0; i < n; i++)
{
    cout << "Enter the maximum need of resources to Process "<<i+1<<": ";
    for (int j = 0; j < m; j++)
    {
        cin >>maxneed[i][j];
    }
}
cout<<endl;
cout<<"Enter the respective number number of available resources: ";
for(int i=0;i<m;i++){
    cin>>available[i];
}
cout<<endl;
int remainingneed[n][m];
for(int i=0;i<n;i++){
    cout << "The remaining need of respective no of resources to Process "<<i + 1 << " are: ";
    for (int j = 0; j < m; j++)
    {
        cout << maxneed[i][j] - allocated[i][j]<<" ";
        remainingneed[i][j] = maxneed[i][j] - allocated[i][j];
}
cout<<endl;
}

cout<<endl;
vector<int> p;
unordered_map<int,bool> mapp;
int c=0;

for(int i=0;i<n;i++)
    mapp[ i+1 ]=false;

while(p.size()!=n||(c!=n)){
    c++;
for(int i=0;i<n;i++){
    int count = 0;
    for(int j=0;j<m;j++){

        if(remainingneed[i][j]<=available[count]&&(mapp[i+1]==false)){
             count++;
             if(count==m){
                    p.push_back(i+1);
                    mapp[i+1]=true;
                    for(int k=0;k<m;k++)
                        available[k]+=allocated[i][k];
                    }
}
else
break;
    }
}
}

if(c!=n||p.size()!=n){
cout<<"There is no safe order of Prcocesses for this action !"<<endl;
}

if(p.size()==n){
    cout<<"The Safe order of Processes in which they repectively can be executed is: ";
    for(int i=0;i<p.size()-1;i++)
    cout<<"Process "<<p[i]<<" -> ";
    cout<<"Process "<<p[p.size()-1]<<" ";
}
return 0;
}



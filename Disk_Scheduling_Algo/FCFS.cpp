#include<bits/stdc++.h>
using namespace std;
int main(){
    
    vector<int> v = {176, 79, 34, 60, 92, 11, 41, 114};
    int ans = 0,hp = 50,total = 0;
    cout<<"Seek operations sequence : \n";
    for(auto i:v)
    {
        cout<<i<<endl; 
    }
    for(int i=v.size()-1;i>0;i--)
    { 
        ans = v[i] - v[i-1];
        if(ans<0)
        {
            ans = ans * (-1);
        }
        total += ans; 
    }
    ans = v[0] - hp;
    if(ans<0)
    {
        ans = ans * (-1);
    }
    total += ans; 
    cout<<"Total No of seek movement : "<<total;
    

return 0;
}
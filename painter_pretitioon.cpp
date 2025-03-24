#include<iostream>
#include<vector>

using namespace std;
bool ispa(vector<int>&a,int m,int n,int max){
    int painter=1,time=0;
    
    for(int i=0;i<a.size();i++){
        if(a[i]>max){
            return false;
        }
        if(a[i]+time<=max){
            time+=a[i];
        }
        else{
            painter++;
            time=a[i];
        }
    }
    return painter<=m?true:false;

}
int mintime(vector<int>&a,int m,int n){
    int end=0,st = 0;
    for(int i=0;i<n;i++){
        end+=a[i];
        st=max(st,a[i]);
    }
    int ans=-1;
    if(m>n){
        return ans;
    }
    while(st<=end){
        int mid=st+(end-st)/2;
        if(ispa(a,m,n,mid)){        //left side
            end=mid-1;
            ans=mid;
        }
        else{
            st=mid+1;               //right side
        }
    }
    return ans;

}

int main(){
    vector<int>a={40,30,10,20};
    int n=a.size(),m=2;

    cout<<mintime(a,m,n)<<endl;


    return 0;
}
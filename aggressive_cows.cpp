#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool ispa(vector<int>&a,int m,int n,int max){
    int cow=1,first=a[0];
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
        
        if(a[i]-first>=max){
            first=a[i];
            cow++;
        }
        
    }
    return cow>=m?true:false;

}
int mintime(vector<int>&a,int m,int n){
    int end=0,st = 1;
    for(int i=0;i<n;i++){
        
        end=max(end,a[i])-1;
    }
    int ans=-1;
    if(m>n){
        return ans;
    }
    while(st<=end){
        int mid=st+(end-st)/2;
        if(ispa(a,m,n,mid)){        //left side
            st=mid+1;
            ans=mid;
        }
        else{
            end=mid-1;               //right side
        }
    }
    return ans;

}

int main(){
    vector<int>a={1,2,8,4,9};
    int n=a.size(),m=3;

    cout<<mintime(a,m,n)<<endl;


    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int N,M;
vector<int> vec;
 
int binarySearch(int low, int high){
    
    int sum=0;
    int mid=(low+high)/2;
    while(high>=low){
        
        sum=0;
        for(int i=0;i<N;i++)
            sum+=(vec[i]>mid)? mid:vec[i];
        
        if(sum==M)
            return mid;
        
        if(sum>M)  high=mid-1;
        else    low=mid+1;
        
        mid=(low+high)/2;
    }
    
    //low=n일 때 mid와 high는 n-1
    return mid;
}
 
int main(){
    
    scanf("%d",&N);
    
    int high=0;
    vec=vector<int> (N,0);
    for(int i=0;i<N;i++){
        scanf("%d",&vec[i]);
        
        if(vec[i]>high)
            high=vec[i];
    }
    
    scanf("%d",&M);
    cout<<binarySearch(0,high)<<endl;
    
    return 0;
}
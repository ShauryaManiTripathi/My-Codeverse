// Given a set P = {p1, p2, . . . , pn} of n points in R
// 2
// , where pi = (xi

// , yi). Let sij
// denotes the slope of the line segment joining pi and pj and S = {sij | 1 ≤ i <
// j ≤ n}. Basically, S contains all the slopes. Thus, |S| = O(n
// 2
// ). The objective
// is to compute maximum slope in S in O(n log n) time, rather than the obvious
// O(n
// 2
// ) time. Devise an algorithm for the above mentioned objective. (Hint:
// 1. Use geometrical property, 2. the desired time complexity is another clue.)

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct pair{
    int x;int y;
}point;


int main(){
int n;
cin>>n;
point a[n];
for(int i=0;i<n;i++){
    cin>>a[i].x>>a[i].y;
}
sort(a,a+n,compare);
for(int i=0;i<n;i++){
    cout<<a[i].x<<" "<<a[i].y<<" , ";
}




}
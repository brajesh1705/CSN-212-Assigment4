#include<bits/stdc++.h>
using namespace std;
#define MP         make_pair
#define PB         push_back
#define LL         long long
#define MAX        1000005
#define mod        1000000007
#define debug(a)   cout<<a<<"\n"
#define rep(i,x,b) for(int i=x;i<b;i++)


const double eps=1e-9;
const double pi =acos(-1);

struct point{
  int x;
  int y;
};
point p[100005];

LL t1,t2,t3,t4,t5;
int orientation(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
  if(val==0)return val;
    return (val > 0)? 1:2; 
}
void gift_wrap(int n)
{
  if(n<3)return;
  vector <point> hull;
  set<pair<int,int> > s;
  int a=t2,b;
  do{
    hull.PB(p[a]);
    b=(a+1)%n;
    rep(i,0,n)
    {
      if(orientation(p[a],p[i],p[b])==2)
      {
        b=i;
      }
    }
    a=b;
   }while(a!=t2);
    cout<<"Convex-Hull in counterclock wise fashion:\n";
   rep(i,0,hull.size())
   {
          cout<<hull[i].x<<" "<< hull[i].y<<"\n";
     
   }
  

}
int main()
{
    
    t1=1000000007;
    int n;
    cout<<"Enter no. of points:\n";
    cin>>n;
    cout<<"Enter the points as Xi and Yi:\n";
    rep(i,0,n)
    {
        cin>>p[i].x>>p[i].y;
      
        if(p[i].x<t1)
        {
          t2=i;
          t1=p[i].x;
        }
       
    }
    gift_wrap(n);


}

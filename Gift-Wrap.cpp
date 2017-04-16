#include<bits/stdc++.h>
using namespace std;
#define MP         make_pair
#define PB         push_back
#define LL         long long
#define MAX        1000005
#define mod        1000000007
#define debug(a)   cout<<a<<"\n"
#define pred(a)    printf("%0.6lf",a);
#define rep(i,x,b) for(int i=x;i<b;i++)


struct point{
	int x;
	int y;

};
point p0;
point p[100005];
int n;


point nextToTop(stack<point> &S)
{
    point p = S.top();
    S.pop();
    point res = S.top();
    S.push(p);
    return res;
}
int dis(point p1, point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
int orientation(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
  if(val==0)return val;
    return (val > 0)? 1:2; 
}

int cmp(const void *p11, const void *p12){
	point *p1=(point *) p11;
	point *p2=(point *) p12;
	int x=orientation(p0,*p1,*p2);
	if(x==0)
	{
		 return (dis(p0, *p2) >= dis(p0, *p1))? -1 : 1;
	}
	 return (x== 2)? -1: 1;

}
void Graham_scan()
{
  
   int y_lowest = p[0].y, min = 0;
   rep(i,1,n)
   {
     int y = p[i].y;
 
     
     if ((y < y_lowest) || (y_lowest == y &&
         p[i].x < p[min].x))
        y_lowest = p[i].y, min = i;
   }
 
   swap(p[0], p[min]);
 
   // Sort n-1 points with respect to the first point in terms of polar orientation

   p0 = p[0];
   qsort(&p[1], n-1, sizeof(point), cmp);
 
   int m = 1; // Initialize size of modified array
  rep(i,1,n)
   {
       
       while (i<n-1 && orientation(p0, p[i], p[i+1])== 0)
          i++;
       p[m] = p[i];
       m++;  // Update size of modified array
   }
 
   
   
   if (m < 3) return; 
 

   stack<point> S;
   S.push(p[0]);
   S.push(p[1]);
   S.push(p[2]);
 
   
   for (int i = 3; i < m; i++)
   {
      
      while (orientation(nextToTop(S), S.top(), p[i]) != 2)
         S.pop();
      S.push(p[i]);
   }
 
   
   cout<<"The convex hull in counter-clockwise fashion: \n";
   while (!S.empty())
   {
       point p = S.top();
       cout << "(" << p.x << ", " << p.y <<")" <<"\n";
       S.pop();
   }
}

int main()
{
    
   
 
  	cout<<"Enter no. of points:\n";
  	cin>>n;
  	cout<<"Enter the points as Xi and Yi:\n";
  	rep(i,0,n)
  	cin>>p[i].x>>p[i].y;
  	Graham_scan();


}

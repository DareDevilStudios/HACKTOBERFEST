#include<bits/stdc++.h>
using namespace std;

class Inter()
{
public:
  int intersec(int a[],int n,int b[],int m)
  {
      set<int>s;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<n-1-i;j++)
          {
              if(a[i]==b[i])
              {
                  s.insert(a[i]);
                  break;
              }
                
          }
      }
      return s;

  }
};

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int n,m;
      cin>>n>>m;
      int ar[n],br[m];
      for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
    for(int i=0;i<m;i++)
        {
            cin>>br[i];
        }
    Inter obj;
    cout<<obj.intersec(ar,n,br,m)<<endl;
  }
}
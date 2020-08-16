#include <iostream>
using namespace std;
void print(int n,int **a)
{
        for(int i=n-1; i>=0; i--)
        {
                for(int j=0; j<n; j++)
                        cout<<a[j][i]<<" ";
                // cout<<endl;
        }
        cout<<endl;
        return ;

}
int main() {
        int t;
        cin>>t;
        while(t--)
        {
                int n;
                cin>>n;
                int **a=new int*[n];
                for(int i=0;i<n;i++)
                a[i]=new int[n];
                for(int i=0; i<n; i++)
                {
                        for(int j=0; j<n; j++)
                                cin>>a[i][j];
                }
                print(n,a);
        }
        return 0;
}

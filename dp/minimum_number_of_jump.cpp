#include<bits/stdc++.h>
using namespace std;
#define ln "\n" 
int main()
{
cout<<ln<<ln;
//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n;
cin >> n;

vector<int> v;
int x;
for(int i= 0;i<n;i++)
{
    cin >> x;
    v.push_back(x);
}


int i = 0;
int maxx = v[i];
int jumps = 0;
int index;
vector<int> jump;
jump.push_back(1);
while(i<n-1 && i<maxx){
    int temp = maxx;
    for (int j = i + 1; j <= maxx; j++)
    {
        // cout << "j=\t" << j << ln;
        if (j + v[j] > maxx)
        {
            index = j;
        }
}
if(index + v[index]>temp)
{maxx = index + v[index];
if(index>n-1)
            index = n - 1;
jump.push_back(index+1);
jumps++;}
i = temp;
}
cout<<"number of jumps\t"<<jumps<<ln;
cout << "jumping route ";
for(auto i : jump){
cout << i << "->";
}
cout << (maxx >= n - 1 ? "passed!" : "failed");

cout << ln;

cout<<ln<<ln<<ln;
 return 0;
}
// testcase
// 16 3 2 1 4 5 7 2 1 4 1 2 3 2 0 0 1
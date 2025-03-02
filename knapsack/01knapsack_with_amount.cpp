#include<bits/stdc++.h>
using namespace std;
#define ln "\n" 
class knap{
    public:
        int weight, profit;
        knap(int w,int p){
            weight = w;
            profit = p;
        }
};


int main()
{
cout<<ln<<ln;

// for(auto i : weigtt_profit){
//     cout << i.weight << " " << i.profit << ln;
// }
// cout << ln;

vector<knap> weigtt_profit = {knap(4,5),knap(3,2),knap(5,6) ,knap(2,8)};
int n=weigtt_profit.size();
int w;
cout << "ENTER THE SIZE OF THE  KNAPSACK\t";
cin >> w;
vector<int> vect(w+1, 0);
vector<vector<int>> v(n + 1, vect);

for (int i = 1; i <=n;i++){
    for (int j = 1; j <= w;j++){
        if (j- weigtt_profit[i-1].weight>=0)
            v[i][j] = max(v[i - 1][j], v[i - 1][j - weigtt_profit[i-1].weight] + weigtt_profit[i-1].profit);
            else
                v[i][j] = v[i - 1][j];
    }
}

    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << ln;
    }
cout << ln;



    cout << ln << ln << ln;
return 0;
}
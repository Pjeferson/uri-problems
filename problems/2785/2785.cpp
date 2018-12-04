#include <iostream>
#include <cstring>

using namespace std;

int memo[101][101][101];
int array[101][101];

int pyramid(int h,int l, int r){
    if(h == -1) return 0;
    if(memo[h][l][r] != -1) return memo[h][l][r];
    int result = array[h][r] - array[h][l-1];
    return memo[h][l][r] = result+min(pyramid(h-1,l+1,r),pyramid(h-1,l,r-1));
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    memset(memo,-1,sizeof memo);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
         cin >> array[i][j];
         if(j>0)  array[i][j]+=array[i][j-1];
        }
    }
    n = pyramid(n-1,0,n-1);
    cout << n<<endl;
    return 0;
}

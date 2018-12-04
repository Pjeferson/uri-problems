# Top-down example

```
// Searching for the best pyramid

int pyramid(int h,int l, int r){
    if(h == -1) return 0;
    if(memo[h][l][r] != -1) return memo[h][l][r];
    int result = array[h][r] - array[h][l-1];
    return memo[h][l][r] = result+min(pyramid(h-1,l+1,r),pyramid(h-1,l,r-1));
}
```
int setSetBit(int xx, int yy, int l, int r)
{
    // code here

    // Method 1. time - O(r-l)

    // for(int i=l-1; i<= r-1; i++) {
    //     if(y & (1 << i)) x = x | (1 << i);
    // }
    // return x;

    // Method 2. time - O(1)
    unsigned x = xx;
    unsigned y = yy;
    y = y >> (l - 1);
    y = y << (l - 1);
    y = y << (32 - r);
    y = y >> (32 - r);
    x = x | y;
    return x;
}
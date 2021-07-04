// Trailing zeroes in factorial
// https://practice.geeksforgeeks.org/problems/trailing-zeroes-in-factorial5134/1#

int trailingZeroes(int n)
{
    if (n < 0)
    return -1;

    int count = 0;

    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;
    
    return count;
}
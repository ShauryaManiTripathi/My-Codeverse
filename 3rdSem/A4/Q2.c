#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<ctype.h>

int HasMajority(int *a, int l, int r, int *count, int *val)
{
    if (l == r)
    {
        *count = 1;
        *val = a[l];
    }
    else
    {
        int count1, val1, count2, val2, mid = (l + r) / 2;
        HasMajority(a, l, mid, &count1, &val1);
        HasMajority(a, mid + 1, r, &count2, &val2);
        if (val1 == val2)
        {
            *count = count1 + count2;
            *val = val1;
        }
        else
        {
            int count1in2 = 0;
            for (int i = mid + 1; i <= r; i++)
            {
                if (a[i] == val1)
                    count1++;
            }
            int count2in1 = 0;
            for (int i = l; i <= mid; i++)
            {
                if (a[i] == val2)
                    count2++;
            }
            if (count1 > count2)
            {
                *count = count1;
                *val = val1;
            }
            else
            {
                *count = count2;
                *val = val2;
            }
        }
    }
    if (*count > (l + r) / 2 + 1)
        return 1;
    else
        return 0;
}

int main()
{
    int a[10] = {1, 1, 1, 1, 1, 3, 7, 8, 9, 0};
    // printf("%d\n", findpeak(a, 0, 9));
    int temp1 = 0, temp2 = 0;
    printf("%d %d %d\n", temp1,temp2,HasMajority(a, 0, 9, &temp1, &temp2));
}
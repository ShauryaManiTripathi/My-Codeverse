#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

int findpeak(int *a, int l, int r)
{
    if (l == r)
        return a[l];
    int mid = (l + r) / 2;
    if (a[mid] > a[mid + 1])
        return findpeak(a, l, mid);
    else
        return findpeak(a, mid + 1, r);
}

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
                    count1in2++;
            }
            int count2in1 = 0;
            for (int i = l; i <= mid; i++)
            {
                if (a[i] == val2)
                    count2in1++;
            }
            int newCount1 = count1 + count1in2;
            int newCount2 = count2 + count2in1;
            if (newCount1 > newCount2)
            {
                *count = newCount1;
                *val = val1;
            }
            else
            {
                *count = newCount2;
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
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    printf("%d\n", findpeak(a, 0, 9));
    int temp1 = 0, temp2 = 0;
    printf("%d\n", HasMajority(a, 0, 9, &temp1, &temp2));
}
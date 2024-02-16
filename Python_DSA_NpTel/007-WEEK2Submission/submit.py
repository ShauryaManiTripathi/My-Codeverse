def threesquares(x):
    is_it=True
    test=1
    while(test<x):
        if x%test==0 and (x//test)%8==7:
            is_it=False
        test*=4
    return is_it

def repfree(x):
    if len(x) == len((set)(x)):
        return True
    return False

def hillvalley(x):
    n = len(x)
    i = 0
    first=False
    second=False
    is_asc = False
    if x[0] < x[1]:
        is_asc = True

    while ((i < n-1) and ((x[i] < x[i+1]) == is_asc)):
        i += 1
        first=True
    while ((i < n-1) and ((x[i] > x[i+1]) == is_asc)):
        i += 1
        second=True

    return ((i == n-1) and first and second)
    return False


                


    
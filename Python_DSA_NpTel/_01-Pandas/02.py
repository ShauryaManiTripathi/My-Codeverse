
import numpy as np
import pandas as pd
def p(x):
    print((str)(x)+'\n-------------------------------------------------------------------')
dates = pd.date_range("20210101", periods=6)
p(dates)
df = pd.DataFrame(np.random.randn(6, 4), index=dates, columns=list("ABCD"))
p(df)
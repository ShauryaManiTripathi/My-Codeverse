
import numpy as numpy
import pandas as pd
def p(x):
    print((str)(x)+'\n-------------------------------------------------------------------')
mydataset = {
    'cars': ["BMW", "Volvo", "Ford"],
    'passings': [3, 7, 2]
}
pdseries = pd.Series([1,2,3,"hello",5,6,numpy.nan,8,9,10])
p(pdseries)
pdseriesWithIndex = pd.Series([1,2,3,"hello",5,6,numpy.nan,8,9,10], index=["A", "B", "C", "D", "E", "F", "G", "H", "I", "J"])
p(pdseriesWithIndex)
p(mydataset)
myvar = pd.DataFrame(mydataset)
p(myvar)
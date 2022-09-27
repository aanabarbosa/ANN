import numpy as np
import math 

def dif_div(x, y):
    Y = [yi for yi in y]
    coefs = [y[0]]
    for j in range(len(x)-1):
        for i in range(len(x)-1-j):
            number = Y[i+1]-Y[i]
            denom = x[i+1+j]-x[i]
            div = number/denom
            Y[i] = div
        coefs.append(Y[0])
    return coefs


def poly(t, x, coefs):
    val = 0
    for i in range(len(coefs)):
        prod = 1
        for j in range(i):
            prod *= (t-x[j])
        val += coefs[i]*prod
    return val


def build_func(x, coefs):
    def temp(t):
        return poly(t, x, coefs)
    return temp


if __name__ == '__main__':
    x =   [1.507, 1.751, 1.915, 2.277, 2.557, 2.787, 2.894, 3.209, 3.421, 3.748, 3.838, 4.208, 4.37, 4.664, 4.975]
    y = []

    def f(x):
        #return np.cos(np.sin(np.log(x**2)))
        return np.cos(x+math.sqrt(np.log(pow(x,2))))


    for i in x:
        y.append(f(i))

    coefs = dif_div(x, y)
    p = build_func(x, coefs)
    print(coefs)
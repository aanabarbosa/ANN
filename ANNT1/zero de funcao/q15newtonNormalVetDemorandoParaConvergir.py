#f(x)=x(x−1)(x−2)+0.42


from math import pow, sqrt, tanh
from mpmath import sech


def newton(f,df,x0,n):
    for _ in range(n):
        x0 -= f(x0) / df(x0)
        yield x0

def f(x):
    return x * (x - 1) * (x - 2) + 0.42

def df(x):
    return 3*x*x-6*x+2

x0 = 2.4355127

n = 200

resp = list(newton(f,df,x0,n))

interations =  [5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175, 180, 185, 190, 195]

for i in interations:
    print(resp[i-1], end=',')


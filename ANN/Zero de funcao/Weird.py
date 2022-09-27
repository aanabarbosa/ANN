from math import pow, sqrt, tanh
from mpmath import sech


def newton(f,df,x0,n):
    for _ in range(n):
        x0 -= f(x0) / df(x0)
        yield x0

def f(x):
    return sqrt(2*9.81*x)*tanh((((sqrt(2*9.81*x))/(2*4.22))*9.37)) - 7.11

def df(x):
    return  (3*sqrt(109)*tanh((2811*sqrt(109)*sqrt(x))/(1055*pow(2,(5/2)))))/(5*pow(2,(3/2))*sqrt(x))+(919197*sech((2811*sqrt(109)*sqrt(x))/(1055*pow(2,(5/2)))))/84400

x0 = 0.4 

n = 200

resp = list(newton(f,df,x0,n))

interations = [1, 3, 5, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175, 180, 185, 190, 195]

for i in interations:
    print(resp[i-1], end=',')


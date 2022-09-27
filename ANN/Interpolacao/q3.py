
from weakref import ProxyTypes
import numpy as np


def poly(x,y):
    n = len(x)-1
    A =[]
    B =[]
    for xi in x:
        row = [1]
        for j in range(1, n+1):
            row.append(xi ** j)
        A.append(row)
    return np.linalg.solve(A, y)

def func_poly(x, coeffs):
    first=coeffs[0]
    return first + sum([ai * x ** j for j, ai in enumerate(coeffs[1:], 1)])

if __name__ == '__main__':
    #exemplo 1

    x= [0.456, 0.823, 1.551, 1.927, 2.508, 3.11, 3.781, 4.273, 5.134, 5.654, 5.94, 6.662]
    y=[4.433, 4.711, 4.92, 4.813, 4.382, 3.709, 2.927, 2.486, 2.209, 2.346, 2.487, 2.89]

    coeffs = poly(x,y)
    #print(coeffs)

    for x in (coeffs):
        print("%.16f," %x)
    def p(x):
        return func_poly(x,coeffs)

#    print("%.16f" %p(4.879))
 #   print("%.16f" %p(5.113))
  #  print("%.16f" %p(5.202))




#visulaizar
#import matplotlib.pylab as plt

#plt.scatter(x,y)
#t = np.linspace(min(x),  max(x), 200)
#pt = [p(ti) for ti in t]

#função seno
# st=np.sin(t)
# plt.plot(t, pt)
# plt.plot(t, st)

#plt.plot(t, pt)
#plt.savefig('interp.png')
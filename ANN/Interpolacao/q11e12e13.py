def dif_div(x, y):
    num = len(x)
    Y = [yi for yi in y]
    coefs = [y[0]]
    for j in range(num -1):
        for i in range(num - 1 - j):
            numerador = Y[i + 1] - Y[i]
            denominador = x[i + 1 + j] - x[i]
            div = numerador / denominador
            Y[i] = div
        coefs.append(Y[0])
    return coefs

def poly(t, x, coefs):
    val = 0
    num = len(coefs)
    for i in range(num):
        prod = 1
        for j in range(i):
            prod *= (t - x[j])
        val += coefs[i] * prod
    return val

def build_func(x, coefs):
    def temp(t):
        return poly(t, x, coefs)
    return temp


if __name__ == '__main__':

    #ex
    x =  [0.304, 0.602, 1.329, 1.731, 1.973, 2.612, 3.046, 3.414, 3.901, 4.382, 5.01, 5.436, 5.703, 6.357, 6.677]
    y = [4.866, 4.52, 3.41, 2.89, 2.629, 2.138, 2.005, 2.037, 2.275, 2.676, 3.293, 3.662, 3.836, 3.997, 3.923]
    coefs = dif_div(x, y)

    #polinomio interpolador da lista de pontos
    p = build_func(x, coefs)

    print(coefs)

    #print(p(1), p(3), p(3), p(4))
   # print(f'{p(0.97244)}')


    #visu
    #import matplotlib.pyplot as plt
    #import numpy as np

    #t = np.linspace(min(x), max(x), 100)
    #pt = [p(ti) for ti in t]

    #plt.scatter(x, y)
    #plt.plot(t, pt)

    #plt.savefig('dif_div.png')
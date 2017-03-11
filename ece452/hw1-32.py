# lets get numpy
import numpy as np
from numpy import pi
from numpy.fft import fft
import matplotlib.pyplot as plt

N = 1000
dt = 0.1
tmin = 0
tmax = N*dt
t = np.arange( tmin , tmax , dt )

df = 1
fmin = - (N*df) / 2
fmax = (N*df) / 2
f = np.arange(fmin,fmax,df)

A = np.sqrt(2)
fc = 2/tmax

for M in range(2):
    Phi = np.random.random(t.size) * 2 * pi - pi
    w = np.random.normal(0,1,t.size)

    s = A * np.cos( 2*pi*fc*t + Phi) + w
    s = np.cos(2*pi*fc*t)

    plt.plot(t,s)
    plt.show()
    
    S = fft(s)

    plt.plot(f,S)
    plt.show()

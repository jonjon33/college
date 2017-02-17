import numpy as np
import matplotlib.pyplot as plt

NN = 100
dt = .01

t1 = np.array()
x1tim = np.zeros(NN)
x2tim = np.zeros(NN)
f = np.zeros(NN)

for n in range(0,NN):
    t1.append(n*dt)
    x1tim.append(0)
    x2tim.append(0)
    f.append(0)

A = np.array( [ [0,1] , [-2,-3] ] )
B = np.array( [ [0] , [1] ] )

x = np.array( [ [0] , [0] ] )

idx = 0
steps = 10
for n in range(0,steps):
    idx += 1
    x = x + dt*A*x + dt*B*f(idx)
    x1tim(idx)
    x2tim(idx)

plt.plot(t1,x1tim,'ro')
plt.title('Example Plot')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.show()

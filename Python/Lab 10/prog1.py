import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-3, 3, 400)
y = (2 ** x) * np.sin(10 * x)

plt.figure(figsize=(8, 5))
plt.plot(x, y, linestyle='-', linewidth=2, color='blue', label='Y(x) = 2^x * sin(10x)')


plt.xlabel('x')
plt.ylabel('Y(x)')

plt.title('Plot of Y(x) = 2^x * sin(10x)')
plt.legend()

plt.grid(True)
plt.show()
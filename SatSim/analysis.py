import matplotlib.pyplot as plt

with open("o.csv", "r") as file:
    lines = file.readlines()

t = []
x = []
y = []
z = []
for i, line in enumerate(lines):
    values = line.split(',')
    t.append(i)
    x.append(float(values[0]))
    y.append(float(values[1]))
    z.append(float(values[2]))

plt.plot(t, x, label='x')
plt.plot(t, y, label='y')
plt.plot(t, z, label='z')
plt.xlabel('Steps')
plt.ylabel('Component_magnitude')
plt.legend()
plt.show()
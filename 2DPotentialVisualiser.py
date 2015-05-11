import numpy
import matplotlib.pyplot as plt

display_list = []

with open('gridArray.txt') as data_file:
   for line in data_file:
      display_list.append(line.strip().split())
A = numpy.asarray(display_list)
A = A.astype(float)

A[0:]=A[::-1]
plt.imshow(A)
plt.colorbar()
plt.show()
    
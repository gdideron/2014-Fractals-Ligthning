def PotentialVisualiser(potential_list):
    import numpy
    import matplotlib.pyplot as plt
    A=numpy.array([potential_list])
    A[0:]=A[::-1]
    A.resize(numpy.sqrt(A.shape),numpy.sqrt(A.shape))
    plt.imshow(A)
    plt.colorbar()
    plt.show()
    
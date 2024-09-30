import numpy as np  

A = np.arange(16).reshape((4,4))
  
# Displaying the Matrix
print("Numpy Matrix is:")
print(A)

pos = (len(A)) // 2 - 1 if (len(A))  % 2 == 0 else (len(A)) // 2
pos2 = (len(A[0])) // 2 - 1 if (len(A[0]))  % 2 == 0 else (len(A[0])) // 2
print(pos)
print(pos2)
print(len(A)//2)
print(len(A[0])//2)
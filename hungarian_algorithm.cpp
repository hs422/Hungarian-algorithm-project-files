 import numpy as np
from scipy.optimize import linear_sum_assignment

# Define the cost matrix (example)
cost_matrix = np.array([
    [4, 2, 8],
    [2, 3, 7],
    [3, 1, 6]
])

# Solve the assignment problem
row_ind, col_ind = linear_sum_assignment(cost_matrix)

# Display results
print("Optimal Assignment:")
for i, j in zip(row_ind, col_ind):
    print(f"Agent {i} assigned to Task {j} with cost {cost_matrix[i][j]}")

print("Total Minimum Cost:", cost_matrix[row_ind, col_ind].sum())

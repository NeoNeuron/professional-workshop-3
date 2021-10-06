def neuron_B(activity_of_A, alpha=0.9):
  """Model activity of neuron B as neuron A activity + noise

  Args:
    activity_of_A (ndarray): An array of shape (T,) containing the neural activity of neuron A
    alpha (float): coupling strength between A and B

  Returns:
    ndarray: activity of neuron B
  """
  noise = np.random.randn(activity_of_A.shape[0])
  return alpha * activity_of_A + noise

np.random.seed(12)

# Randomly assigned (binary) activity of neuron A
A = np.random.randint(2, size=(100000,))


diff_in_means = neuron_B(A)[A==1].mean() - neuron_B(A)[A==0].mean()
print(diff_in_means)
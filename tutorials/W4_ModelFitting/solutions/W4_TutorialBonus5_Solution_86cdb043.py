def sigmoid(z):
  """Return the logistic transform of z."""
  return 1 / (1 + np.exp(-z))
plot_function(sigmoid, "\sigma", "z", (-10, 10))
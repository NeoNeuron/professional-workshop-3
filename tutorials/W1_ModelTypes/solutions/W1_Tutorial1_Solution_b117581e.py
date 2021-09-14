def compute_single_neuron_isis(spike_times, neuron_idx):
  """Compute a vector of ISIs for a single neuron given spike times.

  Args:
    spike_times (list of 1D arrays): Spike time dataset, with the first
      dimension corresponding to different neurons.
    neuron_idx (int): Index of the unit to compute ISIs for.

  Returns:
    isis (1D array): Duration of time between each spike from one neuron.
  """
  # Extract the spike times for the specified neuron
  single_neuron_spikes = spike_times[neuron_idx]

  # Compute the ISIs for this set of spikes
  # Hint: the function np.diff computes discrete differences along an array
  isis = np.diff(single_neuron_spikes)

  return isis

# Testing your function by ploting ISI histogram of 283-th neuron
# Also indicate the mean of ISI with a vertical line
# Hint: Use the funciton plt.hist and plt.axvline

single_neuron_isis = compute_single_neuron_isis(spike_times, neuron_idx=283)

plt.hist(single_neuron_isis, bins=50, histtype="stepfilled")
plt.axvline(single_neuron_isis.mean(), color="orange", label="Mean ISI")
plt.xlabel("ISI duration (s)")
plt.ylabel("Number of spikes")
plt.legend();
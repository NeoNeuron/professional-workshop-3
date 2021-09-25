# perform PCA
score, evectors, evals = pca(X)

# plot the eigenvalues
plot_eigenvalues(evals, limit=False)
plt.xlim([0, 100])  # limit x-axis up to 100 for zooming
def create_structure_array(x:np.ndarray, order:int)->np.ndarray:
    '''
    Prepare structure array for regression analysis.

    Args:
    x         : original time series
    order     : regression order

    Return:
    x_array   : structure array with shape (len(x)-order) by (order).

    '''
    N = len(x) - order
    x_array = np.zeros((N, order))

    for i in range(order):
        x_array[:, i] = x[-i-1-N:-i-1]

    return x_array


# Uncomment below to test create_structure_array
np.random.seed(10)
test_X = np.random.randn(10)
X_array = create_structure_array(test_X, 3)
print(X_array)
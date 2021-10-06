def GC(x, y, order):
    '''
    Granger Causality from y to x

    Args:
    x         : original time series (dest)
    y         : original time series (source)
    order     : regression order

    Return:
    GC_value  : residual vector

    '''

    res_auto = auto_reg(x, order)
    res_joint = joint_reg(x, y, order)
    GC_value = 2.*np.log(res_auto.std()/res_joint.std())

    return GC_value

# Uncomment to test our GC code with 2-node regression model
np.random.rand(10)
test_X = np.random.randn(100000)
test_Y = np.random.randn(100000)
test_Y[1:] += test_X[:-1]*0.5
print(f'GC Y->X: {GC(test_X, test_Y, 100):.3e}')
print(f'GC X->Y: {GC(test_Y, test_X, 100):.3e}')
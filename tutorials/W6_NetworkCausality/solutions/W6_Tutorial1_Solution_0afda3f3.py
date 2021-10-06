def auto_reg(x, order)->np.ndarray:
    '''
    Auto regression analysis of time series.

    Args:
    x         : original time series
    order     : regression order

    Return:
    res       : residual vector

    '''
    reg_array = create_structure_array(x, order)

    coef = np.linalg.lstsq(reg_array, x[order:], rcond=None)[0]
    res = x[order:] - reg_array @ coef

    return res

# Uncomment below to test auto_reg()
np.random.seed(10)
test_x = np.random.randn(10)
print(auto_reg(test_x, 3))
def joint_reg(x, y, order)->np.ndarray:
    '''
    Joint regression analysis of time series.

    Args:
    x         : original time series 1
    y         : original time series 2
    order     : regression order

    Return:
    res       : residual vector

    '''
    reg_array_x = create_structure_array(x, order)
    reg_array_y = create_structure_array(y, order)

    reg_array = np.hstack((reg_array_x, reg_array_y))
    coef = np.linalg.lstsq(reg_array, x[order:], rcond=None)[0]
    res = x[order:] - reg_array @ coef

    return res

# Uncomment below to test joint_reg()
np.random.seed(10)
test_x = np.random.randn(10)
test_y = np.random.randn(10)
print(joint_reg(test_x, test_y, 3))
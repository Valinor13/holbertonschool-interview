#!/usr/bin/python3
""" rotate_2d_matrix.py: Rotate a 2D matrix 90 degrees clockwise """


def rotate_2d_matrix(matrix):
    """
    rotate_2d_matrix - Edit matrix in place by rotating it 90 degrees clockwise
    Args:
      matrix: 2D list of integers
    Returns:
      none  # Edit the matrix in place
    """
    # Transpose the matrix
    for i in range(len(matrix)):
        for j in range(i, len(matrix)):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Reverse each row
    for row in matrix:
        row.reverse()

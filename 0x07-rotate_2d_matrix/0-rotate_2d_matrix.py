#!/usr/bin/python3
""" rotate_2d_matrix.py: Rotate a 2D matrix 90 degrees clockwise """


def rotate_2d_matrix(matrix):
    """
    rotate_2d_matrix - Using list comprehension,
      edit matrix in place by rotating it 90 degrees clockwise
    Args:
      matrix: 2D list of integers
    Returns:
      none  # Edit the matrix in place
    """
    # Transpose matrix
    matrix[:] = [list(i) for i in zip(*matrix)]
    # Reverse rows using list comprehension
    matrix[:] = [list(reversed(i)) for i in matrix]

#!/usr/bin/python3
"""A module for evaluting 2d arrays"""


def island_perimeter(grid):
    """
        A simple function that counts border tiles in a 0, 1 matrix
        and returns the perimeter of the island
        land is marked with 1, water is marked with 0
        there is guaranteed to be at least one island in the matrix
        the matrix borders are all water
        there will be no islands with water inside (lakes)
    """
    perimeter = 0
    for row in range(len(grid)):
        for col in range(len(grid[0])):
            if grid[row][col] == 1:
                if row == 0 or grid[row - 1][col] == 0:
                    perimeter += 1
                if row == len(grid) - 1 or grid[row + 1][col] == 0:
                    perimeter += 1
                if col == 0 or grid[row][col - 1] == 0:
                    perimeter += 1
                if col == len(grid[0]) - 1 or grid[row][col + 1] == 0:
                    perimeter += 1
    return perimeter

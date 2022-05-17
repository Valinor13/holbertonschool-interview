#!/usr/bin/python3
"""
  Given a set of consecutive integers starting from 1 up to and including n,
    Maria & Ben take turns choosing a prime number from the set and removing that number and its multiples from the set.
    The player that cannot make a move loses the game.
"""

def isWinner(x, nums):
  """
    isWinner - 
      Deterimne winner based on turns
      n and x will not be larger than 10000
    @x: number of rounds
    @nums: array of numbers n
    Return: Name of player who wins, or None if no one wins
  """

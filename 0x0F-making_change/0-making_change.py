#!/usr/bin/python3

# makeChange - a function that returns the minimum number of coins needed to
# make change for a given total. No limit to the number of each coin used.
# most efficient solution
# @coins: a list of coin denominations, each coin is a positive integer greater than 0
# @total: the amount of change to make
# return: the minimum number of coins needed to make change for the given total
#         or -1 if no solution exists
def makeChange(coins, total):
    # sort the coins in descending order
    coins.sort(reverse=True)
    # initialize the dp array
    dp = [0] * (total + 1)
    # set the dp array to all -1
    for i in range(total + 1):
        dp[i] = -1
    # set the dp array to 0 for all values in the coins list
    for coin in coins:
        dp[coin] = 0
    # set the dp array to 1 for all values in the coins list
    for coin in coins:
        for i in range(coin, total + 1):
            if dp[i - coin] != -1:
                if dp[i] == -1:
                    dp[i] = dp[i - coin] + 1
                else:
                    dp[i] = min(dp[i], dp[i - coin] + 1)
    return dp[total]

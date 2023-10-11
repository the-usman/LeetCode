# Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

# Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

# Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

# Return the minimum integer k such that she can eat all the bananas within h hours.


# Example 1:

# Input: piles = [3,6,7,11], h = 8
# Output: 4
# Example 2:

# Input: piles = [30,11,23,4,20], h = 5
# Output: 30
# Example 3:

# Input: piles = [30,11,23,4,20], h = 6
# Output: 23


from math import ceil

def can_eat(piles, mid, h) :
    timeTotal = 0
    for i in range(len(piles)) :
        timeTotal += ceil(piles[i] / mid)
    return timeTotal <= h

def main(piles, h) :
    left = min(piles)
    right = max(piles)
    result = 0
    while left <= right :
        mid = (left + right) // 2
        if can_eat(piles, mid, h ) : 
            result = mid
            right = mid - 1
        else :
            left = mid + 1
    return result



print(main([3,6,7,11], 8 ))




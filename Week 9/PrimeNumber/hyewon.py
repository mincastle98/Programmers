from itertools import combinations

def isPrime(n):
    cnt = 0
    if n > 1:
        for i in range(1, n + 1):
            if n % i == 0:
                cnt += 1
        if cnt == 2:
            return True
        else:
            return False
    else:
        return False

def solution(nums):
    answer = 0

    for i in list(combinations(nums, 3)):
        sum = 0
        for j in i:
            sum += j

        if isPrime(sum):
            answer += 1

    return answer
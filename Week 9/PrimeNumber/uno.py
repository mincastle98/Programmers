from itertools import combinations


def isPrime(num):
    flag = 1

    for i in range(2, num):
        if (num % i == 0):
            flag = 0
            break

    if (flag == 1):
        return True
    else:
        return False


def solution(nums):
    answer = 0
    comList = list(combinations(nums, 3))

    for item in comList:
        if (isPrime(sum(item))):
            answer += 1
    return answer


# 5C3 -> 5*4*3/3*2*1 * 1/2


print(solution([1, 2, 7, 6, 4]))

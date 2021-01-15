def solution(clothes):
    answer = 1
    dic = {}
    for cloth in clothes:
        if cloth[1] not in dic:
            dic[cloth[1]] = 1
        else:
            dic[cloth[1]] += 1

    for val in dic.values():
        answer *= (val + 1)
    answer -= 1

    return answer

print(solution([["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]]))

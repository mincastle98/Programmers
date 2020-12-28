import functools


def cmp(a, b):
    t1 = a + b
    t2 = b + a

    return (int(t1) > int(t2)) - (int(t1) < int(t2))


def solution(numbers):
    answer = ""
    temp = [str(x) for x in numbers]
    temp = sorted(temp, key=functools.cmp_to_key(cmp), reverse=True)

    for s in temp:
        answer += s

    return answer


print(solution([6, 10, 2]))

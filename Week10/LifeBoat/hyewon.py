from collections import deque
def solution(people, limit):
    answer = 0
    people.sort()
    people = deque(people)
    while len(people) != 0:
        if len(people) == 1:
            answer += 1
            break
        else:
            if people[0] + people.pop() <= limit:
                people.popleft()
        answer += 1

    return answer

print(solution([70, 50, 80, 50], 100))
print(solution([70, 80, 50], 100))
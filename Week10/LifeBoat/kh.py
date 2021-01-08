def solution(people, limit):
    answer = 0
    right=len(people) - 1
    left = 0
    people.sort(reverse=True)
    while left<right+1:
        if people[left]+people[right]<=limit:
            right-=1
        left+=1
        answer+=1

    return answer
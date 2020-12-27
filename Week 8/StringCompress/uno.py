def solution(s):
    length = []
    result = ""

    if len(s) == 1:
        return 1

    for cut in range(1, len(s) // 2 + 1):
        cnt = 1
        temp = s[:cut]
        for i in range(cut, len(s), cut):
            if s[i:i + cut] == temp:
                cnt += 1
            else:
                if cnt == 1:
                    cnt = ""
                result += str(cnt) + temp
                temp = s[i:i + cut]
                cnt = 1
        if cnt == 1:
            cnt = ""
        result += str(cnt) + temp
        length.append(len(result))
        result = ""

    return min(length)


print(solution("aabbaccc"))

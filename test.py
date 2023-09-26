# check prime num
def is_pr(n):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


def main(number):
    if number == 0 or (is_pr(number) and number > 7):
        return 0
    if number == 1:
        return 1
    ans = []
    while number > 1:
        for dels in range(9, 1, -1):
            if number % dels == 0:
                ans.append(dels)
                number //= dels
                break
        else:
            if number > 10:
                break
    if number <= 1 and len(ans) <= 32:
        return ''.join(map(str, sorted(ans)))
    return 0


num = int(input())
print(main(num))

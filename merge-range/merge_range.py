def makerangestr(low, high):
    return str(low) + "..." + str(high)

def merge_range(arr):
    left = 0
    right = 1
    cur = 0
    merged = []
    while (right < len(arr)):
        if arr[right] - arr[cur] == 1 or arr[right] - arr[cur] == 0:
            cur += 1
        else:
            merged.append(makerangestr(arr[left], arr[cur]))
            left = right
            cur = right
        right += 1
    merged.append(makerangestr(arr[left], arr[cur]))
    return merged

arr = [0, 1, 2, 5, 7, 8, 9, 9, 10, 11, 15]
print(merge_range(arr))

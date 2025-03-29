def quicksort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[-1]
    left = [x for x in arr[:-1] if x <= pivot]
    right = [x for x in arr[:-1] if x > pivot]
    return quicksort(left) + [pivot] + quicksort(right)

arr = [8, 3, 1, 7, 0, 10, 2]
sorted_arr = quicksort(arr)
print("Sorted Array:", sorted(arr))

def subset_sums(arr, idx=0, curr_sum=0, sums=None):
    if sums is None:
        sums = [] 

    if idx == len(arr):
        sums.append(curr_sum) 
        return sums

    subset_sums(arr, idx + 1, curr_sum + arr[idx], sums)
    

    subset_sums(arr, idx + 1, curr_sum, sums)
    
    return sums 


arr = [3, 1, 2]
result = subset_sums(arr) 
result.sort()  
print("Subset sums:", result) 

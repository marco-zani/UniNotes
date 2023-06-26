def selection_sort(arr):
    for i in range(len(arr)):      
        currMin = min(arr[i::])
        if currMin != -1:
            swap(arr, i, currMin + i)
    return arr

def swap(arr, p1,p2):
    swap = arr[p1]
    arr[p1] = arr[p2] 
    arr[p2] = swap
    return arr

def min(arr):
    out = 0
    min = arr[0]
    i = 1
    while i< len(arr):
        if min > arr[i]:
            min = arr[i]
            out = i
        i+=1
    return out





def printArr(arr):
    for el in arr:
        print(el, "", end='')
    print()
    return 


arr = [5,4,1,2,3]
printArr(arr)
print()
printArr(selection_sort(arr))
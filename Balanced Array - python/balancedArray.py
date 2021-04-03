#VMWare Sample

def balancedSum(arr):
    for i in range(1, len(arr)-1):
        sumLeft=0
        sumRight=0
        for k in range(i-1, -1, -1):
            sumLeft= sumLeft+arr[k]
        for j in range(i+1, len(arr)):
            sumRight= sumRight+arr[j]
        if sumRight==sumLeft:
            return(i)
    return(-1)


arr=[int(x) for x in input().split()]
val=balancedSum(arr)
if val== -1:
    print("Pivot does not exist")
else:
    print(val) 
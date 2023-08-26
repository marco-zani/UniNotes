# Massima sotto sequenza crescente
funzione ricorsiva:
i = 0 => 1
DP[i] è l'elemento più piccolo del vettore => 1
altrimenti trovare l'elemento precedente più piccolo e sommarsi

```python
lis(V,n):
	DP = [n]
	for el in DP:
		el = -1
	DP[0] = 1
	rec(DP, V, n)
	max = 0
	for el in DP
		if el > max:
			max = el
	print(max)

rec(DP,V,index):
	if DP[index] < 0
		DP[index] = 1
		from i = 0 to index -1:
			j = rec(DP,V,i)
			if V[i] < V[index] and j + 1 > DP[index]:
				DP[index] = j+1
	return DP[index]

```

# Insieme indipendente di intervalli pesati

```python
intervals(V,T,n):
	DP = [n]
	for el in DP:
		el = -1
	rec(DP,V,T,n)
	
rec(DP,V,A,B,index):
	if DP[index] < 0:
		if index == 0:
			DP[index] = 0
		else:
			noTaken = rec(DP, V,T, index-1)
			currMax = 0
			from i = 0 to index:
				if B[i]<=A[index] and DP[i]+V[index] > rec(DP,V,A,B,currMax):
					currMax = i
			taken = DP[currMax] + V[index]
			DP[index] = max(taken, noTaken)
	return DP[index]
```

# Somma massima di sottosequenza crescente
```python
maxSUmIncreasing(A,n):
	DP = [n]
	from i = 0 to n:
		DP[i] = A[i]
		from j = 0 to i-1:
			if A[i]>A[j] and DP[j]+A[i]>DP[i]:
				DP[i] = DP[j]+A[i]

	return max(DP)
```
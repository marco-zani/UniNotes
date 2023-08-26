# Sottosequenza comune
```python
rec(DP,A,B, a, b):
	if DP[a][b] < 0:
		if a == 0 or b == 0:
			DP[a][b] = 0
		elif A[a] == B[b]:
			DP[a][b] = rec(DP,A,B,a-1,b-1) +1
		else:
			advanceLeft = rec(DP,A,B,a-1,b)
			advanceRight = rec(DP,A,B,a,b-1)
			DP[a][b] = max(advanceLeft,advanceRight)
	return DP[a][b]
```

# Sottosequenza comune massimale
```python
rec(DP,A,B,a,b):
	if DP[a][b] <0
		if a == 0 or b == 0:
			DP[a][b] = 0
		elif A[a] == B[b]:
			DP[a][b] = rec(DP,A,B,a-1,b-1) + A[a]
		else:
			advanceLeft = rec(DP,A,B,a-1,b)
			advanceRight = rec(DP,A,B,a,b-1)
			DP[a][b] = max(advanceLeft,advanceRight)
	return DP[a][b]
```

# Sottosequenza ripetuta massimale
```python
rec(DP,A,a,b):
	if DP[a][b] < 0:
		if a == 0 or b == 0:
			DP[a][b] = 0
		elif A[a] == A[b] and a!=b:
			DP[a][b] = rec(DP,A,a-1,b-1)
		else:
			advanceLeft = rec(DP,A,a-1,b)
			advanceRight = rec(DP,A,a,b-1)
			DP[a][b] = max(advanceLeft,advanceRight)
	return DP[a][b]
```
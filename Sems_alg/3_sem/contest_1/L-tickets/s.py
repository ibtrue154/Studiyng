n, s = map(int, input().split(" "))

mas = [0-1] * (n + 1)
for i in range(n + 1):
    mas[i] = [-1] * (((s - 1) * n) // 2 + 1)

for i in range(s):
    mas[1][i] = 1

for i in range(s, ((s - 1) * n) // 2 + 1):
    mas[1][i] = 0

for i in range(2, n + 1):
    for j in range((s - 1) * n // 2 + 1):
        mas[i][j] = 0
        for t in range(s):
            if (j - t < 0):
                mas[i][j] += 0
            else:
                mas[i][j] += mas[i - 1][j - t]

print(mas[n][(s - 1) * n // 2])
l = [[23, 5], [0,1], [1,0], [3,6], [6,7], [2, -1], [2, 1]]
l.sort(key=lambda l: (l[0] ** 2 + l[1] ** 2) ** 0.5)
print(*l)
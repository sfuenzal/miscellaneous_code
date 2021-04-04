counter = 0
aux = []
while counter < 100:
    counter += 1
    aux.append(counter)

counter_2 = 0
for i in range(len(aux)):
    counter_2 += aux[i]

print(counter_2)




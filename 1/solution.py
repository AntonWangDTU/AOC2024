#!/home/aws/anaconda3/bin/python3
import sys 

with open('data.txt', 'r') as infile:

    list1 = list()    
    list2 = list()

    for line in infile:

        lists = line.strip().split()
        list1.append(int(lists[0]))
        list2.append(int(lists[1]))

list1 = sorted(list1)
list2 = sorted(list2)

distances = list()
for i in range(len(list1)):
    distances.append(abs(list1[i]-list2[i]))
print(sum(distances))

samesies = list()
for i in range(len(list1)):

    samesies.append(list1[i] * list2.count(list1[i]))

print(sum(samesies))
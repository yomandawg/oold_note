import csv

def generator(data1):
    data = csv.reader(data1)
    for line in data:

        yield line

a = open('input.csv', 'r', encoding='utf-8')

b = generator(a)

while True:
    print(next(b))
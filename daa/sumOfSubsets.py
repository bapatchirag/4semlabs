def subsets(array, num):
    if num < 0:
        return
    if len(array) == 0:
        if num == 0:
            yield []
        return

    for solution in subsets(array[1:], num):
        yield solution
    for solution in subsets(array[1:], num - array[0]):
        yield [array[0]] + solution

complete_set = [int(x) for x in input("Enter space separated numbers to be tested for: ").split(" ")]
check_num = int(input("Enter number to be tested for: "))

print("Solutions are: ")
for sol in list(subsets(complete_set, check_num)):
    print(sol)



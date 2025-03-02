def wrapper(func):
    def original (*a):
        print(f"called for {func.__name__} and args {a}")

        return  printsum(a[0],a[1],a[2])
    return original

def printsum(a,b,c):
    return a,b,c

wrapedprintsum = wrapper(printsum)



print(wrapedprintsum(3,2,4)    )
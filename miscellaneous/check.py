# for i in range(3):
#         for j in range(3):
#             print(1<<i , " ",1<<j)
#             y = (1 << i) | (1 << j)
#             print(y, end="\n\n")
#             # if y < x and x + y > (x ^ y) and y + (x ^ y) > x:
#                 # ans = y


# ___________________demonstrating nested lambda function--------------

# dalal = lambda a:  lambda x : x*a 
# mul_with5 = dalal(5)

# if __name__ == "__main__":
#     print('hello world')
#     for i in range(5):
#         print(mul_with5(i+1))

#     g = [[] for _ in range(4)]
#     print(g)

# ---------------------------------------------------------------------------------

# str = '3 5'
# u,v = list(map(int,str.split()))
# print(u,v,file=open("akaimmafile.txt","w+"))

# ----------------------------------------------------------------------

# for _ in range(int(input())):
#     print("**") 
#--------------------------------------

# import sys
# x = 1
# print(sys.getsizeof(x))
# t='ci'
# print(sys.getsizeof(t))

# ------------------------------------------------------

def subsets(nums):
    result = []
    
    def backtrack(start, path):
        # record current subset
        result.append(path[:])
        
        # explore further
        for i in range(start, len(nums)):
            # choose
            path.append(nums[i])
            # recurse
            backtrack(i + 1, path)
            # un-choose (backtrack)
            path.pop()
    
    backtrack(0, [])
    return result


print(subsets([1,2,3]))

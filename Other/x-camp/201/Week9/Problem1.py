ans = 0
def log(s):
    print(s)
    pass

def dfs(n, cur):
    global ans
    n = int(n)
    if cur > n:
        return
    ans += 1
    
    dfs(n, int(str(cur) + "0"))
    dfs(n, int(str(cur) + "1"))
        
def main():
    global ans
    n = input()
    dfs(n, 1)
    return ans

print(main())
import copy

start = [1,1,1,1,1,0,-1,-1,-1,-1,-1]
end = [-1,-1,-1,-1,-1,0,1,1,1,1,1]

def is_valid(ind):
    return ind>=0 and ind<len(end)

res = []

def f(x):
    if x==end:
        print res
        return True
    else:
        for i in range(len(x)):
            if x[i] == 1 or x[i] == -1: # move forward
                d = x[i] #direction
                if is_valid(i+d) and x[i+d] == 0:
                    res.append(copy.deepcopy(x))
                    x[i], x[i+d] = x[i+d], x[i] #swap
                    if f(x): return True
                    x[i], x[i+d] = x[i+d], x[i]
                    res.pop()
                elif is_valid(i+2*d) and x[i+2*d] == 0:
                    res.append(copy.deepcopy(x))
                    x[i], x[i+2*d] = x[i+2*d], x[i]
                    if f(x): return True
                    x[i], x[i+2*d] = x[i+2*d], x[i]
                    res.pop()
        return False

print f(start)
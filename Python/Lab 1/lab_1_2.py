fib = [0, 1]

for i in range(2, 8):
    fib.append(fib[i-1] + fib[i-2])

print("Fibonacci numbers:", fib)
print("Sum:", sum(fib))

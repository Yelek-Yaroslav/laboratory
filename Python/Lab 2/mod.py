def total_distance(n):
    distance = 10
    total = 0
    for _ in range(n):
        total += distance
        distance *= 1.1
    return total
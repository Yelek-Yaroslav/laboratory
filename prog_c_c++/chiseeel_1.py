import math

def f(x: float) -> float:
    return x + math.log10(1 + x) - 1.5

def phi(x: float) -> float:
    return 1.5 - math.log10(1 + x)

def f_prime(x: float) -> float:
    return 1 + 1 / ((1 + x) * math.log(10))

def decimals_from_eps(eps: float) -> int:
    return max(0, int(-math.log10(eps) + 0.5))

def simple_iteration(x0: float, eps: float, d: int, max_iter: int = 100) -> None:
    print("\nМетод простої ітерації:")
    x = x0
    for i in range(1, max_iter + 1):
        x_new = phi(x)
        delta = abs(x_new - x)
        print(f"x{i} = {x_new:.{d}f}, Δ{i} = {delta:.{d}g}, Δ{i} < eps → {int(delta < eps)}")
        if delta < eps:
            break
        x = x_new

def newton(x0: float, eps: float, d: int, max_iter: int = 100) -> None:
    print("\nМетод Ньютона:")
    x = x0
    for i in range(1, max_iter + 1):
        if f_prime(x) == 0:
            raise ValueError("f'(x) = 0, метод Ньютона зупинено.")
        x_new = x - f(x) / f_prime(x)
        delta = abs(x_new - x)
        print(f"x{i} = {x_new:.{d}f}, Δ{i} = {delta:.{d}g}, Δ{i} < eps → {int(delta < eps)}")
        if delta < eps:
            break
        x = x_new

if __name__ == "__main__":
    a = float(input("Введіть межу a: "))
    b = float(input("Введіть межу b: "))
    eps = float(input("Введіть бажану точність: "))

    if a >= b:
        print("Помилка: межа a повинна бути меншою за b!")
        exit()

    if f(a) * f(b) > 0:
        print("У вказаному проміжку [a, b] немає кореня або їх парна кількість.")
        exit()

    d = decimals_from_eps(eps)
    x0 = a

    simple_iteration(x0, eps, d)
    newton(x0, eps, d)

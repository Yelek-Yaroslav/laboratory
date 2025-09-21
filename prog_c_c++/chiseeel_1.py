import math
from typing import Callable, Tuple

def f(x: float) -> float:
    return x + math.log10(1 + x) - 1.5

def phi(x: float) -> float:
    return 1.5 - math.log10(1 + x)

def f_prime(x: float) -> float:
    return 1 + 1 / ((1 + x) * math.log(10))

def simple_iteration(phi: Callable[[float], float], x0: float, eps: float, max_iter: int = 1000) -> Tuple[float, int]:
    x = x0
    for i in range(1, max_iter + 1):
        x_new = phi(x)
        if abs(x_new - x) < eps:
            return x_new, i
        x = x_new
    return x, max_iter

def newton(x0: float, eps: float, max_iter: int = 1000) -> Tuple[float, int]:
    x = x0
    for i in range(1, max_iter + 1):
        if f_prime(x) == 0:
            raise ValueError("Похідна дорівнює нулю, метод Ньютона не може продовжувати.")
        x_new = x - f(x) / f_prime(x)
        if abs(x_new - x) < eps:
            return x_new, i
        x = x_new
    return x, max_iter

def decimals_from_eps(eps: float) -> int:
    return max(0, abs(int(round(math.log10(eps)))))

if __name__ == "__main__":
    a = float(input("Введіть межу a: "))
    b = float(input("Введіть межу b: "))

    if a >= b:
        print("Помилка: межа a повинна бути меншою за b!")
        exit()

    if f(a) * f(b) > 0:
        print("У вказаному проміжку [a, b] немає кореня або їх парна кількість.")
        exit()

    eps = float(input("Введіть бажану точність: "))
    d = decimals_from_eps(eps)

    x0 = (a + b) / 2

    root_iter, k_iter = simple_iteration(phi, x0, eps)
    root_newton, k_newton = newton(x0, eps)

    error_iter = abs(f(root_iter))
    error_newton = abs(f(root_newton))

    print(f"Метод простої ітерації: x = {root_iter:.{d}f}, ітерацій: {k_iter}, похибка: {error_iter:.{d + 2}e}")
    print(f"Метод Ньютона:         x = {root_newton:.{d}f}, ітерацій: {k_newton}, похибка: {error_newton:.{d + 2}e}")

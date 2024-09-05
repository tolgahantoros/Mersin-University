class B:
    def f(self, x):
        return x * 2
class A(B):
    def f(self, x):
        return x ** 2
def main():
    instance_of_A = A()
    result = instance_of_A.f(2)
    print("A sınıfındaki f(2) değeri:", result)

if __name__ == "__main__":
    main()

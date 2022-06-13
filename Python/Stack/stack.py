import os

class Stack:
    def __init__(self):
        self.top = -1
        self.arr = [0 for x in range(5)]

    def isEmpty(self):
        return True if self.top == -1 else False

    def isFull(self):
        return True if self.top == 4 else False

    def push(self, val):
        if not self.isFull():
            self.top += 1
            self.arr[self.top] = val
        else:
            print("Stack overflow")

    def pop(self):
        if self.isEmpty():
            print("Stack underflow")
        else:
            pop_value = self.arr[self.top]
            self.arr[self.top] = 0
            self.top -= 1
            return pop_value

    def peek(self, pos):
        if not self.isEmpty():
            return self.arr[pos]
        else:
            print("Stack underflow")

    def change(self, pos, val):
        self.arr[pos] = val
        print(f"Changed item on pos {pos} to value: {val}")

    def display(self):
        for x in reversed(self.arr):
            print(x)
    
    def count(self):
        return self.top + 1

def menu():
    flag = True
    s = Stack()
    while flag:
        print("1. push")
        print("2. pop")
        print("3. isEmpty")
        print("4. isFull")
        print("5. peek")
        print("6. count")
        print("7. change")
        print("8. display")
        print("9. clear")
        print("0. EXIT")

        user_in = int(input())
        if user_in == 1:
            val = int(input("Push new value: "))
            s.push(val)
        elif user_in == 2:
            print(f"Pop value from the stack: {s.pop()}")
        elif user_in == 3:
            if s.isEmpty():
                print("Empty stack")
            else:
                print("Not empty stack")
        elif user_in == 4:
            if s.isFull():
                print("Full stack")
            else:
                print("Not full stack")
        elif user_in == 5:
            pos = int(input("Item pos"))
            print(f"{pos} -> {s.peek(pos)}")
        elif user_in == 6:
            print(f"Number of item in the stack {s.count()}")
        elif user_in == 7:
            pos = int(input("Enter pos of the item to change"))
            val = int(input("Enter new value"))
            s.change(pos, val)
        elif user_in == 8:
            print("Items in the stack")
            s.display()
        elif user_in == 9:
            os.system('cls' if os.name == 'nt' else 'clear')
        elif user_in == 0:
            flag = False
            break

if __name__ == '__main__':
    menu()
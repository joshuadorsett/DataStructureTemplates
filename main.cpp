#include <iostream>
#include "Array.h"
#include "DynamicArray.h"
#include "Stack.h"
int main() {
    {
        DynamicArray<std::string> stringArray(4);
        std::string john = "john";
        stringArray.PushBack("Hi");
        stringArray.PushBack("Hi");
        stringArray.PushBack("Hi");
        stringArray.PopBack();
        stringArray.PushBack(john);
        for (int i = 0; i < stringArray.Size(); i++) {
            std::cout << "index " << i << " is " << stringArray[i] << "\n";
        }
    }

    {
        Stack<int> stack;
        stack.Push(1);
        stack.Push(2);
        stack.Clear();
        stack.Push(3);
        stack.Pop();
        stack.Push(4);
        stack.Push(5);
        stack.Clear();
        stack.Push(4);
        std::cout << "data on top of stack: " << stack.Get() << "\n";
        std::cout << "final size: " << stack.Size() << "\n";
        std::cout << "final cap: " << stack.Cap() << "\n";
    }

    std::cin.get();
}

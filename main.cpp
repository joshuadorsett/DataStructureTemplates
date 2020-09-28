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
        int num = 1;
        for (int i = 0; i < 50; i++)
        {
            stack.Push((int&&)i);
            stack.Push(num);
            num++;
            if (num > 32)
            {
                num = 0;
                stack.Clear();
            }
        }
        std::cout << stack.Pop() << "\n";
        std::cout << "data on top of stack: " << stack.Get() << "\n";
        std::cout << "final size: " << stack.Size() << "\n";
        std::cout << "final cap: " << stack.Cap() << "\n";
    }

    std::cin.get();
}

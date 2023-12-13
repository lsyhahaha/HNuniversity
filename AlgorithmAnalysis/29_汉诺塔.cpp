#include <iostream>
#include <stack>
#include <tuple>

// 递归解法
void hanoiRecursive(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << source << " to " << target << std::endl;
        return;
    }

    hanoiRecursive(n - 1, source, target, auxiliary);
    std::cout << "Move disk " << n << " from " << source << " to " << target << std::endl;
    hanoiRecursive(n - 1, auxiliary, source, target);
}

// 非递归解法
void hanoiIterative(int n, char source, char auxiliary, char target) {
    std::stack<std::tuple<int, char, char, char, bool>> stack;
    stack.push(std::make_tuple(n, source, auxiliary, target, false));

    while (!stack.empty()) {
        std::tuple<int, char, char, char, bool> current = stack.top();
        stack.pop();

        int currentN = std::get<0>(current);
        char currentSource = std::get<1>(current);
        char currentAuxiliary = std::get<2>(current);
        char currentTarget = std::get<3>(current);
        bool isReturn = std::get<4>(current);

        if (currentN == 1) {
            std::cout << "Move disk 1 from " << currentSource << " to " << currentTarget << std::endl;
        } else {
            if (!isReturn) {
                stack.push(std::make_tuple(currentN, currentSource, currentAuxiliary, currentTarget, true));
                stack.push(std::make_tuple(currentN - 1, currentSource, currentTarget, currentAuxiliary, false));
            } else {
                std::cout << "Move disk " << currentN << " from " << currentSource << " to " << currentTarget << std::endl;
                stack.push(std::make_tuple(currentN - 1, currentAuxiliary, currentSource, currentTarget, false));
            }
        }
    }
}

int main() {
    int numberOfDisks;
    std::cout << "Enter the number of disks: ";
    std::cin >> numberOfDisks;

    std::cout << "Recursive Solution:" << std::endl;
    hanoiRecursive(numberOfDisks, 'A', 'B', 'C');

    std::cout << "Iterative Solution:" << std::endl;
    hanoiIterative(numberOfDisks, 'A', 'B', 'C');

    return 0;
}

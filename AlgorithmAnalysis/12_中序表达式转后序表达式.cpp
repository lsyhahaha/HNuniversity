// #include <iostream>
// #include <stack>
// #include <cctype>

// using namespace std;

// // 判断运算符的优先级
// int precedence(char op) {
//     if (op == '+' || op == '-') {
//         return 1;
//     } else if (op == '*' || op == '/') {
//         return 2;
//     }
//     return 0;
// }

// // 中序表达式转后序表达式
// string infixToPostfix(const string& infix) {
//     string postfix = "";
//     stack<char> operators;

//     for (char ch : infix) {
//         if (isalnum(ch)) {
//             postfix += ch; // 如果是字母或数字，直接添加到后序表达式中
//         } else if (ch == '(') {
//             operators.push(ch);
//         } else if (ch == ')') {
//             // 弹出栈中的运算符直到遇到左括号
//             while (!operators.empty() && operators.top() != '(') {
//                 postfix += operators.top();
//                 operators.pop();
//             }
//             operators.pop(); // 弹出左括号
//         } else {
//             // 处理运算符
//             while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
//                 postfix += operators.top();
//                 operators.pop();
//             }
//             operators.push(ch);
//         }
//     }

//     // 弹出栈中剩余的运算符
//     while (!operators.empty()) {
//         postfix += operators.top();
//         operators.pop();
//     }

//     return postfix;
// }

// int main() {
//     string infixExpression = "a + b * c";
//     string postfixExpression = infixToPostfix(infixExpression);

//     cout << "Infix Expression: " << infixExpression << endl;
//     cout << "Postfix Expression: " << postfixExpression << endl;

//     return 0;
// }

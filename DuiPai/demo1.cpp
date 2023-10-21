#include <cstdlib>
#include <cstdio>
#include <ctime>

int main() {
    for (int T = 1; T <= 10000; T++) {
        // 自行设定适当的路径
        system("C:\\random.exe");
        // 当前程序已经运行的CPU的时间，Windows下单位ms,Unix下单位s
        double st = clock();
        system("C:\\sol.exe");
        double ed = clock();
        system("C:\\bf.exe");
        if (system("fc C:\\data.out C:\\data.ans")) {
            puts("Wrong Answer");
            // 程序立即退出，此时data.in即为发生错误的数据
            return 0;
        }
        else {
            printf("Accepted, 测试点 #%d, 用时 %.0lfms\n", T, ed-st);
        }
    }
}
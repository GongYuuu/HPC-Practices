// main.cpp
#include <iostream>
#include <chrono>
#include <fstream>
#include "kernel_axpy.h"

int main()
{
    const int n = 102400;  // 向量长度
    float a = 3.14f;  // 常数a
    float x[n], y[n];  // 向量x和y

    // 初始化x和y
    for(int i = 0; i < n; ++i) {
        x[i] = i % 100 * 0.01f;  // 填充0.0到0.99之间的值
        y[i] = 12.0f - a * x[i];  // 根据给定的计算规则初始化y
    }

    // 记录开始时间
    auto start = std::chrono::high_resolution_clock::now();

    // 调用saxpy函数
    saxpy(n, a, x, y);

    // 记录结束时间
    auto end = std::chrono::high_resolution_clock::now();

    // 计算运行时间
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "saxpy function took " << elapsed.count() << " seconds." << std::endl;

    // 将结果输出到文件
    std::ofstream outfile("y_value.txt");
    for(int i = 0; i < n; ++i) {
        outfile << y[i] << std::endl;
    }
    outfile.close();

    return 0;
}

// main.cpp
#include <iostream>
#include <chrono>
#include <fstream>
#include "kernel_axpy.h"

int main()
{
    const int n = 102400;  // ��������
    float a = 3.14f;  // ����a
    float x[n], y[n];  // ����x��y

    // ��ʼ��x��y
    for(int i = 0; i < n; ++i) {
        x[i] = i % 100 * 0.01f;  // ���0.0��0.99֮���ֵ
        y[i] = 12.0f - a * x[i];  // ���ݸ����ļ�������ʼ��y
    }

    // ��¼��ʼʱ��
    auto start = std::chrono::high_resolution_clock::now();

    // ����saxpy����
    saxpy(n, a, x, y);

    // ��¼����ʱ��
    auto end = std::chrono::high_resolution_clock::now();

    // ��������ʱ��
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "saxpy function took " << elapsed.count() << " seconds." << std::endl;

    // �����������ļ�
    std::ofstream outfile("y_value.txt");
    for(int i = 0; i < n; ++i) {
        outfile << y[i] << std::endl;
    }
    outfile.close();

    return 0;
}

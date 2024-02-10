# 程序saxpy实现了单精度浮点型数据的向量加法运算，其具体公式如下：

y[n]=y[n]+a*x[n]

其中，n为向量长度，x、y为向量数组，a为标量系数，x、y、a均为单精度浮点型float。

各变量的初始值如下：

n为102400

a为3.14

x中各元素初始为0.0~6.0间的浮点型随机数

y初始取值为y[n] = 12.0 - a * x[n]

程序的文件组织如下：

kernel_axpy.h

负责向量加法接口函数的声明如下：
1. void saxpy(const float a,const float * const x, float *y)，其中，a、x 为输入, y 即为输入、也为输出。kernel_axpy.cpp 负责向量加法接口函数saxpy()的定义实现。 main.cpp 负责初始化向量。调用向量加法接口saxpy()

2. 使用计时函数clock()统计saxpy()的运行时间，并打印到屏幕

3. 打印结果y的前20个元素数值到文件y_value.txt

# 编写Makefile，用以编译课程的作业saxpy程序
要求：

分别使用-O0、-O2优化等级的编译选项
将编译和链接阶段分开
二进制文件名称分别命令为saxpy.O0.exe，saxpy.O2.exe

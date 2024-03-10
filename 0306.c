#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int rows;
    int cols;
    double data[MAX_SIZE * MAX_SIZE];
} Matrix;

// 获取矩阵中元素的值
double get(Matrix mat, int row, int col) {
    return mat.data[row * mat.cols + col];
}

// 设置矩阵中元素的值
void set(Matrix mat, int row, int col, double val) {
    mat.data[row * mat.cols + col] = val;
}

// 创建一个 rows x cols 的零矩阵
Matrix zeros(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    for (int i = 0; i < rows * cols; i++) {
        mat.data[i] = 0.0;
    }
    return mat;
}

// 打印矩阵
void printMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%.2f ", get(mat, i, j));
        }
        printf("\n");
    }
}

// 矩阵加法
Matrix add(Matrix mat1, Matrix mat2) {
    if (mat1.rows != mat2.rows || mat1.cols != mat2.cols) {
        printf("Error: 矩阵尺寸不匹配\n");
        return zeros(0, 0);
    }
    Matrix result = zeros(mat1.rows, mat1.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.cols; j++) {
            set(result, i, j, get(mat1, i, j) + get(mat2, i, j));
        }
    }
    return result;
}

// 矩阵乘法
Matrix multiply(Matrix mat1, Matrix mat2) {
    if (mat1.cols != mat2.rows) {
        printf("Error: 矩阵尺寸不匹配\n");
        return zeros(0, 0);
    }
    Matrix result = zeros(mat1.rows, mat2.cols);
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat2.cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < mat1.cols; k++) {
                sum += get(mat1, i, k) * get(mat2, k, j);
            }
            set(result, i, j, sum);
        }
    }
    return result;
}

// 计算矩阵的转置
Matrix transpose(Matrix mat) {
    Matrix result = zeros(mat.cols, mat.rows);
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            set(result, j, i, get(mat, i, j));
        }
    }
    return result;
}

int main() {
    // 创建一个矩阵
    Matrix mat1 = zeros(2, 3);
    set(mat1, 0, 0, 1.0);
    set(mat1, 0, 1, 2.0);
    set(mat1, 0, 2, 3.0);
    set(mat1, 1, 0, 4.0);
    set(mat1, 1, 1, 5.0);
    set(mat1, 1, 2, 6.0);

    // 打印原始矩阵
    printf("原始矩阵:\n");
    printMatrix(mat1);

    // 计算转置矩阵
    Matrix transposeMat = transpose(mat1);

    // 打印转置矩阵
    printf("\n转置矩阵:\n");
    printMatrix(transposeMat);

    return 0;
}
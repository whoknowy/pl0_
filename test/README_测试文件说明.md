# PL/0编译器测试文件说明

## 📁 测试文件分类

### 🔵 基础功能测试

#### 1. 基本do-while循环
- **`do_while_simple.pl0`** - 最简单的do-while循环
  - 功能：输出1到3的数字
  - 预期输出：`1 2 3`
  - 难度：⭐

- **`do_while_basic.pl0`** - 带计算的do-while循环
  - 功能：计算1到5的和
  - 预期输出：`15`
  - 难度：⭐

- **`do_while_calc.pl0`** - 带常量的do-while循环
  - 功能：使用常量进行累加计算
  - 预期输出：`6`
  - 难度：⭐

#### 2. 一维数组测试
- **`array.pl0`** - 基础一维数组
  - 功能：数组的声明、赋值和访问
  - 预期输出：`15`
  - 难度：⭐⭐

- **`do_while_simple_array.pl0`** - do-while与一维数组
  - 功能：使用do-while循环操作数组
  - 预期输出：`55`
  - 难度：⭐⭐

- **`do_while_array.pl0`** - 复杂数组操作
  - 功能：数组统计、查找最大值
  - 预期输出：`55 11 25 5`
  - 难度：⭐⭐⭐

### 🔵 二维数组测试

#### 3. 基础二维数组
- **`array2d_simple.pl0`** - 简单二维数组
  - 功能：2×2矩阵的基本操作
  - 预期输出：`2 3 3 4`
  - 难度：⭐⭐

- **`array2d_test.pl0`** - 基础二维数组操作
  - 功能：3×4矩阵的初始化和遍历
  - 预期输出：`11 12 13 14 21 22 23 24 31 32 33 34 180`
  - 难度：⭐⭐

#### 4. 二维数组与do-while结合
- **`array2d_do_while.pl0`** - 基础二维数组与do-while
  - 功能：3×3乘法表生成
  - 预期输出：`1 2 3 2 4 6 3 6 9 36`
  - 难度：⭐⭐⭐

- **`array2d_do_while_advanced.pl0`** - 高级二维数组操作
  - 功能：4×4矩阵的行列统计
  - 预期输出：`10 14 18 22 10 14 18 22 16`
  - 难度：⭐⭐⭐⭐

- **`array2d_do_while_matrix.pl0`** - 矩阵运算
  - 功能：两个3×3矩阵的加法
  - 预期输出：`3 5 7 5 8 11 7 11 15 72`
  - 难度：⭐⭐⭐⭐

### 🔵 高级功能测试

#### 5. 复杂循环结构
- **`do_while_nested.pl0`** - 嵌套do-while循环
  - 功能：生成乘法表
  - 预期输出：`1 2 3 2 4 6 3 6 9 6`
  - 难度：⭐⭐⭐

- **`do_while_condition.pl0`** - 条件判断do-while
  - 功能：数组条件统计
  - 预期输出：`5 60 20 4`
  - 难度：⭐⭐⭐

- **`do_while_fibonacci.pl0`** - 斐波那契数列
  - 功能：使用do-while计算斐波那契数列
  - 预期输出：`1 1 2 3 5 8 13 21 34 55 143 55 10`
  - 难度：⭐⭐⭐⭐

#### 6. 其他功能测试
- **`forloop.pl0`** - for循环测试
  - 功能：for循环的基本使用
  - 预期输出：`15`
  - 难度：⭐⭐

- **`else.pl0`** - if-else语句测试
  - 功能：条件语句的测试
  - 预期输出：`1`
  - 难度：⭐⭐

- **`fuhe.pl0`** - 复合语句测试
  - 功能：复合语句的测试
  - 预期输出：`10`
  - 难度：⭐

- **`zhushi.pl0`** - 注释测试
  - 功能：注释功能的测试
  - 预期输出：`5`
  - 难度：⭐

## 🎯 推荐测试顺序

### 初学者测试顺序
1. `do_while_simple.pl0` - 最基础
2. `do_while_basic.pl0` - 带计算
3. `array.pl0` - 一维数组
4. `array2d_simple.pl0` - 二维数组
5. `forloop.pl0` - for循环

### 进阶测试顺序
1. `do_while_simple_array.pl0` - 数组与循环
2. `array2d_do_while.pl0` - 二维数组与循环
3. `do_while_nested.pl0` - 嵌套循环
4. `do_while_condition.pl0` - 条件判断
5. `array2d_do_while_advanced.pl0` - 高级操作

### 完整功能测试
1. `do_while_array.pl0` - 复杂数组操作
2. `array2d_do_while_matrix.pl0` - 矩阵运算
3. `do_while_fibonacci.pl0` - 算法实现
4. `array2d_complex.pl0` - 复杂二维数组操作

## 📊 测试覆盖功能

### ✅ 已测试功能
- [x] do-while循环
- [x] for循环
- [x] if-else语句
- [x] 一维数组
- [x] 二维数组
- [x] 嵌套循环
- [x] 条件判断
- [x] 算术运算
- [x] 注释处理
- [x] 常量定义
- [x] 变量声明
- [x] 复合语句

### 🔧 测试方法
```bash
# 运行单个测试
echo test/do_while_simple.pl0 | .\pl0.exe

# 批量测试（建议）
for file in test/*.pl0; do
    echo "Testing $file"
    echo "$file" | .\pl0.exe
    echo "---"
done
```

## 📝 测试结果记录

| 测试文件 | 功能 | 状态 | 输出结果 | 备注 |
|---------|------|------|----------|------|
| do_while_simple.pl0 | 基础循环 | ✅ | 1 2 3 | 正常 |
| do_while_basic.pl0 | 计算循环 | ✅ | 15 | 正常 |
| array2d_do_while.pl0 | 二维数组循环 | ✅ | 1 2 3 2 4 6 3 6 9 36 | 正常 |
| array2d_do_while_advanced.pl0 | 高级矩阵操作 | ✅ | 10 14 18 22 10 14 18 22 16 | 正常 |
| array2d_do_while_matrix.pl0 | 矩阵运算 | ✅ | 3 5 7 5 8 11 7 11 15 72 | 正常 |

---
*最后更新：2025年1月*

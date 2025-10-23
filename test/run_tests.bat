@echo off
echo ========================================
echo PL/0编译器测试脚本
echo ========================================
echo.

echo 1. 基础功能测试
echo --------------------------------
echo 测试do-while循环...
echo test/basic/do_while_simple.pl0 | pl0.exe
echo.
echo 测试for循环...
echo test/basic/forloop.pl0 | pl0.exe
echo.
echo 测试注释功能...
echo test/basic/zhushi.pl0 | pl0.exe
echo.

echo 2. 数组功能测试
echo --------------------------------
echo 测试一维数组...
echo test/arrays/array.pl0 | pl0.exe
echo.
echo 测试二维数组...
echo test/arrays/array2d_simple.pl0 | pl0.exe
echo.
echo 测试二维数组与do-while结合...
echo test/arrays/array2d_do_while.pl0 | pl0.exe
echo.

echo 3. 高级功能测试
echo --------------------------------
echo 测试嵌套循环...
echo test/advanced/do_while_nested.pl0 | pl0.exe
echo.
echo 测试斐波那契数列...
echo test/advanced/do_while_fibonacci.pl0 | pl0.exe
echo.

echo ========================================
echo 测试完成！
echo ========================================
pause

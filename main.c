#include "CuTest.c"
#include "CuTest.h"
int
sum(int a, int b)
{
    return a + b;
}

void
test_add(CuTest *cuTest)
{
    int re = sum(1, 1);
    CuAssertIntEquals(cuTest, 2, re);
}
void
test_add1(CuTest *cuTest)
{
    int re = sum(2, 1);
    CuAssertIntEquals(cuTest, 3, re);

}
void
test_all()
{
    // 定义用于存储测试信息的字符串
    CuString *output = CuStringNew();
    // 新建测试套件
    CuSuite *suite = CuSuiteNew();
    // 把 test_add 方法加入到测试套件中
    SUITE_ADD_TEST(suite, test_add);
    // 把 test_add1 方法加入到测试套件中
    SUITE_ADD_TEST(suite, test_add1);
    // 运行测试套件
    CuSuiteRun(suite);
    // 把运行后的结果存入 output 中
    CuSuiteDetails(suite, output);
    // 打印测试结果
    printf("%s\n", output->buffer);
}
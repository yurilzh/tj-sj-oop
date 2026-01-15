/* 2451899 刘哲豪 计科 */
#include <iostream>
#include <iomanip>
using namespace std;

#define STUDENT_NUM	4
#define SCORE_NUM	5

/* --- 不允许定义任何形式的全局变量 --- */

/***************************************************************************
  函数名称：
  功    能：求第一门课的平均分
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void average(int (*score)[STUDENT_NUM])
{
    /* 函数定义语句部分：
       1、本函数中仅允许定义 1个简单变量 + 1个指针变量 */
    int *oneScore = *score, sum = 0;
    /* 函数执行语句部分：
       1、不允许再定义任何类型的变量，包括 for (int i=0;...）等形式定义变量
       2、循环变量必须是指针变量，后续语句中不允许出现[]形式访问数组
          不允许：int a[10], i;
                  for(i=0; i<10; i++)
                      cout << a[i];
          允许  ：int a[10], p;
                  for(p=a; p<a+10; p++)
                      cout << *p;          */
    for (; oneScore < *score + STUDENT_NUM; oneScore++)
        sum += *oneScore;
    cout << "第1门课平均分：" << sum / double(STUDENT_NUM) << endl;
}

/***************************************************************************
  函数名称：
  功    能：找出有两门以上课程不及格的学生
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void fail(int (*score)[STUDENT_NUM])
{
    /* 函数定义语句部分：
       1、本函数中仅允许定义 3个简单变量 + 1个行指针变量 + 1个简单指针变量 */
    int (*aclass)[STUDENT_NUM] = score, failNum, sum, id;
    /* 函数执行语句部分（要求同average）*/
    cout << "2门以上不及格的学生：" << endl;
    for (id = 0; id < STUDENT_NUM; id++) {
        for (failNum = 0, aclass = score; aclass < score + SCORE_NUM; aclass++)
            if (*(*aclass + id) < 60)
                failNum++;
        if (failNum >= 2) {
            cout << "No：" << id + 1;
            for (aclass = score, sum = 0; aclass < score + SCORE_NUM; aclass++) {
                sum += *(*aclass + id);
                cout << ' ' << *(*aclass + id);
            }
            cout << " 平均：" << sum / double(SCORE_NUM) << endl;
        }
    }
}

/***************************************************************************
  函数名称：
  功    能：找出平均成绩在90分以上或全部成绩在85分以上的学生
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void good(int (*score)[STUDENT_NUM])
{
    /* 函数定义语句部分：
       1、本函数中仅允许定义 3个简单变量 + 1个行指针变量 + 1个简单指针变量 */
    int (*aclass)[STUDENT_NUM] = score, sum, id, isGood;
    /* 函数执行语句部分（要求同average）*/
    cout << "平均90以上或全部85以上的学生：" << endl;
    for (id = 0; id < STUDENT_NUM; id++) {
        for (isGood = 1, sum = 0, aclass = score; aclass < score + SCORE_NUM; aclass++) {
            sum += *(*aclass + id);
            if (*(*aclass + id) < 85)
                isGood = 0;
        }
        isGood = isGood || sum >= 90 * SCORE_NUM;
        if (isGood) {
            cout << "No：" << id + 1;
            for (aclass = score; aclass < score + SCORE_NUM; aclass++)
                cout << ' ' << *(*aclass + id);
            cout << " 平均：" << sum / double(SCORE_NUM) << endl;
        }
    }

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    int a[SCORE_NUM][STUDENT_NUM] = {
        {91,92,93,97},  //第1-4个学生的第1门课成绩
        {81,82,83,85},  //第1-4个学生的第2门课成绩
        {71,72,99,87},  //第1-4个学生的第3门课成绩
        {61,32,80,91},  //第1-4个学生的第4门课成绩
        {51,52,95,88} };//第1-4个学生的第5门课成绩
    /* 除上面的预置数组外，本函数中仅允许定义 1个行指针变量 + 1个简单指针变量 */
    int (*aclass)[STUDENT_NUM] = a;
    int* oneScore = *aclass;

    /* 函数执行语句部分（要求同average）*/
    cout << "初始信息：" << endl;
    for (; aclass - a < SCORE_NUM; aclass++) {
        cout << "No.1-4学生的第" << aclass - a + 1 << "门课的成绩：";
        for (oneScore = *aclass; oneScore - *aclass < STUDENT_NUM; oneScore++)
            cout << *oneScore << ' ';
        cout << endl;
    }
    cout << endl;
    average(a);
    cout << endl;
    fail(a);
    cout << endl;
    good(a);
    return 0;
}

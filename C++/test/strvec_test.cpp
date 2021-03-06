#include <iostream>
#include "strvec.h"

using namespace std;
using namespace lf_vec;

void strVecTest()
{
    StrVec v;
    v.push_back("1");
    cout << v << endl;
    v.push_back("2");
    cout << v << endl;
    v.push_back("3");
    cout << v << endl;
    v.push_back("4");
    cout << v << endl;
    StrVec v2(v);
    cout << v << endl << v2 << endl;
    v2.push_back("100");
    cout << v2 << endl;
    v = {"1", "2", "3", "6"};
    const StrVec cv = v;
    v[0] = "";
    cv[0];
    v++;
    ++v;
}

void strVecMoveTest()
{
    vector<StrVec> v;
    v.push_back(retStrVec());
    // 编译器经过特殊优化编程直接初始化，没有移动，甚至没有调用构造函数，由于Copy elision的特性。-fno-elide-constructors可以禁止这个特性
    // https://zh.cppreference.com/w/cpp/language/copy_elision
    // StrVec a(retStrVec()) 
    StrVec a(std::move(retStrVec()));
    a = retStrVec();
    cout << a << endl;
}
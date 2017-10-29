/******************************************************************************
      function:该文件主要测试一下"深入应用C++11代码优化与工程级应用"
	           的第七章几个知识点（全部内容来自该书）
      author：Demon
	  Time:2017/10/29
	  注：关于内存方面的知识点，下次总结一下才行。（知识点有点多，也有点乱）
******************************************************************************/

#include<iostream>
#include<string>
#include<codecvt>
using namespace std;

//★委托构造函数
/*
struct A
{   
	A(int tempx)
	{
		x = tempx;
	}
	A(int tempx, int tempy):A(tempx)
	{
		y = tempy;
	}
	int x;
	int y;
	
};
*/

//★继承构造函数
/*
struct A
{
	A(){}
	A(int tempx):x(tempx){}
	A(int tempx, int tempy):x(tempx),y(tempy){}
	int x;
	int y;
};
struct B :A
{
	using A::A;
	B(int tempz):z(tempz){}
	int z;
};
*/

//★final
/*
struct A 
{
	virtual void test()final{}
};
struct B :A
{
	//virtual void test(){}//错误，不可重写
};
*/
//struct B final
//{
//
//};
//struct C :B//错误用法
//{
//
//};
//★override
/*
struct A
{
	virtual void test(){}
};
struct B :A
{
	virtual void test()override{}
};
*/
int main()
{
	//●数值类型转字符串（to_string)
	/*
	string s;
	wstring ws;
	int i = 10;
	long f = 132;
	s=to_string(i);
	ws = to_wstring(f);
	cout << "s=" <<s<< endl;
	wcout << "ws=" << ws << endl;
	*/
	
	//●字符串转为整型和浮点型(atoi,atol,atoll,atof)
	/*
	char const*str1 = "123";
	char const*str2 = "hello123";
	char const*str3 = "456hello";
	char const*str4 = "123.45";
	char const*strll= "200000000012345g";
	cout << atoi(str1) << endl;
	cout << atoi(str2) << endl;
	cout << atoi(str3) << endl;
	cout << atoi(str4) << endl;
	cout << atof(str4) << endl;
	cout << atoi(strll) << endl;
	cout << atol(strll) << endl;
	cout << atoll(strll) << endl;
	*/

	//●宽窄字符转化（wstring_convert)
	/*
	string str = "自称臣是酒中仙";
	wstring wstr = L"独钓寒江雪";

	wstring_convert<std::codecvt<wchar_t, char, std::mbstate_t>>
	converter(new std::codecvt<wchar_t, char, std::mbstate_t>("CHS"));

	string tempStr = converter.to_bytes(wstr);
	cout << tempStr << endl;

	wstring tempWstr = converter.from_bytes(str);
	wcout.imbue(std::locale("chs"));
	wcout << tempWstr << endl;
    */

    //★委托构造函数（同一个类中，一个构造函数调用另一个构造函数）
	/*
	//注意：1.调用委托构造函数，不可再使用类成员初始化了。
	//      2.构造函数不可以形成一个环。
	 A a(12,16);
	*/

	//★继承构造函数
	/*
	B b(223);
	B b1(12, 16);
	B b2(23);
	cout << b.x << "  " << b.y << "  " << b.z << endl;
	cout << b1.x << "  " << b1.y << "  " << b1.z << endl;
	cout << b2.x << "  " << b2.y << "  " << b2.z << endl;
	*/

	//★原始字面量(R)
	/*
	char const*str = R"(C:\Users\Public\Desktop\QQ音乐.lnk)";
	cout << str<< endl;
	*/

	//★final(final可以用来表示某个类不能被继承，或者某个虚函数不能被重写）

	//★override(确定在派生类中重写和基类相同签名的函数，防止想重写，结果去重载）

	return 0;
}
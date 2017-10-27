/**************************************************************************
     function:该文件主要用来测试一下"深入C++代码优化与工程级应用"该书的
	          第二章知识点（全部内容均来自该书，回顾一下学习过的知识点）
     author：Demon
	 Time:2017/10/27
***************************************************************************/

#include<windows.h>
#include<iostream>
#include<list>
#include<vector>
#include<map>
#include<string>
#include<unordered_map>


using namespace std;

/////// 2.1右值引用

//int g_constructCount = 0;
//int g_copyConstructCount = 0;
//int g_destructCount = 0;
//struct A
//{
//	A()
//	{
//		cout << "construct:" << ++g_constructCount << endl;
//	}
//	A(A const&a)
//	{
//		cout << "copy construct:" << ++g_copyConstructCount << endl;
//	}
//	~A()
//	{
//		cout << "destruct:" << ++g_destructCount << endl;
//	}
//
//};
//A GetA()
//{
//
//	return A();
//}

////// 2.2 move的使用

//std::list<int> L1 = { 1,3,5,7,9 };
//std::list<int> L2;

////// 2.3 forward 完美转发

//void Test(int&&v)
//{
//	cout << "rvalue" << endl;
//}
//void Test1(int&&v)
//{
//	Test(forward<int>(v));
//}


//////2.4 emplace_back减少内存拷贝和移动

//struct A {
//	int x;
//	double y;
//	A(int a, double b) :x(a), y(b) {}
//};

//struct B
//{
//	int year;
//	std::string name;
//	B(int a,string b):year(a),name(b)
//	{
//		cout << "construct" << endl;
//	}
//	B(B const&temp):year(temp.year),name(std::move(temp.name))
//	{
//		cout << "copy construct" << endl;
//	}
//};

//////2.5 unordered container(unordered_map/multimap/set/multiset)的使用



int main()
{

	/////// 2.1右值引用
	/*
	A&&a=GetA();
	*/


	////// 2.2 std::move
	/*
	L1;
	L2;
	cout << "L1:" << endl;
	for (auto i : L1)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << "L2:" << endl;
	for (auto i : L2)
	{
		cout << i << " ";
	}
	cout << endl;
	L2 = std::move(L1);
	cout << "move后L1:" << endl;
	for (auto i : L1)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << "move后L2:" << endl;
	for (auto i : L2)
	{
		cout << i << " ";
	}
	cout << endl;
	*/


	//////2.3 std::forward

	/*
	int x = 1;
	Test(1);
	*/


	//////2.4 emplace_back减少内存拷贝和移动（可以通过参数构造对象,不需要拷贝或者移动内存）

	/*
	vector<A> v;
	v.emplace_back(1, 3);
	v.emplace_back(2, 5.66);
	cout << v.size() << endl;
	for (auto i : v)
	{
		cout << "x=" << i.x << " " << "y=" << i.y << endl;
	}
	*/

	/*
	std::map<int, B> m;
	int tempInt = 6;
	std::string tempName = "C++";
	cout << "--insert--" << endl;
	m.insert(std::make_pair(6, B(tempInt, tempName)));
	cout << "--emplace--" << endl;
	m.emplace(6, B(tempInt, tempName));
	cout << "--emplace_back--" << endl;
	vector<B> v;
	v.emplace_back(tempInt, tempName);
	*/
	
	//////2.5 unordered container

	/*
	std::map<int,int> m;
	std::unordered_map<int, int> m1;
	m.emplace(1,4);
	m.emplace(7,1);
	m.emplace(3,6);
	m.emplace(9,11);
	m.emplace(11,8);
	m.emplace(6, 2);
	m1.emplace(1,4);
	m1.emplace(7,1);
	m1.emplace(3,6);
	m1.emplace(9,11);
	m1.emplace(11,8);
	m1.emplace(6,2);
	cout << "m:" << endl;
	for (auto i : m)
	{
		cout << i.second << "  ";
	}
	cout << endl;
	cout << "m1:" << endl;
	for (auto i : m1)
	{
		cout << i.second << "  ";
	}
	cout << endl;
	*/

	return 0;
}
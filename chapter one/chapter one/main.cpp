/********************************************************************************************
    
	    该cpp文件的作用：回顾一下“深入应用C++11代码优化与工程级应用"的第一章
		author：Demon
		Time：2017/9/23

********************************************************************************************/
#include<iostream>
#include<vector>
#include<functional>
using namespace std;

////auto受限

////1.不能用于非静态成员变量
//struct Foo
//{
//	//auto var1 = 0;              //error:auto不能用于非静态成员变量
//	static const auto var2 = 0;//OK，var2->static const int
//};
//
////2.不能用于函数参数
//void func(auto a = 1)//error：不能用于函数参数
//{
//
//}
////3.无法定义数组
//auto arr[2]= {0};//error：无法定义数组
//
////4.无法到处模版参数
//template<typename T>
//struct Bar {};
//
//Bar<int> bar;
//Bar<auto> bb = bar;//error：无法导出模版参数




int main()
{

	//1.1类型推导

	///1.1.1 auto类型推导
	//auto x = 5;               //x :int
	//auto pi = new auto(1);    //pi:int*
	//const auto *v = &x,u=8;   //v:const int*,u:const int
	//static auto f = 0.4;      //y:double
	//
	//int y =1;
	//auto &a = y;//a:int &,auto:int
	//auto b = a; //b:int,auto:int(当表达式是一个引用时，auto会把引用类型抛弃）
	//const auto c = 1; //c:int const 
	//auto d = c;      //d:int(当表达式中带有const，volatile属性时，auto会把该属性抛弃）
	//const auto &g = y;//g:const int &
	//auto &h = g;      //h：const int&(当auto和引用结合时，auto推导保留表达式的const属性）

	//遍历使用auto

	//std::vector<int> vv;
	//vv.push_back(3);
	//vv.push_back(7);
	//for (auto it = vv.begin();it!= vv.end();it++)//用于推断迭代器的类型
	//{
	//	cout<<*it<< endl;
	//}


	///1.1.2 decltype关键字

	//int  x = 0;
	//decltype(x+7) y = 1;  //y->int 
	//const int&i = x;
	//decltype(i) j = y; //j->const int &


	//1.标识符和类表达式推导

	//class Foo
	//{
	//public:
	//	static const int Number = 0;
	//	int x;
	//	
	//};
	//int n = 0;
	//volatile const int &x = n;
	//decltype(n) a = n;   //a->int
	//decltype(x) b = n;  //b->const volatile int &
	//decltype(Foo::Number) c = 0; //c->const int 
	//Foo foo;
	//decltype(foo.x) d=0          //d->int，类访问表达式


	////2.函数调用

	//int&func_int_r(void);             //左值
	//int&&func_int_rr(void);           //x值
	//int func_int(void);              //纯右值
	//const int&func_cint_r(void);
	//const int&&func_cint_rr(void);
	//const int func_cint(void);
    //测试语句
	//int x = 0;
	//decltype(func_int_r())  a1 = x; //a1->int&
	//decltype(func_int_rr()) b1 = 0; //b1->int&&
	//decltype(func_int())    c1 = 0; //c1->int
	//decltype(func_cint_r())  a2 = x;//a2->const int&
	//decltype(func_cint_rr()) b2 = 0;//b2->const int&&
	//decltype(func_cint())    c2 = 0;//c2->int(因为函数返回的int是一个纯右值，对于纯右值，只有类类型可以携带（const，volatile）限定符。
	//class Foo
	//{
	//	
	//};
	//const Foo func_cfoo(void);
	//decltype(func_cfoo()) ff = Foo();//ff->const Foo(函数返回值是一个纯右值，类类型可以携带（const，volatile）限定符。）
	//3.带括号的表达式和加法运算表达式
	//struct Foo1
	//{
	//	int x;
	//};
	//const Foo1 foo = Foo1();
	//
	//decltype(foo.x) a = 0;   //a->int
	//decltype((foo.x)) b = a; //b->const int&（foo.x是一个左值，可知括号表达式也是一个左值）
	//int n = 0, m = 0;
	//decltype(n + m) c = 0;   //c->int
	//decltype(n += m) d = c;//d->int&,n+=m返回一个左值


	///1.1.3返回类型后置语法（auto和decltype的结合使用）
    
   /* template<typename T,typename U>
	auto Add(T t, U u) ->decltype(t + u)
	{

		return r + u;
	}

	int foo(int*i);
	float foo(float&f);

	template<typename T>
	auto func(T&t) ->decltype(t)
	{
		return t;
	}*/

///1.2 模版的细节改进

 //1.2.1 模版的右尖括号

//template<typename T>
//struct Foo
//{
//	typedef T type;
//};
//template<typename T>
//class A
//{
//
//};
//Foo<A<int>>::type xx;//c++11支持使用">>"两个连续的，c++98不支持，会被误以为是右移。

 //模版的别名

//重定义

//typedef unsigned int u_int;
//using u_int = unsigned int;
//
//typedef std::vector<int> v_int;
//using v_int = std::vector<int>;
//例子
//template<typename T>
//struct foo_u
//{
//	typedef void(*type)(T, T);
//};
//foo_u<int>::type xx_1;
////c++11
//template<typename T>
//using foo1 = void(*)(T, T);
//foo1<int> xx_2;
//

//1.2.3 函数模版的默认参数

//C++11支持函数模版有默认模版参数,以下例子在C++98不支持
//template<typename T=int>
//void f(void)
//{
//
//}

///1.3 列表初始化

//1.3.1统一的初始化

//int*a = new int{ 123 };
//double b = double{ 12.12 };
//int*arr = new int[3]{ 1,2,3 };
//struct f
//{
//	f(int){}
//};
//f temp1 = { 45 };
//f temp2{ 34 };
//

//1.3.1 列表初始化的使用细节

//：集合体的概念（是聚合体就可以使用初始化列表）

//1.类型是一个普通数组。
//2.类型是一个类。且要满足以下条件
     /*1.无用户自定义的构造函数
	 2.无私有或者保护的非静态数据成员
	 3.无基类
	 4.无虚函数
	 5.不能有{}和=直接初始化的非静态数据成员*/
//3.对于一个数组而言，只要该类型是一个普通数组，哪怕数组的元素并非一个聚合类型，这个数组本身也是一个聚合类型。

///1.3.3  初始化列表

// 1.3.1 任意长度的初始化列表

//int arr[]={1,2,3};//没有指定长度，可以任意长
//使用 std::initializer_list这个轻量级的模版
//void f(std::initializer_list<int> L)
//{
//	for (auto it = L.begin();it != L.end();it++)
//	{
//		cout << *it << endl;
//	}
//}
//f({});
//f({ 1,2,456,787,33,8 });
//使用std::initializer_list使用的一些细节
//1.元素必须为同种
//2.只有3个成员接口：size(),begin(),end()
//3.只能整体初始化或者赋值
//注意：std::initializer_list仅仅存储了列表元素的引用而已。所以不该如下使用
  //   std::initializer_list<int> f(void)
  //  {
  //      int a=1,b=2;
  //      return {a+b};//a,b返回时没有被拷贝
  //  }

//1.3.2 防止类型收缩

//int a = 1.1;
//int b = { 1.1 }; //error:初始化列表不予许类型收缩

///1.4 基于范围的for循环

//std::vector<int> arr;
//arr.push_back(55);
//arr.push_back(77);
//for (auto i : arr)//冒号后面的表达式只执行一次
//{
//	cout << i << endl;
//}


///1.5 std::function和bind绑定器

//1.5.1 可调用对象

//1.是一个函数指针
//2.是一个具有operator（）成员函数的类对象（仿函数）
//3.是一个可被转化为函数指针的类对象
//4.是一个类成员（函数）指针
//例子
//void func(void)
//{
//
//}
//struct Foo
//{
//	void operator()(void)
//	{
//
//	}
//};
//struct Bar
//{
//	using fr_t = void(*)(void);
//	static void func(void)
//	{
//
//	}
//	operator fr_t(void)
//	{
//		return func;
//	}
//
//};
//struct A
//{
//	int a_;
//	void mem_func(void)
//	{
//
//	}
//};
////////
//void(*func_ptr)(void) = &func;//函数指针
//func_ptr();
//Foo foo;
//foo();//仿函数
//Bar bar;
//bar();//可被转化为函数指针的类对象
//void (A::*mem_func_ptr)(void) = &A::mem_func;//类成员函数指针
//int A::*mem_obj_ptr = &A::a_;//类成员指针


//1.5.2 可调用对象包装器 std::function


return 0;
}

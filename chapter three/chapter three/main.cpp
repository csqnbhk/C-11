/******************************************************************************************
            function:该文件主要测试一下"深入C++11代码优化与工程级应用"(全部内容来自该书）
			author:Demon
            Time:2017/10/28
*******************************************************************************************/
#include<windows.h>
#include<iostream>
#include<memory>
#include<type_traits>
using namespace std;

///////●●●●●● 3.1 type_traits 类型萃取

//1.圈复杂度（从函数第一行开始，一直往下看程序。一旦遇到 if,while,repeat,and,or就加1，
//  case语句中每一种情况就加1.


///////●●● 3.1.1 基本的type_traits

//1.简单的type_traits,直接从std::integral_constant派生

//template<typename type>
//struct A : std::integral_constant<int,6>
//{
//
//};

//2.类型判定的type_traits

//3.判断两个类型之间的关系的traits

//struct A
//{
//
//};
//struct B :public A
//{
//
//};
//struct C
//{
//
//};


//4.类型的转化traits

//移除和添加引用的例子
/*
template<class T>
struct Construct
{
	using U = typename std::remove_reference<T>::type;
	Construct():m_ptr(new U)
	{
		
	}
	typename std::add_lvalue_reference<U>::type GetObject() const
	{
		return *m_ptr.get();
	}

private:
	std::unique_ptr<U> m_ptr;

};
*/

//使用std::decay保存函数指针
/*
int test(int a)
{
	return a;
}
*/


///////●●● 3.1.2条件选择的traits


///////●●● 3.1.3 获取可调用对象返回类型的traits(std::result_of)

//class A
//{
//	A() = delete;
//public:
//	int operator()(int i)
//	{
//		return i;
//
//	}
//};

///////●●● 3.1.4根据条件禁用或者启动某些类型的traits

//1.限定返回值

//template<class T>
//typename std::enable_if<std::is_arithmetic<T>::value, T>::type foo(T t)
//{
//	return t;
//}

//2.限定模版入参类型

//template<class T>
//T foo(T t, typename std::enable_if <std::is_integral<T>::value,int>::type = 0)
//{
//	return t;
//}

//3.限定对模版参数T类型

//template<class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
//T foo(T t)
//{
//	return t;
//}


//4.模版特化时，限定模版参数

//template<class T,class Enable=void>
//class A;
//template<class T>
//class A < T, typename std::enable_if<std::is_floating_point<T>::value>::type>{};
//A<double> a;//正确
////A<int> b;   //错误

///////●●●●●● 3.2可变参数模版

//●1.递归函数方式展开参数包

//void f()
//{
//	cout << "结束递归" << endl;
//}
//template<class T,class ...Args>
//void f(T val,Args ...reset)
//{
//	cout <<val<< endl;
//	f(reset...);
//}

//●2.逗号表达式和初始化列表方式展开参数包

 /*
 template<class T>
 void f(T t)
 {
	 cout << t << endl;
 }
template<class ...Args>
void expand(Args...args)
{
	int arr[] = { (f(args),0)... };
}
*/


int main()
 {

	///////★★★★★★ 3.1 type_traits

	//★1.简单的type_traits

	/*A<int> a;
	cout << a.value << endl;*/

	//★2.类型判定的type_traits

	/*cout << "int:" << std::is_const<int>::value << endl;
	cout << "int&:" << std::is_const<int const>::value << endl;
	cout << "int const&:" << std::is_const<int const&>::value << endl;
	cout << "int const*:" << std::is_const<int const*>::value << endl;
	cout << "int *const:" << std::is_const<int*const>::value  << endl;*/


	//★3.判断两个类型之间的关系的traits
	
	//is_same的使用

	/*cout << std::is_same<int, int>::value << endl;
	cout << std::is_same<int, int&>::value << endl;
	cout << std::is_same<int, char>::value << endl;*/

   //is_base_of的使用（用来判断在编译期两个类型是否为继承关系）

	/*cout << std::is_base_of<A, B>::value << endl;
	cout << std::is_base_of<B, A>::value << endl;
	cout << std::is_base_of<A, C>::value << endl;*/

   //is_convertible的使用（用来判断前面的模版参数是否可以转化为后面的模版参数）

	/*cout << std::is_convertible<A*, B*>::value << endl;
	cout << std::is_convertible<B*, A*>::value << endl;
	cout << std::is_convertible<A*, C*>::value << endl;*/

	//★4.类型的转化traits

	//添加或者移除const，reference,pointer
	/*
	cout << std::is_same<const int, add_const<int>::type>::value << endl;
	cout << std::is_same<int, remove_const<int>::type>::value << endl;
	cout << std::is_same<int&, add_lvalue_reference<int>::type>::value << endl;
	cout << std::is_same<int&&, add_rvalue_reference<int>::type>::value << endl;
	cout << std::is_same<int, remove_reference<int&>::type>::value << endl;
	cout << std::is_same<int, remove_reference<int&&>::type>::value << endl;
	cout << std::is_same<int*, add_pointer<int>::type>::value << endl;
	cout << std::is_same<int, remove_pointer<int*>::type>::value << endl;
	*/
	//移除数组的顶层维度
	/*
	cout << std::is_same<int, remove_extent<int[]>::type>::value << endl;
	cout << std::is_same<int[5], remove_extent<int[][5]>::type>::value << endl;
	*/
	//移除数组的所有维度
	/*
	cout << std::is_same<int, remove_all_extents<int[][3][4]>::type>::value << endl;
	*/

	//移除带有cv符的引用类型（const,volatile),可用std::decay保存函数指针
	/*
	using A = std::decay<int>::type;        //int
	using B = std::decay<int&>::type;       //int
	using C = std::decay<int&&>::type;      //int
	using D = std::decay<int const&>::type; //int
	using E = std::decay<int[2]>::type;     //int*
	using F = std::decay<int(int)>::type;   //int(*)(int)	
	using pTr = typename std::decay<F>::type;
	F   pa = test;
	pTr pb = test;
	pa(77);
	pb(88);
	*/

	//取公共类型(怎么感觉放在最后面并且相同的才可以为1呢？有点小纠结）
	/*
	using NumericType=std::common_type<unsigned char, short, int>::type ;
	cout << std::is_same<int, NumericType>::value << endl;
	*/


	//移除和添加引用的例子
	/*
	Construct<int> c;
	int a = c.GetObject();
	cout << a << endl;
	*/
	

	///////★★★ 3.1.2 根据条件选择的traits(std::conditional)

	/*using A = std::conditional<true, int, double>::type;
	using B = std::conditional<false, unsigned int, char>::type;*/


	///////★★★ 3.1.3 获取可调用对象返回类型的traits(std::result_of)

	// std::declval可以获取任何对象的临时值，不管它有没有默认的构造函数
	// 但是其获取的临时值引用不可以用于求值，要结合decltype来推导类型。

   /* decltype(std::declval<A>()(std::declval<int>())) i = 66;
   cout << i << endl;*/
   //使用std::result_ofy
   /* std::result_of<A(int)>::type x = 77;
   cout << x << endl;*/

   ///////★★★ 3.1.4根据条件禁用或者启动某些类型的traits(std::enable_if)
    
   //★1.限定做返回值
   /*
   auto t1 = foo(1);
   auto t2 = foo(1.4);
   // auto t3 = foo("error");
   */
   //★2.限定模版定义
   //★3.限定对模版参数T类型
   //★4.模版特化时，限定模版参数

   ///////★★★★★★ 3.2可变参数模版
        
  ///////★★★3.2.1可变参数模版函数

   //★1.递归方式展开参数包

   /* 
    f(1,683, 212, 34);
   */
 
   //★2.逗号表达式和初始化列表方式展开参数包
   /*
   expand(1, 343, 656, 24);
   */

    cout << "开饭开饭" << endl;
	return 0;
}
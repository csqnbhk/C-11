/****************************************************************************

     function:该文件主要测试一下"深入C++11代码优化与工程级应用"
			  该书的第四章,回顾一下所学的知识点（全部内容来自该书）
	 author：Demon
	 Time  :2017/10/28

****************************************************************************/

#include<iostream>
#include<memory>
using namespace std;

//////●●●●●● 4.1 shared_ptr 共享的智能指针

///错误做法（重复析构例子）

//struct A
//{
//   shared_ptr<A> GetSelf()
//	{
//		return shared_ptr<A>(this);
//  }
//
//};

//正确做法（继承std::enable_shared_from_this<T>,返回其成员函数shared_from_this()，其实就是返回一个weak_ptr指针

//struct A :public std::enable_shared_from_this<A>
//{
//	std::shared_ptr<A> GetSelf()
//	{
//		return shared_from_this();
//	}
//};


//////●●●●●● 4.2 unique_ptr 独占的智能指针

//////●●●●●● 4.3 weak_ptr 弱引用智能指针

//weak_ptr解决循环引用问题

//struct B;
//struct A {
//	std::shared_ptr<B> bptr;
//	~A() { cout << "A is delete" << endl; }
//};
//
//struct B {
//	std::weak_ptr<A> aptr;
//	~B() { cout << "B is delete" << endl; }
//};


//////●●●●●● 4.4 通过智能指针管理第三方库分配的内存

//1.一般而言，第三方库返回的是原始指针,使用完后调用其释放接口

/*
     void*p=GetHandle()->Create();
	 GetHandle()->Release(p);

*/

//2.智能指针的使用，不显示去调用其释放接口

/*

  void*p=GetHandle()->Create()
  std::shared_ptr<void> sp(p,[this](void*p){ GetHandle()->Release(p);});
  
  做成一个通用函数
  std::shared_ptr<void> Guard(void*p)
  {
      return std::shared_ptr<void> sp(p,[this](void*p){GetHandle()->Release(p);});

  }
  //正确使用
  void*p=GetHandle()->Create();
  auto sp=Guard();
  //do something

  //★错误使用
   void*p=GetHandle()->Create();
   Guard(p);//●由于Guard()返回的是一个右值，如果不把这个右值赋值给一个指针，那么
           //  当Guard()语句结束后，将会导致指针p提前释放，后面就出现访问野指针了。
  //do something
  
  
 宏定义解决这个问题

 #define GUARD(P) std::shared_ptr<void> p##P(P,[](void*p){GetHandle()->Release(p);});
 void*p=CetHandle()->Create();
 GUARD(p);

*/

int main()
{

	////// ★★★★★★  4.1 shared_ptr

	///1.初始化

	/*
	std::shared_ptr<int> p(new int(6));
	std::shared_ptr<int> p1 = p;
	cout << "p =" << p  << endl;
	cout << "p1=" << p1 << endl;
	*/

	//2.获取原始指针（get)

	/*
	int*rPtr = p.get();
	cout << "p   =" <<  p    << endl;
	cout << "p1  =" <<  p1   << endl;
	cout << "rPtr=" <<  rPtr << endl;
	*/

	//3.指定删除器

	//删除指针
	/*{
		std::shared_ptr<int> p(new int(7), [](int*p) { delete p;cout << "删除指针" << endl;});
		cout << "p =" << p << endl;
		cout << "*p=" << *p << endl;
	}*/
	//删除数组指针
	/*{
		std::shared_ptr<int> p(new int[10], [](int*p) { delete[] p;cout << "删除数组指针" << endl;});
		cout << "p =" << p << endl;
		cout << "*p=" << *p << endl;
	}*/
	

	//4.使用shared_ptr注意问题
    
	/*
	   1.不要使用一个原始指针初始化多个shared_ptr
	   int*rPtr = new int(6);
	   std::shared_ptr<int> p(rPtr);
	   std::shared_ptr<int> p1(rPtr); //logic error

	   2.不能把一个原始指针直接赋值给一个智能指针
	   int*rPtr=new int(8);
	   std::shared_ptr<int> p=rPtr;

	   3.不要在函数的实参中创建智能指针
	   function(shared_ptr<int>(new int(5)),Max() );有缺陷,可能导致内存泄漏
	 
	   4.通过shared_from_this() 返回this指针，不要将this指针作为shared_ptr返回。
	     因为this指针本质是一个裸指针，可能导致重复析构。
     	shared_ptr<A> p1(new A);
		shared_ptr<A> p2 = p1->GetSelf();

		5.避免智能指针的循环引用，会导致内存泄漏。

    */

	
	/////// ★★★★★★ 4.2 unique_ptr

	//1.unique_ptr是独占型的智能指针，不和其它智能指针共享内部的指针。

	//  故不予许通过赋值把一个unique_ptr赋值给另一个unique_ptr
	//std::unique_ptr<int> p(new int(7));
	//错误写法
	//std::unique_ptr<int> p1 = p;
	//正确写法(转移所有权）
	//std::unique_ptr<int> p1 = std::move(p);

	//2.如果希望只有一个智能指针管理资源或者数组就用unique_ptr,
	//  如果希望多个智能指针管理同一个资源就用shared_ptr。

	/////// ★★★★★★ 4.3 weak_ptr

	//1.weak_ptr是用来监视shared_ptr的

	//它不能改变引用计数，也不管shared_ptr内部的指针。
	//  主要作用是监视shared_ptr的生命周期。（来判断shared_ptr管理的资源是否还存在）

	//2.use_count()使用

	/*
	shared_ptr<int> p(new int);
	shared_ptr<int> p1 = p;
	weak_ptr<int> wp = p;
	cout << "use_count()=" << wp.use_count() << endl;
	*/

	//3.expired()使用
	
	/*{
		shared_ptr<int> p(new int);
		weak_ptr<int> wp(p);
		if (wp.expired())
		cout << "wp指针监视资源已经释放" << endl;
		else
		cout << "wp指针监视资源没有释放" << endl;
	}*/

    //4.lock()使用
   
   /*
    shared_ptr<int> p(new int(88));
    weak_ptr<int> wp(p);
    if (wp.expired())
    cout << "资源已经释放" << endl;
    else
    cout << "资源为：" << *wp.lock() << endl;
	*wp.lock() = 34; //可以修改
	cout << "资源为：" << *wp.lock() << endl;
	cout << "原始资源:" << *p << endl;
   */

   //5.weak_ptr返回this指针

    //继承std::enable_shared_from_this<T>
    //返回其成员函数shared_from_this()，其实就是返回一个weak_ptr指针

  //6.weak_ptr解决循环引用问题

    /*
    std::shared_ptr<A> pa(new A);
    std::shared_ptr<B> pb(new B);
    pa->bptr = pb;
    pb->aptr = pa;
    */

   return 0;
}
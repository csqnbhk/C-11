/********************************************************************************************
    
	    ��cpp�ļ������ã��ع�һ�¡�����Ӧ��C++11�����Ż��빤�̼�Ӧ��"�ĵ�һ��
		author��Demon
		Time��2017/9/23

********************************************************************************************/
#include<iostream>
#include<vector>
#include<functional>
using namespace std;

////auto����

////1.�������ڷǾ�̬��Ա����
//struct Foo
//{
//	//auto var1 = 0;              //error:auto�������ڷǾ�̬��Ա����
//	static const auto var2 = 0;//OK��var2->static const int
//};
//
////2.�������ں�������
//void func(auto a = 1)//error���������ں�������
//{
//
//}
////3.�޷���������
//auto arr[2]= {0};//error���޷���������
//
////4.�޷�����ģ�����
//template<typename T>
//struct Bar {};
//
//Bar<int> bar;
//Bar<auto> bb = bar;//error���޷�����ģ�����




int main()
{

	//1.1�����Ƶ�

	///1.1.1 auto�����Ƶ�
	//auto x = 5;               //x :int
	//auto pi = new auto(1);    //pi:int*
	//const auto *v = &x,u=8;   //v:const int*,u:const int
	//static auto f = 0.4;      //y:double
	//
	//int y =1;
	//auto &a = y;//a:int &,auto:int
	//auto b = a; //b:int,auto:int(�����ʽ��һ������ʱ��auto�����������������
	//const auto c = 1; //c:int const 
	//auto d = c;      //d:int(�����ʽ�д���const��volatile����ʱ��auto��Ѹ�����������
	//const auto &g = y;//g:const int &
	//auto &h = g;      //h��const int&(��auto�����ý��ʱ��auto�Ƶ��������ʽ��const���ԣ�

	//����ʹ��auto

	//std::vector<int> vv;
	//vv.push_back(3);
	//vv.push_back(7);
	//for (auto it = vv.begin();it!= vv.end();it++)//�����ƶϵ�����������
	//{
	//	cout<<*it<< endl;
	//}


	///1.1.2 decltype�ؼ���

	//int  x = 0;
	//decltype(x+7) y = 1;  //y->int 
	//const int&i = x;
	//decltype(i) j = y; //j->const int &


	//1.��ʶ��������ʽ�Ƶ�

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
	//decltype(foo.x) d=0          //d->int������ʱ��ʽ


	////2.��������

	//int&func_int_r(void);             //��ֵ
	//int&&func_int_rr(void);           //xֵ
	//int func_int(void);              //����ֵ
	//const int&func_cint_r(void);
	//const int&&func_cint_rr(void);
	//const int func_cint(void);
    //�������
	//int x = 0;
	//decltype(func_int_r())  a1 = x; //a1->int&
	//decltype(func_int_rr()) b1 = 0; //b1->int&&
	//decltype(func_int())    c1 = 0; //c1->int
	//decltype(func_cint_r())  a2 = x;//a2->const int&
	//decltype(func_cint_rr()) b2 = 0;//b2->const int&&
	//decltype(func_cint())    c2 = 0;//c2->int(��Ϊ�������ص�int��һ������ֵ�����ڴ���ֵ��ֻ�������Ϳ���Я����const��volatile���޶�����
	//class Foo
	//{
	//	
	//};
	//const Foo func_cfoo(void);
	//decltype(func_cfoo()) ff = Foo();//ff->const Foo(��������ֵ��һ������ֵ�������Ϳ���Я����const��volatile���޶�������
	//3.�����ŵı��ʽ�ͼӷ�������ʽ
	//struct Foo1
	//{
	//	int x;
	//};
	//const Foo1 foo = Foo1();
	//
	//decltype(foo.x) a = 0;   //a->int
	//decltype((foo.x)) b = a; //b->const int&��foo.x��һ����ֵ����֪���ű��ʽҲ��һ����ֵ��
	//int n = 0, m = 0;
	//decltype(n + m) c = 0;   //c->int
	//decltype(n += m) d = c;//d->int&,n+=m����һ����ֵ


	///1.1.3�������ͺ����﷨��auto��decltype�Ľ��ʹ�ã�
    
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

///1.2 ģ���ϸ�ڸĽ�

 //1.2.1 ģ����Ҽ�����

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
//Foo<A<int>>::type xx;//c++11֧��ʹ��">>"���������ģ�c++98��֧�֣��ᱻ����Ϊ�����ơ�

 //ģ��ı���

//�ض���

//typedef unsigned int u_int;
//using u_int = unsigned int;
//
//typedef std::vector<int> v_int;
//using v_int = std::vector<int>;
//����
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

//1.2.3 ����ģ���Ĭ�ϲ���

//C++11֧�ֺ���ģ����Ĭ��ģ�����,����������C++98��֧��
//template<typename T=int>
//void f(void)
//{
//
//}

///1.3 �б��ʼ��

//1.3.1ͳһ�ĳ�ʼ��

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

//1.3.1 �б��ʼ����ʹ��ϸ��

//��������ĸ���Ǿۺ���Ϳ���ʹ�ó�ʼ���б�

//1.������һ����ͨ���顣
//2.������һ���ࡣ��Ҫ������������
     /*1.���û��Զ���Ĺ��캯��
	 2.��˽�л��߱����ķǾ�̬���ݳ�Ա
	 3.�޻���
	 4.���麯��
	 5.������{}��=ֱ�ӳ�ʼ���ķǾ�̬���ݳ�Ա*/
//3.����һ��������ԣ�ֻҪ��������һ����ͨ���飬���������Ԫ�ز���һ���ۺ����ͣ�������鱾��Ҳ��һ���ۺ����͡�

///1.3.3  ��ʼ���б�

// 1.3.1 ���ⳤ�ȵĳ�ʼ���б�

//int arr[]={1,2,3};//û��ָ�����ȣ��������ⳤ
//ʹ�� std::initializer_list�����������ģ��
//void f(std::initializer_list<int> L)
//{
//	for (auto it = L.begin();it != L.end();it++)
//	{
//		cout << *it << endl;
//	}
//}
//f({});
//f({ 1,2,456,787,33,8 });
//ʹ��std::initializer_listʹ�õ�һЩϸ��
//1.Ԫ�ر���Ϊͬ��
//2.ֻ��3����Ա�ӿڣ�size(),begin(),end()
//3.ֻ�������ʼ�����߸�ֵ
//ע�⣺std::initializer_list�����洢���б�Ԫ�ص����ö��ѡ����Բ�������ʹ��
  //   std::initializer_list<int> f(void)
  //  {
  //      int a=1,b=2;
  //      return {a+b};//a,b����ʱû�б�����
  //  }

//1.3.2 ��ֹ��������

//int a = 1.1;
//int b = { 1.1 }; //error:��ʼ���б�������������

///1.4 ���ڷ�Χ��forѭ��

//std::vector<int> arr;
//arr.push_back(55);
//arr.push_back(77);
//for (auto i : arr)//ð�ź���ı��ʽִֻ��һ��
//{
//	cout << i << endl;
//}


///1.5 std::function��bind����

//1.5.1 �ɵ��ö���

//1.��һ������ָ��
//2.��һ������operator������Ա����������󣨷º�����
//3.��һ���ɱ�ת��Ϊ����ָ��������
//4.��һ�����Ա��������ָ��
//����
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
//void(*func_ptr)(void) = &func;//����ָ��
//func_ptr();
//Foo foo;
//foo();//�º���
//Bar bar;
//bar();//�ɱ�ת��Ϊ����ָ��������
//void (A::*mem_func_ptr)(void) = &A::mem_func;//���Ա����ָ��
//int A::*mem_obj_ptr = &A::a_;//���Աָ��


//1.5.2 �ɵ��ö����װ�� std::function


return 0;
}

/******************************************************************************************
            function:���ļ���Ҫ����һ��"����C++11�����Ż��빤�̼�Ӧ��"(ȫ���������Ը��飩
			author:Demon
            Time:2017/10/28
*******************************************************************************************/
#include<windows.h>
#include<iostream>
#include<memory>
#include<type_traits>
using namespace std;

///////������� 3.1 type_traits ������ȡ

//1.Ȧ���Ӷȣ��Ӻ�����һ�п�ʼ��һֱ���¿�����һ������ if,while,repeat,and,or�ͼ�1��
//  case�����ÿһ������ͼ�1.


///////���� 3.1.1 ������type_traits

//1.�򵥵�type_traits,ֱ�Ӵ�std::integral_constant����

//template<typename type>
//struct A : std::integral_constant<int,6>
//{
//
//};

//2.�����ж���type_traits

//3.�ж���������֮��Ĺ�ϵ��traits

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


//4.���͵�ת��traits

//�Ƴ���������õ�����
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

//ʹ��std::decay���溯��ָ��
/*
int test(int a)
{
	return a;
}
*/


///////���� 3.1.2����ѡ���traits


///////���� 3.1.3 ��ȡ�ɵ��ö��󷵻����͵�traits(std::result_of)

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

///////���� 3.1.4�����������û�������ĳЩ���͵�traits

//1.�޶�����ֵ

//template<class T>
//typename std::enable_if<std::is_arithmetic<T>::value, T>::type foo(T t)
//{
//	return t;
//}

//2.�޶�ģ���������

//template<class T>
//T foo(T t, typename std::enable_if <std::is_integral<T>::value,int>::type = 0)
//{
//	return t;
//}

//3.�޶���ģ�����T����

//template<class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
//T foo(T t)
//{
//	return t;
//}


//4.ģ���ػ�ʱ���޶�ģ�����

//template<class T,class Enable=void>
//class A;
//template<class T>
//class A < T, typename std::enable_if<std::is_floating_point<T>::value>::type>{};
//A<double> a;//��ȷ
////A<int> b;   //����

///////������� 3.2�ɱ����ģ��

//��1.�ݹ麯����ʽչ��������

//void f()
//{
//	cout << "�����ݹ�" << endl;
//}
//template<class T,class ...Args>
//void f(T val,Args ...reset)
//{
//	cout <<val<< endl;
//	f(reset...);
//}

//��2.���ű��ʽ�ͳ�ʼ���б�ʽչ��������

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

	///////������� 3.1 type_traits

	//��1.�򵥵�type_traits

	/*A<int> a;
	cout << a.value << endl;*/

	//��2.�����ж���type_traits

	/*cout << "int:" << std::is_const<int>::value << endl;
	cout << "int&:" << std::is_const<int const>::value << endl;
	cout << "int const&:" << std::is_const<int const&>::value << endl;
	cout << "int const*:" << std::is_const<int const*>::value << endl;
	cout << "int *const:" << std::is_const<int*const>::value  << endl;*/


	//��3.�ж���������֮��Ĺ�ϵ��traits
	
	//is_same��ʹ��

	/*cout << std::is_same<int, int>::value << endl;
	cout << std::is_same<int, int&>::value << endl;
	cout << std::is_same<int, char>::value << endl;*/

   //is_base_of��ʹ�ã������ж��ڱ��������������Ƿ�Ϊ�̳й�ϵ��

	/*cout << std::is_base_of<A, B>::value << endl;
	cout << std::is_base_of<B, A>::value << endl;
	cout << std::is_base_of<A, C>::value << endl;*/

   //is_convertible��ʹ�ã������ж�ǰ���ģ������Ƿ����ת��Ϊ�����ģ�������

	/*cout << std::is_convertible<A*, B*>::value << endl;
	cout << std::is_convertible<B*, A*>::value << endl;
	cout << std::is_convertible<A*, C*>::value << endl;*/

	//��4.���͵�ת��traits

	//��ӻ����Ƴ�const��reference,pointer
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
	//�Ƴ�����Ķ���ά��
	/*
	cout << std::is_same<int, remove_extent<int[]>::type>::value << endl;
	cout << std::is_same<int[5], remove_extent<int[][5]>::type>::value << endl;
	*/
	//�Ƴ����������ά��
	/*
	cout << std::is_same<int, remove_all_extents<int[][3][4]>::type>::value << endl;
	*/

	//�Ƴ�����cv�����������ͣ�const,volatile),����std::decay���溯��ָ��
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

	//ȡ��������(��ô�о���������沢����ͬ�Ĳſ���Ϊ1�أ��е�С���ᣩ
	/*
	using NumericType=std::common_type<unsigned char, short, int>::type ;
	cout << std::is_same<int, NumericType>::value << endl;
	*/


	//�Ƴ���������õ�����
	/*
	Construct<int> c;
	int a = c.GetObject();
	cout << a << endl;
	*/
	

	///////���� 3.1.2 ��������ѡ���traits(std::conditional)

	/*using A = std::conditional<true, int, double>::type;
	using B = std::conditional<false, unsigned int, char>::type;*/


	///////���� 3.1.3 ��ȡ�ɵ��ö��󷵻����͵�traits(std::result_of)

	// std::declval���Ի�ȡ�κζ������ʱֵ����������û��Ĭ�ϵĹ��캯��
	// �������ȡ����ʱֵ���ò�����������ֵ��Ҫ���decltype���Ƶ����͡�

   /* decltype(std::declval<A>()(std::declval<int>())) i = 66;
   cout << i << endl;*/
   //ʹ��std::result_ofy
   /* std::result_of<A(int)>::type x = 77;
   cout << x << endl;*/

   ///////���� 3.1.4�����������û�������ĳЩ���͵�traits(std::enable_if)
    
   //��1.�޶�������ֵ
   /*
   auto t1 = foo(1);
   auto t2 = foo(1.4);
   // auto t3 = foo("error");
   */
   //��2.�޶�ģ�涨��
   //��3.�޶���ģ�����T����
   //��4.ģ���ػ�ʱ���޶�ģ�����

   ///////������� 3.2�ɱ����ģ��
        
  ///////����3.2.1�ɱ����ģ�溯��

   //��1.�ݹ鷽ʽչ��������

   /* 
    f(1,683, 212, 34);
   */
 
   //��2.���ű��ʽ�ͳ�ʼ���б�ʽչ��������
   /*
   expand(1, 343, 656, 24);
   */

    cout << "��������" << endl;
	return 0;
}
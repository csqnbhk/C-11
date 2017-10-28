/****************************************************************************

     function:���ļ���Ҫ����һ��"����C++11�����Ż��빤�̼�Ӧ��"
			  ����ĵ�����,�ع�һ����ѧ��֪ʶ�㣨ȫ���������Ը��飩
	 author��Demon
	 Time  :2017/10/28

****************************************************************************/

#include<iostream>
#include<memory>
using namespace std;

//////������� 4.1 shared_ptr ���������ָ��

///�����������ظ��������ӣ�

//struct A
//{
//   shared_ptr<A> GetSelf()
//	{
//		return shared_ptr<A>(this);
//  }
//
//};

//��ȷ�������̳�std::enable_shared_from_this<T>,�������Ա����shared_from_this()����ʵ���Ƿ���һ��weak_ptrָ��

//struct A :public std::enable_shared_from_this<A>
//{
//	std::shared_ptr<A> GetSelf()
//	{
//		return shared_from_this();
//	}
//};


//////������� 4.2 unique_ptr ��ռ������ָ��

//////������� 4.3 weak_ptr ����������ָ��

//weak_ptr���ѭ����������

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


//////������� 4.4 ͨ������ָ�����������������ڴ�

//1.һ����ԣ��������ⷵ�ص���ԭʼָ��,ʹ�����������ͷŽӿ�

/*
     void*p=GetHandle()->Create();
	 GetHandle()->Release(p);

*/

//2.����ָ���ʹ�ã�����ʾȥ�������ͷŽӿ�

/*

  void*p=GetHandle()->Create()
  std::shared_ptr<void> sp(p,[this](void*p){ GetHandle()->Release(p);});
  
  ����һ��ͨ�ú���
  std::shared_ptr<void> Guard(void*p)
  {
      return std::shared_ptr<void> sp(p,[this](void*p){GetHandle()->Release(p);});

  }
  //��ȷʹ��
  void*p=GetHandle()->Create();
  auto sp=Guard();
  //do something

  //�����ʹ��
   void*p=GetHandle()->Create();
   Guard(p);//������Guard()���ص���һ����ֵ��������������ֵ��ֵ��һ��ָ�룬��ô
           //  ��Guard()�������󣬽��ᵼ��ָ��p��ǰ�ͷţ�����ͳ��ַ���Ұָ���ˡ�
  //do something
  
  
 �궨�����������

 #define GUARD(P) std::shared_ptr<void> p##P(P,[](void*p){GetHandle()->Release(p);});
 void*p=CetHandle()->Create();
 GUARD(p);

*/

int main()
{

	////// �������  4.1 shared_ptr

	///1.��ʼ��

	/*
	std::shared_ptr<int> p(new int(6));
	std::shared_ptr<int> p1 = p;
	cout << "p =" << p  << endl;
	cout << "p1=" << p1 << endl;
	*/

	//2.��ȡԭʼָ�루get)

	/*
	int*rPtr = p.get();
	cout << "p   =" <<  p    << endl;
	cout << "p1  =" <<  p1   << endl;
	cout << "rPtr=" <<  rPtr << endl;
	*/

	//3.ָ��ɾ����

	//ɾ��ָ��
	/*{
		std::shared_ptr<int> p(new int(7), [](int*p) { delete p;cout << "ɾ��ָ��" << endl;});
		cout << "p =" << p << endl;
		cout << "*p=" << *p << endl;
	}*/
	//ɾ������ָ��
	/*{
		std::shared_ptr<int> p(new int[10], [](int*p) { delete[] p;cout << "ɾ������ָ��" << endl;});
		cout << "p =" << p << endl;
		cout << "*p=" << *p << endl;
	}*/
	

	//4.ʹ��shared_ptrע������
    
	/*
	   1.��Ҫʹ��һ��ԭʼָ���ʼ�����shared_ptr
	   int*rPtr = new int(6);
	   std::shared_ptr<int> p(rPtr);
	   std::shared_ptr<int> p1(rPtr); //logic error

	   2.���ܰ�һ��ԭʼָ��ֱ�Ӹ�ֵ��һ������ָ��
	   int*rPtr=new int(8);
	   std::shared_ptr<int> p=rPtr;

	   3.��Ҫ�ں�����ʵ���д�������ָ��
	   function(shared_ptr<int>(new int(5)),Max() );��ȱ��,���ܵ����ڴ�й©
	 
	   4.ͨ��shared_from_this() ����thisָ�룬��Ҫ��thisָ����Ϊshared_ptr���ء�
	     ��Ϊthisָ�뱾����һ����ָ�룬���ܵ����ظ�������
     	shared_ptr<A> p1(new A);
		shared_ptr<A> p2 = p1->GetSelf();

		5.��������ָ���ѭ�����ã��ᵼ���ڴ�й©��

    */

	
	/////// ������� 4.2 unique_ptr

	//1.unique_ptr�Ƕ�ռ�͵�����ָ�룬������������ָ�빲���ڲ���ָ�롣

	//  �ʲ�����ͨ����ֵ��һ��unique_ptr��ֵ����һ��unique_ptr
	//std::unique_ptr<int> p(new int(7));
	//����д��
	//std::unique_ptr<int> p1 = p;
	//��ȷд��(ת������Ȩ��
	//std::unique_ptr<int> p1 = std::move(p);

	//2.���ϣ��ֻ��һ������ָ�������Դ�����������unique_ptr,
	//  ���ϣ���������ָ�����ͬһ����Դ����shared_ptr��

	/////// ������� 4.3 weak_ptr

	//1.weak_ptr����������shared_ptr��

	//�����ܸı����ü�����Ҳ����shared_ptr�ڲ���ָ�롣
	//  ��Ҫ�����Ǽ���shared_ptr���������ڡ������ж�shared_ptr�������Դ�Ƿ񻹴��ڣ�

	//2.use_count()ʹ��

	/*
	shared_ptr<int> p(new int);
	shared_ptr<int> p1 = p;
	weak_ptr<int> wp = p;
	cout << "use_count()=" << wp.use_count() << endl;
	*/

	//3.expired()ʹ��
	
	/*{
		shared_ptr<int> p(new int);
		weak_ptr<int> wp(p);
		if (wp.expired())
		cout << "wpָ�������Դ�Ѿ��ͷ�" << endl;
		else
		cout << "wpָ�������Դû���ͷ�" << endl;
	}*/

    //4.lock()ʹ��
   
   /*
    shared_ptr<int> p(new int(88));
    weak_ptr<int> wp(p);
    if (wp.expired())
    cout << "��Դ�Ѿ��ͷ�" << endl;
    else
    cout << "��ԴΪ��" << *wp.lock() << endl;
	*wp.lock() = 34; //�����޸�
	cout << "��ԴΪ��" << *wp.lock() << endl;
	cout << "ԭʼ��Դ:" << *p << endl;
   */

   //5.weak_ptr����thisָ��

    //�̳�std::enable_shared_from_this<T>
    //�������Ա����shared_from_this()����ʵ���Ƿ���һ��weak_ptrָ��

  //6.weak_ptr���ѭ����������

    /*
    std::shared_ptr<A> pa(new A);
    std::shared_ptr<B> pb(new B);
    pa->bptr = pb;
    pb->aptr = pa;
    */

   return 0;
}
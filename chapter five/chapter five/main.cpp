/**************************************************************************************

               function:���ļ���������һ��"����Ӧ��C++11�����Ż��빤�̼�Ӧ��"�����£�
			            �ع�һ����ѧ��֪ʶ�㡣������¼��(ȫ�����ݾ����Ը��飩
			   author��Demon
			   Time:2017/10/25
****************************************************************************************/
#include<iostream>
#include<windows.h>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<atomic>
#include<list>
using namespace std;
//int Max(int a,int b)
//{
//	std::this_thread::sleep_for(std::chrono::seconds(3));//�߳�˯��
//	if (a > b)
//	{
//		cout << "a>b" << endl;
//		return a;
//	}
//	else
//	{
//		cout << "b>a" << endl;
//		return b;
//	}
//	
//}

///////std::mutexʹ��

//std::mutex g_lock;
//void func()
//{
//	g_lock.lock();
//	cout << "enter thread,thread id:" << std::this_thread::get_id() << endl;
//	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//	g_lock.unlock();
//}

//////std::recursive_mutex���ݹ�����ͬһ�߳̿ɶ�λ�ȡ�û�������

//struct Complex
//{
//	std::recursive_mutex mutex;
//	int i;
//	Complex() :i(0) {}
//
//	void mul(int x)
//	{
//		
//		std::lock_guard<std::recursive_mutex> lock(mutex);
//		cout << "mul()����" << endl;
//		i *= x;
//	}
//	void div(int x)
//	{
//		std::lock_guard<std::recursive_mutex> lock(mutex);
//		cout << "div()����" << endl;
//		i /= x;
//	}
//	void both(int x, int y)
//	{		
//    	std::lock_guard<std::recursive_mutex> lock(mutex);
//		cout << "both����" << endl;
//		mul(x);
//		div(y);
//	}
//};

//////std::time_mutex ����ʱ����ʹ��

//std::timed_mutex t_mutex;
//void work()
//{
//	std::chrono::milliseconds timeout(100);
//	while (true)
//	{
//		if (t_mutex.try_lock_for(timeout))
//		{
//			cout << std::this_thread::get_id() << ":do work with the mutex" << endl;
//			std::chrono::milliseconds sleepDuration(3000);
//			std::this_thread::sleep_for(sleepDuration);
//			t_mutex.unlock();
//			std::this_thread::sleep_for(sleepDuration);
//		}
//		else
//		{
//			cout << std::this_thread::get_id() << ":do work without mutex" << endl;
//			std::chrono::milliseconds sleepDuration(1000);
//			std::this_thread::sleep_for(sleepDuration);
//		}
//
//	}
//
//}

//////�����������������Ľ��ʹ�ã�ͬ�����е�ʵ�֣�

//class SyncQueue
//
//{
//public:
//	SyncQueue():m_maxSize(2)
//	{
//		
//	}
//public:
//	void Put(int const &x)
//	{
//		int temp = x;
//		std::unique_lock<std::mutex> locker(m_mutex);
//		m_notFull.wait(locker, [this] { return !this->Full();});
// 		m_queue.push_back(x);
//		cout << "ѹ������:" << x << endl;
//		m_notEmpty.notify_one();
//
//    }
//	void Take(int &x)
//	{
//		std::unique_lock<std::mutex> locker(m_mutex);
//		m_notEmpty.wait(locker, [this] { return !m_queue.empty();});
//		x = m_queue.front();
//		m_queue.pop_front();
//		cout << "��ȡ����:" <<x<< endl;
//		m_notFull.notify_one();
//	}
//
//public:
//	bool Full()
//	{
//		return m_queue.size()==m_maxSize;
//	}
//
//private:
//	std::list<int> m_queue;
//	std::mutex   m_mutex;
//	std::condition_variable m_notEmpty;
//	std::condition_variable m_notFull;
//	int m_maxSize;
//
//};
//
//void PutWork()
//{
//	static int i = 0;
//	while (true)
//	{
//
//		a.Put(i);
//		i++;
//		Sleep(1000);
//	}
//	
//}
//void TakeWork()
//{
//	static int j = 0;
//	while (true)
//	{
//		a.Take(j);
//		Sleep(3000);
//	}
//
//}

//////std::atomic<T> ԭ�ӱ���

//std::atomic<int> a=0;
//void Add()
//{
//	while (a < 8889999)
//     ++a;
//}

//////std::call_once/once_flagʹ��

//std::once_flag once;
//void do_once()
//{
//	std::call_once(once, []{ cout << "Called once" << endl;});
//}

int main()
{
	//1.1�̵߳Ĵ���(ע��:�̺߳���Ҫ���̶߳������������������(��ʱ�̶߳���û�к��̺߳���detach������������
	/*
	std::thread t(Max, 2, 4);
	cout << "�߳�ID:" << t.get_id() << endl;
	cout << "CPU������:" << std::thread::hardware_concurrency() << endl;
	*/
	//t.join();   //�����߳�ֱ���߳�������
	//t.detach();//�����̶߳�����̺߳������Ժ󲻿�����ʹ�ø��̶߳���ȥ�����̺߳�������ϣ���߳�����ִ�У�


	//1.2 �������������߳�ͬ����,����

	//sdt::mutex
	//std::timed_mutex
	//std::recursive_mutex
    //std::recursive_mutex

    //////std::mutex ʹ��
	/*std::thread t1(func);
	std::thread t2(func);
	std::thread t3(func);*/

	//////std::recursive_mutex ʹ��
	/*
	Complex complex;
	complex.both(12,6);
	*/

	//////std::timed_mutex ����ʱ����ʹ��
	/*
	std::thread t1(work);
	std::thread t2(work
	*/
	


	///////1.3 ���������������߳�ͨ�ţ�������

	//condition_variable     ���std::unique_lock<std::mutex>����wait
	//condition_variable_any ���������lock��unlock�����mutex���ʹ�ã��Ƚ�����Ч�ʱ�condition_variable�ϲ�һ��
	
	///////1.4���������ͻ������Ľ��ʹ�ã��ر�ע�⣬һ����Ҫ������
	/*
	std::thread t1(PutWork);
	std::thread t2(TakeWork);
	*/

	//////1.5 ԭ�ӱ�����ʹ�ã�std::atomic<T>)

	//std::thread t1(Add);
	//std::thread t2(Add);
	//t1.join();
	//t2.join();
	//std::cout<< "a=" << a.load() << endl;//(û���߳�ͬ�����ᵼ�����ݲ�׼ȷ)ֻ�ǲ���
	

	///////1.6 call_once/once_flag ��ʹ��

	/*
	std::thread t1(do_once);
	std::thread t2(do_once);
	std::thread t3(do_once);
	*/

	while (1);
	return 0;
}
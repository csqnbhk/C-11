/******************************************************************************
      function:���ļ���Ҫ����һ��"����Ӧ��C++11�����Ż��빤�̼�Ӧ��"
	           �ĵ����¼���֪ʶ�㣨ȫ���������Ը��飩
      author��Demon
	  Time:2017/10/29
	  ע�������ڴ淽���֪ʶ�㣬�´��ܽ�һ�²��С���֪ʶ���е�࣬Ҳ�е��ң�
******************************************************************************/

#include<iostream>
#include<string>
#include<codecvt>
using namespace std;

//��ί�й��캯��
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

//��̳й��캯��
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

//��final
/*
struct A 
{
	virtual void test()final{}
};
struct B :A
{
	//virtual void test(){}//���󣬲�����д
};
*/
//struct B final
//{
//
//};
//struct C :B//�����÷�
//{
//
//};
//��override
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
	//����ֵ����ת�ַ�����to_string)
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
	
	//���ַ���תΪ���ͺ͸�����(atoi,atol,atoll,atof)
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

	//���խ�ַ�ת����wstring_convert)
	/*
	string str = "�ԳƳ��Ǿ�����";
	wstring wstr = L"��������ѩ";

	wstring_convert<std::codecvt<wchar_t, char, std::mbstate_t>>
	converter(new std::codecvt<wchar_t, char, std::mbstate_t>("CHS"));

	string tempStr = converter.to_bytes(wstr);
	cout << tempStr << endl;

	wstring tempWstr = converter.from_bytes(str);
	wcout.imbue(std::locale("chs"));
	wcout << tempWstr << endl;
    */

    //��ί�й��캯����ͬһ�����У�һ�����캯��������һ�����캯����
	/*
	//ע�⣺1.����ί�й��캯����������ʹ�����Ա��ʼ���ˡ�
	//      2.���캯���������γ�һ������
	 A a(12,16);
	*/

	//��̳й��캯��
	/*
	B b(223);
	B b1(12, 16);
	B b2(23);
	cout << b.x << "  " << b.y << "  " << b.z << endl;
	cout << b1.x << "  " << b1.y << "  " << b1.z << endl;
	cout << b2.x << "  " << b2.y << "  " << b2.z << endl;
	*/

	//��ԭʼ������(R)
	/*
	char const*str = R"(C:\Users\Public\Desktop\QQ����.lnk)";
	cout << str<< endl;
	*/

	//��final(final����������ʾĳ���಻�ܱ��̳У�����ĳ���麯�����ܱ���д��

	//��override(ȷ��������������д�ͻ�����ͬǩ���ĺ�������ֹ����д�����ȥ���أ�

	return 0;
}
#include "stdafx.h"
#include "UTest.h"
using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace	Microsoft::VisualStudio::TestTools::UnitTesting;

namespace Test1
{
	[TestClass]
	public ref class UnitTest1
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///��ȡ�����ò��������ģ����������ṩ
		///�йص�ǰ�������м��书�ܵ���Ϣ��
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//��д����ʱ������ʹ�����¸�������:
		//
		//���������еĵ�һ������֮ǰ��ʹ�� ClassInitialize �����д���
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//�����е����в��Զ�������֮��ʹ�� ClassCleanup �����д���
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//������ÿ������֮ǰ��ʹ�� TestInitialize �����д���
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//��ÿ������������֮��ʹ�� TestCleanup �����д���
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

		[TestMethod]
		void TestMethod1()
		{
			//
			// TODO: �ڴ�	��Ӳ����߼�
			//
			Assert::AreEqual(lastMap(1,3),1);
			Assert::AreEqual(lastMap(0,3),1);
			Assert::AreEqual(lastMap(1,2),1);
			Assert::AreEqual(lastMap(0,2),0);
			Assert::AreEqual(lastMap(1,1),0);
			Assert::AreEqual(lastMap(0,1),0);	

		};
	};
}

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Project20/App.cpp"
#include "../Project20/DeviceDriver.cpp"
#include "../Project20/FlashMemoryDevice.h"

using namespace std;
using namespace testing;

class MockDevice : public FlashMemoryDevice
{
public:
	MOCK_METHOD(unsigned char, read, (long address), (override));
	MOCK_METHOD(void, write, (long address, unsigned char data), (override));
};


TEST(TestCaseName, TestNameFiveRead)
{
	// �뿪 
	MockDevice mock_device;

	// ���ͺ� or Behavior ����
	EXPECT_CALL(mock_device, read).Times(5);

	DeviceDriver driver(&mock_device);
	driver.read(0xA);
}
TEST(TestCaseName, Exception)
{
	// �뿪 
	MockDevice mock_device;

	// ���ͺ� or Behavior ����
	EXPECT_CALL(mock_device, read(0x2))
		.WillOnce(Return(0x7))
		.WillOnce(Return(0x7))
		.WillOnce(Return(0x7))
		.WillOnce(Return(0x7))
		.WillOnce(Return(0x7));

	DeviceDriver driver(&mock_device);
	driver.read(0x2);
}

TEST(TestCaseName, TestNameFiveWrite)
{
	MockDevice mock_device;
	EXPECT_CALL(mock_device, write(0x0, 0x01));
	EXPECT_CALL(mock_device, write(0x1, 0x02));
	EXPECT_CALL(mock_device, write(0x2, 0x03));
	EXPECT_CALL(mock_device, write(0x3, 0x04));
	EXPECT_CALL(mock_device, write(0x4, 0x05));

	EXPECT_CALL(mock_device, read(0x0))
		.WillOnce(Return(0xFF));
	EXPECT_CALL(mock_device, read(0x1))
		.WillOnce(Return(0xFF));
	EXPECT_CALL(mock_device, read(0x2))
		.WillOnce(Return(0xFF));
	EXPECT_CALL(mock_device, read(0x3))
		.WillOnce(Return(0xFF));
	EXPECT_CALL(mock_device, read(0x4))
		.WillOnce(Return(0xFF));


	DeviceDriver driver(&mock_device);
	driver.write(0x0, 0x1);
	driver.write(0x1, 0x2);
	driver.write(0x2, 0x3);
	driver.write(0x3, 0x4);
	driver.write(0x4, 0x5);
}

TEST(TestCaseName, ExceptionWrite)
{
	MockDevice mock_device;
	EXPECT_CALL(mock_device, write(0x0, 0x01));
	EXPECT_CALL(mock_device, write(0x1, 0x02));

	EXPECT_CALL(mock_device, read(0x0))
		.WillOnce(Return(0xFF));
	EXPECT_CALL(mock_device, read(0x1))
		.WillOnce(Return(0xFF));

	DeviceDriver driver(&mock_device);
	driver.write(0x0, 0x1);
	driver.write(0x1, 0x2);

}






TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);


	// Driver�� �Ʒ�ó�� ����
	// 5�� �õ��� ��� ���� ���̸� ����
	// �ϳ��� �̻��ϸ� EX

	// 0XA�� 77�� ������,
	// ���� 1ȸ �о
	// �ݵ�� 0xFF�� ������ ���� ����.
	// �ƴϸ���� Exception


	// Application
	// ReadAndPrint(startAddr, endAddr
	// startAddr~endAddr���� Read������ ��� ���
	// 5��?

	// WriteAll(Value)
	// 0x00~0x04���� ��� value������ write�Ѵ�.
	// 5ȸ read�ϰ� 5ȸ write�Ѵ�
	// �ֳ��ϸ� 0x00~0x04���� �ѹ��� read and write�ϱ� ������. 
}
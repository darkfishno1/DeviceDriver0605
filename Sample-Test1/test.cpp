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
	// 대역 
	MockDevice mock_device;

	// 스터빙 or Behavior 검증
	EXPECT_CALL(mock_device, read).Times(5);

	DeviceDriver driver(&mock_device);
	driver.read(0xA);
}
TEST(TestCaseName, Exception)
{
	// 대역 
	MockDevice mock_device;

	// 스터빙 or Behavior 검증
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


	// Driver는 아래처럼 구현
	// 5번 시도중 모두 같은 값이면 정상
	// 하나라도 이상하면 EX

	// 0XA에 77을 적기전,
	// 먼저 1회 읽어봄
	// 반드시 0xFF가 읽혀야 쓸수 있음.
	// 아니며ㅑㄴ Exception


	// Application
	// ReadAndPrint(startAddr, endAddr
	// startAddr~endAddr까지 Read수행후 결과 출력
	// 5번?

	// WriteAll(Value)
	// 0x00~0x04까지 모두 value값으로 write한다.
	// 5회 read하고 5회 write한다
	// 왜냐하면 0x00~0x04까지 한번씩 read and write하기 때문임. 
}
#include <iostream>

using namespace std;

enum EnTableItem
{
	enOrderNumber = 1 << 1,			//订单号
	enOrderCreateGuy = 1 << 2,		//订单创建人员
	enOrderDebugGuy = 1 << 3,		//订单调试人员
	enOrderOperator = 1 << 4,		//操作人员
	enOrderCaliState = 1 << 5,		//校正状态
	enOrderStart = 1 << 6,			//开始时间
	enOrderEnd = 1 << 7,			//结束时间
	enOrderNote = 1 << 8,			//备注信息

	enUserName = 1 << 9,			//用户名
	enUserAdminPower = 1 << 10,		//用户管理权限
	enDataAdminPower = 1 << 11,		//数据管理权限
	enCaliDebugPower = 1 << 12,		//校正效果调试权限
	enPadMinitorPower = 1 << 13,	//操作平台监控权限
};

int main()
{
		for (EnTableItem(s) = enOrderNumber; s <= enPadMinitorPower; s = (EnTableItem)(s << 1))
		{
			// printf("%d \n",s);
            cout << s << '\n';
		}
        bool a;
        cout << a << '\n';
        a = 2 & enUserName;
        cout << a << '\n';
}
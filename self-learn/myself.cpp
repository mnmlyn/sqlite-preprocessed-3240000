#include"../src-preprocessed/sqlite3.h"
#include<stdio.h>

extern int firsttest();
extern int CoreAPITest();

int main()
{
	/* ��һ�����ԣ����Ա��뻷��������SQLite��API */
	//firsttest();

	/* �ڶ������ԣ��Ķ���file:///D:/sqlite_sourcecode/sqlite-doc-3240000/cintro.html֮��
	   ����ĵ��н�����SQLite��C/C++��̵ĺ���API��������Щ����API
	*/
	CoreAPITest();

	getchar();
	return 0;
}

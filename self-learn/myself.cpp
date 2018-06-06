#include"../src-preprocessed/sqlite3.h"
#include<stdio.h>

extern int firsttest();
extern int CoreAPITest();

int main()
{
	/* 第一个测试，测试编译环境，测试SQLite的API */
	//firsttest();

	/* 第二个测试，阅读了file:///D:/sqlite_sourcecode/sqlite-doc-3240000/cintro.html之后
	   这个文档中介绍了SQLite的C/C++编程的核心API。测试这些核心API
	*/
	CoreAPITest();

	getchar();
	return 0;
}

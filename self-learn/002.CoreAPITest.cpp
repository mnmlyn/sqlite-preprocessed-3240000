/*
* 看了file:///D:/sqlite_sourcecode/sqlite-doc-3240000/cintro.html
* 非常走心的关于C/C++的SQLite核心API的介绍
* 这里参照这些介绍，来做测试
*/

#include"../src-preprocessed/sqlite3.h"
#include<iostream>

/* 第二个测试，阅读了file:///D:/sqlite_sourcecode/sqlite-doc-3240000/cintro.html之后
这个文档中介绍了SQLite的C/C++编程的核心API。测试这些核心API
*/
int CoreAPITest()
{
	using std::cout;
	using std::endl;

	sqlite3 *db;//数据库连接
	sqlite3_stmt *stmt;//数据库已处理语句
	int rc;//返回值编码
	char *sql;//SQL语句
	const char *pzTail;//指向未执行的SQL语句

	rc = sqlite3_open("./testDB/002.test.db", &db);//打开或创建数据库文件，返回数据库连接db
	if (rc != SQLITE_OK)
	{
		cout << "open ERROR" << endl;
		return 1;
	}

	sql = "insert into student (id,name) values(1,'min');";
	rc = sqlite3_prepare(db, sql, strlen(sql), &stmt, &pzTail);
	rc = sqlite3_step(stmt);
	if (rc != SQLITE_DONE)
	{
		cout << "insert ERROR" << endl;
	}
	sqlite3_finalize(stmt);//销毁已处理语句

	sql = "select * from student;";//SQL语句
	rc = sqlite3_prepare(db, sql, strlen(sql), &stmt, &pzTail);//对SQL语句进行编译（处理），返回已处理语句stmt
	if (rc != SQLITE_OK)
	{
		sqlite3_close(db);//关闭数据库连接
		return 2;
	}

	int fieldNum = sqlite3_column_count(stmt);//得到已处理语句的结果字段数量
	rc = sqlite3_step(stmt);//执行SQL
	if (rc == SQLITE_ROW)//SQLITE_ROW代表sqlite3_step()函数得到了一行新的结果
	{
		do
		{
			for (int i = 0; i < fieldNum; i++)
			{
				int ftype = sqlite3_column_type(stmt, i);//得到stmt的第i列结果的数据类型
				if (ftype == SQLITE_INTEGER)
					cout << sqlite3_column_int(stmt, i) << "\t";
				else if (ftype == SQLITE_TEXT)
					cout << sqlite3_column_text(stmt, i) << "\t";
			}
			cout << endl;
			rc = sqlite3_step(stmt);//执行SQL
		} while (rc == SQLITE_ROW);//有新行，继续循环
	}
	else if (rc == SQLITE_DONE)//SQLITE_DONE代表sqlite3_step()函数结束执行
	{
		cout << "查询到0个结果" << endl;
	}

	sqlite3_finalize(stmt);//销毁已处理语句stmt
	sqlite3_close(db);//断开数据库连接db
	return 0;
}
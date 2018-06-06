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
	sqlite3 *db;
	int rc;
	rc = sqlite3_open("./testDB/002.test.db", &db);

	sqlite3_stmt *stmt;
	char *sql = "select * from student;";
	const char *p;

	sqlite3_prepare(db, sql, strlen(sql), &stmt, &p);

	int fieldNum = sqlite3_column_count(stmt);
	rc = sqlite3_step(stmt);//执行SQL
	if (rc == SQLITE_ROW)
	{
		for (int i = 0; i < fieldNum; i++)
		{
			int ftype = sqlite3_column_type(stmt, i);
			if (ftype == SQLITE_INTEGER)
				cout << sqlite3_column_int(stmt, i) << endl;
			else if (ftype == SQLITE_TEXT)
				cout << sqlite3_column_text(stmt, i) << endl;
		}
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return 0;
}
/*
* ����file:///D:/sqlite_sourcecode/sqlite-doc-3240000/cintro.html
* �ǳ����ĵĹ���C/C++��SQLite����API�Ľ���
* ���������Щ���ܣ���������
*/

#include"../src-preprocessed/sqlite3.h"
#include<iostream>

/* �ڶ������ԣ��Ķ���file:///D:/sqlite_sourcecode/sqlite-doc-3240000/cintro.html֮��
����ĵ��н�����SQLite��C/C++��̵ĺ���API��������Щ����API
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
	rc = sqlite3_step(stmt);//ִ��SQL
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
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

	sqlite3 *db;//���ݿ�����
	sqlite3_stmt *stmt;//���ݿ��Ѵ������
	int rc;//����ֵ����
	char *sql;//SQL���
	const char *pzTail;//ָ��δִ�е�SQL���

	rc = sqlite3_open("./testDB/002.test.db", &db);//�򿪻򴴽����ݿ��ļ����������ݿ�����db
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
	sqlite3_finalize(stmt);//�����Ѵ������

	sql = "select * from student;";//SQL���
	rc = sqlite3_prepare(db, sql, strlen(sql), &stmt, &pzTail);//��SQL�����б��루�����������Ѵ������stmt
	if (rc != SQLITE_OK)
	{
		sqlite3_close(db);//�ر����ݿ�����
		return 2;
	}

	int fieldNum = sqlite3_column_count(stmt);//�õ��Ѵ������Ľ���ֶ�����
	rc = sqlite3_step(stmt);//ִ��SQL
	if (rc == SQLITE_ROW)//SQLITE_ROW����sqlite3_step()�����õ���һ���µĽ��
	{
		do
		{
			for (int i = 0; i < fieldNum; i++)
			{
				int ftype = sqlite3_column_type(stmt, i);//�õ�stmt�ĵ�i�н������������
				if (ftype == SQLITE_INTEGER)
					cout << sqlite3_column_int(stmt, i) << "\t";
				else if (ftype == SQLITE_TEXT)
					cout << sqlite3_column_text(stmt, i) << "\t";
			}
			cout << endl;
			rc = sqlite3_step(stmt);//ִ��SQL
		} while (rc == SQLITE_ROW);//�����У�����ѭ��
	}
	else if (rc == SQLITE_DONE)//SQLITE_DONE����sqlite3_step()��������ִ��
	{
		cout << "��ѯ��0�����" << endl;
	}

	sqlite3_finalize(stmt);//�����Ѵ������stmt
	sqlite3_close(db);//�Ͽ����ݿ�����db
	return 0;
}
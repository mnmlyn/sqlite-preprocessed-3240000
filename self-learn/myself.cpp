#include"../src-preprocessed/sqlite3.h"
#include<stdio.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");

	}
   printf("\n");
   return 0;
}


int main()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open("test.db", &db);
	rc = sqlite3_exec(db, "create table student(id int primary key,name char(10));", callback, 0, &zErrMsg);
	rc = sqlite3_exec(db, "insert into student(id,name) values(2,'gao');", callback, 0, &zErrMsg);
	rc = sqlite3_exec(db, "select * from student;", callback, 0, &zErrMsg);

	sqlite3_close(db);

	getchar();
	return 0;
}

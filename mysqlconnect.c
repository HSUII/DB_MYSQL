#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv)
{
        MYSQL *conn;
        MYSQL_RES *result;
        MYSQL_ROW row;

        char query_buffer[2048];

        conn = mysql_init(NULL);

        if(!mysql_real_connect(conn, "localhost", "사용자", ".비밀번호", NULL, 0, NULL, 0)){
                printf("cannot connect");
                exit(1);
        }
        else{
                if (mysql_select_db(conn, "데이터베이스명")){
                        printf("cannot use databases");
                        exit(1);
                }
        }

        sprintf(query_buffer, "%s", "show tables");
        if (mysql_query(conn, query_buffer)){
                printf("query faild : %s\n", query_buffer);
                exit(1);
        }

        result = mysql_use_result(conn);
        while ((row = mysql_fetch_row(result)) != NULL)
                printf("%s \n", row[0]);

        mysql_free_result(result);
        mysql_close(conn);

}


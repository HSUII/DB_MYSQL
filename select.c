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

        int qnum = 10;

        conn = mysql_init(NULL);

        if(!mysql_real_connect(conn, "127.0.0.1", "root", ".dlfndhs", NULL, 0, NULL, 0)){
                printf("cannot connect");
                exit(1);
        }
        else{
                if (mysql_select_db(conn, "hsdb")){
                        printf("cannot use databases");
                        exit(1);
                }
        }
        printf("table목록: 1 , table 출력: 2, 데이터베이스 종료: 0 \n");


        while(qnum!=0){

        printf("숫자를 입력하세요 : ");
        scanf("%d",&qnum);

        if(qnum=1)
        {
                 sprintf(query_buffer, "%s", "show tables");
         }
        if(qnum=2){

                 sprintf(query_buffer, "%s", "select * from human");

        }

                 if (mysql_query(conn, query_buffer)){
                         printf("query faild : %s\n", query_buffer);
                         exit(1);
						 
                 }

                 result = mysql_use_result(conn);
                 while ((row = mysql_fetch_row(result)) != NULL)
                         printf("%s \n", row[0]);
        }
        mysql_free_result(result);
        mysql_close(conn);

}




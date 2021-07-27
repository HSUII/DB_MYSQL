#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
        MYSQL *conn;
        MYSQL_RES *result;
        MYSQL_ROW row;

        char query_buffer[2048];
        char table[20] = "hum";
        int id = 7;
        char name[20] = "heesu";
        int year = 0;
        int birth = 000000;
        char gender[10] = "-";
        int qnum = 9;
        int column_num = 10;
        char info[1000];
        char id_c[10];
        char attr[20];//attribute name
        int attrupint;
        char attrupchar[20];
        conn = mysql_init(NULL);


        if(!mysql_real_connect(conn, "localhost", "사용자", "비밀번호", NULL, 0, NULL, 0)){
                printf("cannot connect");
                exit(1);
        }
        else{
                if (mysql_select_db(conn, "hsdb")){
                        printf("cannot use databases");
                        exit(1);
                }
        }


        while(qnum>0){

        printf("-----------------------------------------------------------------------------------------------------------\n");
        printf("|TABLE LIST : 1 | SELECT : 2 | INSERT : 3 | DELETE: 4 | UPDATE : 5 | TABLE INFO : 6  | DATABASE EXIT: -1 | \n");
        printf("-----------------------------------------------------------------------------------------------------------\n");
        printf("원하는 작업에 맞는 숫자를 입력하세요 : ");
        scanf("%d",&qnum);

 
        if(qnum==1)
        {
                 sprintf(query_buffer, "%s", "show tables");
                 printf("--------------------------------------------------------------------------------------------------\n");
         }
        if(qnum==2){
                 printf("테이블 이름을 입력하세요: ");
                 scanf("%s",table);
                 sprintf(query_buffer, "%s %s", "select * from ",table);
                 printf("--------------------------------------------------------------------------------------------------\n");
        }
        if(qnum==3){

                 printf("테이블 이름을 입력하세요: ");
                 scanf("%s",table);
                 printf("id : ");
                 scanf("%d",&id);
                 printf("이름: ");
                 scanf("%s",name);
                 printf("나이: ");
                 scanf("%d",&year);
                 printf("생년월일: ");
                 scanf("%d",&birth);
                 printf("성별: ");
                 scanf("%s",gender);

                 sprintf(query_buffer, "insert into %s values(%d,'%s',%d,%d,'%s')",table,id,name,year,birth,gender);
                 printf("%s\n",query_buffer);
        }
        if(qnum==4){

                 printf("테이블 이름을 입력하세요: ");
                 scanf("%s",table);
                 printf("삭제할 name  : ");
                 scanf("%s",name);
                 sprintf(query_buffer,"delete from %s where name = '%s%s",table,name,"'");
        }
        if(qnum==6){

                 sprintf(query_buffer, "desc human");
        }
        }
        if(qnum==5){

                 printf("테이블 이름을 입력하세요: ");
                 scanf("%s",table);
                 printf("변경할 속성이름: ");
                 scanf("%s",attr);
                 if(attr == "name"){
                 printf("변경하려는 값: ");
                 scanf("%s",&attrupchar);
                 printf("변경할 행의 id 값: ");
                 scanf("%d",&id);
                 sprintf(query_buffer,"update %s set name = '%s' where id = %d",table,attrupchar,&id);
                }
                 if( attr == "gender"){
                 printf("변경하려는 값: ");
                 scanf("%s",&attrupchar);
                 printf("변경할 행의 id 값: ");
                 scanf("%d",&id);
                 sprintf(query_buffer,"update %s set gender = '%s' where id = %d",table,attrupchar,&id);
                }
                 if(attr == "id" ){
                 printf("변경하려는 값: ");
                 scanf("%d",attrupint);
                 printf("변경할 행의 id 값: ");
                 scanf("%d",id);
                 sprintf(query_buffer,"update %s set id = %d where id = %d",table,attrupint,&id);
                }
                 if( attr == "year"){
                 printf("변경하려는 값: ");
                 scanf("%d",attrupint);
                 printf("변경할 행의 id 값: ");
                 scanf("%d",id);
                 sprintf(query_buffer,"update %s set year = %d where id = %d",table,&attrupint,&id);
                }
                 if( attr == "birth"){
                 printf("변경하려는 값: ");
                 scanf("%d",attrupint);
                 printf("변경할 행의 id 값: ");
                 scanf("%d",id);
                 sprintf(query_buffer,"update %s set %s = %d where id = %d",table,attr,&attrupint,&id);
                }
        }
        if(qnum==-1) break;

        if (mysql_query(conn, query_buffer)){

                         printf("query faild : %s\n", query_buffer);
                         exit(1);
        }                                                                                 }

        result = mysql_use_result(conn);

        while((row = mysql_fetch_row(result)) != NULL) {
                for(column_num =0; column_num < mysql_num_fields(result);column_num++){
                       printf("%s       ", row[column_num]);}
                printf("\n");
        }

        mysql_free_result(result);
        }

        mysql_close(conn);

}

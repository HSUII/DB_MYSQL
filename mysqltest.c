#include <stdio.h>
#include <mysql.h>
#include <errno.h>
#include <stdlib.h>

void main(void) {
        MYSQL mysql;

        if(!mysql_real_connect(&mysql,NULL,"root",".dlfndhs",NULL,3306,(char*)NULL,0))
        {
                printf("%s\n",mysql_error(&mysql));
                exit(1);

        }
        printf("성공 예!~.\n");
        mysql_close(&mysql);



}



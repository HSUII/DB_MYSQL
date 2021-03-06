# MYSQL

## MYSQL 설치 
- 리눅스 기반의 PUTTY 서버에 MYSQL을 설치해보자
- 설치 방법은 [리눅스 MYSQL 설치](https://blog.naver.com/mygoaway/222389484539)을 참고하였다.
***

## MYSQL 시작
- 접속전에 환경설정을 해준다 
- 환경설정 후 잘 설치 되었는지 확인 코드를 실행해보았다. 성공후 table이 화면에 띄여졌다. 
 정확한 코드는 <https://github.com/HSUII/DB_mysql/blob/master/mysqlconnect.c> 에 올려놓았다. 
 
- 잘 설치가 된 후에 밑에 명령어를 통해 mysql에 접속한다. 
``` 
mysql -u root -p
```
- 사전에 설정된 비밀번호를 입력한다. 비밀번호 변경을 원할시 변경할수 있다.
```
mysql> set password = 'password';
```
- ```>show databases```를 입력해서 mysql에 존재하는 database목록을 확인할 수 있다. 

![image](https://user-images.githubusercontent.com/87008955/126748851-770c4a42-e60d-4d6e-9533-aff3ef70a059.png)

- ```CREATE DATABASE HSDB;```를 통해 DATABASE를 생성할 수 있다. 
- ```desc 테이블명 ```  
    : 테이블 정보    
    ![image](https://user-images.githubusercontent.com/87008955/126944335-d8b7be21-a46e-4211-81a1-fc499f24822b.png)
    

***

## SQL 문법
- 본격적으로 TABLE을 생성하기 전에 SQL 문법에 대해 알아야 한다. 
- SQL에는 **DDL**, **DML**,**DCL**이 있다. 

***
  - **DDL(데이터 정의어)**
  : 테이블 생성, 변경, 제거 기능을 한다. 
     - **CREATE TABLE**
    
    : 테이블 생성
    
      ![image](https://user-images.githubusercontent.com/87008955/126749436-be7f0983-01ee-40ab-a626-e93bfe482ba1.png)   
     
      ![image](https://user-images.githubusercontent.com/87008955/126749583-1836c243-3570-4862-aeb7-a933857541e3.png)
     
    - 실제로 create 해보았다. 
    
     ![image](https://user-images.githubusercontent.com/87008955/126750123-afe66256-7264-4f0e-975e-549b1153aae7.png)
 
    - **ALTER TABLE** 
    : 새로운 속성을 추가하거나 기존 속성을 삭제, 수정하는데에 사용한다.
    
      -컬럼 추가 ```add```         
     ![image](https://user-images.githubusercontent.com/87008955/126945079-214209ab-dac3-47aa-9ec2-b0b1655b555b.png)   
     ![image](https://user-images.githubusercontent.com/87008955/126750251-f074bf76-1ef0-433e-b945-5e7b54a188d0.png)
     
      -컬럼 데이터 타입 변경 ```MODIFY COLUMN```     
     ![image](https://user-images.githubusercontent.com/87008955/126945160-e42d4949-ecde-4826-93bb-b74545da557b.png)   
    
      -컬럼명 변경 ```CHANGE```   
     ![image](https://user-images.githubusercontent.com/87008955/126945209-4912f7ed-9ac1-4aaa-904c-ff71dc2ba341.png)   
      
      -컬럼 삭제 ```DROP COLUMN```   
     ![image](https://user-images.githubusercontent.com/87008955/126945326-a213cca0-d90f-4c98-b5e6-682d4f8e5c3b.png)   

    
    - 3.*DROP TABLE*
    : 테이블 제거시 사용된다. 
    
     ![image](https://user-images.githubusercontent.com/87008955/126750463-4ccedd7f-1f7a-4691-86f7-be187ea806c5.png)
    출처: [DBMS](https://blog.naver.com/wltjdrmsdl/222379116092)
***
  - **DML(데이터 조작어)**
  :데이터의 검색, 삽입, 수정,삭제를 위해 사용한다.
  
    - *SELECT*   
    : 데이터 삽입   
    ![image](https://user-images.githubusercontent.com/87008955/126751811-f4092969-7aa0-4481-b1bf-7ed7ab8ecfec.png)

       - *order by*
     ```
     select * from talble명 where - order by id desc limit 2   
     //table명에서 속성명이 -인 열을 출력하는데 이때, id 내림차순으로 2번째까지만 출력해라 
     ```
    


    - *INSERT*
    : 행 삽입   
    ![image](https://user-images.githubusercontent.com/87008955/126750960-68d37d89-34d5-4380-ae85-00a4aeab895f.png)
   
    - *UPDATE* 
    : 특정 행의 속성 변경   
    ![image](https://user-images.githubusercontent.com/87008955/126751071-544a7306-bcd3-49ce-b8ff-5404ce0af9db.png)
   
    - *DELETE*
    : 행 삭제   
    ![image](https://user-images.githubusercontent.com/87008955/126751210-dd4ea069-e592-4ad0-ab1c-ef472ca4d790.png)


    
    

  

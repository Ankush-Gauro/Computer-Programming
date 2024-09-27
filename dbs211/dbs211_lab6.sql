/*
DBS211-Lab 6
Name-Ankush Gauro, Praful Basnet, Eduardo Cam Chang (Group 4)
ID- 108593237, 
Date : March 12, 2024
*/

--Question--1
/*
1.The user has established a new connection to the server.
2.The user used "BEGIN;" statement 
3.The user executes a "COMMIT;"statement
4.The user executes any DDL statement
*/

--Question--2
CREATE TABLE newEmployees AS 
SELECT * FROM employees
WHERE 1=0;

--Question--3
SET AUTCOMMIT OFF;
SET TRANSACTION READ WRITE;

--Question--4
INSERT ALL
    INTO newEmployees VALUES (100, 'Patel', 'Ralph','22333', 'rpatel@mail.com',1, NULL,'Sales Rep')
    INTO newEmployees VALUES (101, 'Denis', 'Betty','33444', 'bdenis@mail.com',4, NULL,'Sales Rep')
    INTO newEmployees VALUES (102, 'Biri','Ben', '44555', 'bbirir@mail.com',2, NULL,'Sales Rep')
    INTO newEmployees VALUES (103, 'Newman','Chad', '66777', 'cnewman@mail.com',3, NULL,'Sales Rep')
    INTO newEmployees VALUES (104, 'Ropeburn','Audrey', '77888', 'aropebur@mail.com',1, NULL,'Sales Rep')
SELECT * FROM dual;

--Question--5
SELECT * FROM newEmployees;
--Five rows are selected

--Question--6
ROLLBACK;
SELECT * FROM newEmployees;
--Zero rows are selected

--Question--7
INSERT ALL
    INTO newEmployees VALUES (100, 'Patel', 'Ralph','22333', 'rpatel@mail.com',1, NULL,'Sales Rep')
    INTO newEmployees VALUES (101, 'Denis', 'Betty','33444', 'bdenis@mail.com',4, NULL,'Sales Rep')
    INTO newEmployees VALUES (102, 'Biri','Ben', '44555', 'bbirir@mail.com',2, NULL,'Sales Rep')
    INTO newEmployees VALUES (103, 'Newman','Chad', '66777', 'cnewman@mail.com',3, NULL,'Sales Rep')
    INTO newEmployees VALUES (104, 'Ropeburn','Audrey', '77888', 'aropebur@mail.com',1, NULL,'Sales Rep')
SELECT * FROM dual;
COMMIT;
SELECT * FROM newEmployees;
--Five rows are selected

--Question--8
UPDATE newEmployees
SET jobTitle ='unknown';

--Question--9
UPDATE newEmployees
SET jobTitle ='unknown';
COMMIT;

--Quesion--10 part a
ROLLBACK;
SELECT *FROM newEmployees 
WHERE jobTitle ='unknown';
--All rows are still updated

--Quesion--10 part b
--No, the ROLLBACK command was not effective as it still showed the updated jobtitile of all employees.

--Quesion--10 part c
--In question-6 the Rollback was succesfull because the statements in the transaction was not commited whereas, in question 10 the transaction before was already commited therefore the rollback statement didn't work.

--Question--11
COMMIT;
DELETE FROM newEmployees;

--Question--12
CREATE VIEW vwNewEmps AS
SELECT * FROM newEmployees
ORDER BY lastName,firstName;

--Question--13 part a
ROLLBACK; 
--There are no employees now in the newEmployees table as the above DDL statement commits the statements before that.

--Question--13 part b
--No, the rollback was not effective because the above DDL statement commits the statements before that.

--Questions--14
COMMIT;
INSERT ALL
    INTO newEmployees VALUES (100, 'Patel', 'Ralph','22333', 'rpatel@mail.com',1, NULL,'Sales Rep')
    INTO newEmployees VALUES (101, 'Denis', 'Betty','33444', 'bdenis@mail.com',4, NULL,'Sales Rep')
    INTO newEmployees VALUES (102, 'Biri','Ben', '44555', 'bbirir@mail.com',2, NULL,'Sales Rep')
    INTO newEmployees VALUES (103, 'Newman','Chad', '66777', 'cnewman@mail.com',3, NULL,'Sales Rep')
    INTO newEmployees VALUES (104, 'Ropeburn','Audrey', '77888', 'aropebur@mail.com',1, NULL,'Sales Rep')
SELECT * FROM dual;

--Question--15
SAVEPOINT INSERTION;

--Question--16
UPDATE newEmployees
SET jobTitle ='unknown';
SELECT * FROM newEmployees;

--Question--17
ROLLBACK TO INSERTION;
SELECT * FROM newEmployees;
--The commands after the savepoint were rolled back i.e., the update statement were rolled back therefore, the jobtitle of the employees are not updated to "unknown".

--Question--18
ROLLBACK;
SELECT *FROM newEmployees;
--There is no data in the table because the basic rollback statement rolled back to the beginning of the trasaction i.e., before the "INSERT" statement.

--**PART B**
--Question--19
REVOKE ALL ON newEmployees FROM PUBLIC;

--Question--20
GRANT SELECT ON newEmployees TO dbs211_241zbb02;
--Question--21
GRANT INSERT,UPDATE,DELETE ON newEmployees TO dbs211_241zbb02;
--Question--22
REVOKE ALL ON newEmployees FROM dbs211_241zbb02;



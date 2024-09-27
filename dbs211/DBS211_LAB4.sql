/*
Name: Ankush Gauro
User Id: dbs211_241zbb10
Student Id: 108593237
Date: 2024 Feb 04
Purpose: DBS211C50 _Lab04
*/


SET AUTOCOMMIT ON;

/*Question 1*/

CREATE TABLE movies(
mid            INT             PRIMARY KEY,
title           VARCHAR(35)     NOT NULL,
releaseYear    INT             NOT NULL,
director        INT             NOT NULL,
score           DECIMAL(3,2)    CHECK (score < 5 and score > 0)
);

CREATE TABLE actors(
aid        INT         PRIMARY KEY,
firstName  VARCHAR(20) NOT NULL,
lastName   VARCHAR(30) NOT NULL
);

CREATE TABLE castings(
movieid INT NOT NULL, 
actorid INT NOT NULL, 
PRIMARY KEY (movieid, actorid),
FOREIGN KEY (movieid) REFERENCES movies (mid),
FOREIGN KEY (actorid) REFERENCES actors (aid) 
); 

CREATE TABLE directors(
directorid INT PRIMARY KEY, 
firstname VARCHAR(20) NOT NULL, 
lastname VARCHAR(30) NOT NULL
); 

/*Question 2*/

ALTER TABLE movies
ADD CONSTRAINT director_fk FOREIGN KEY (director) REFERENCES directors;

/*Question 3*/

ALTER TABLE movies 
ADD CONSTRAINT title_uni UNIQUE(title);

/*Question 4*/

INSERT ALL 
INTO directors VALUES(1010, 'Rob', 'Minkoff') 
INTO directors VALUES(1020, 'Bill', 'Condon')
INTO directors VALUES(1050, 'Josh' ,'Cooley') 
INTO directors VALUES (2010, 'Brad','Bird')
INTO directors VALUES (3020, 'Lake', 'Bell')
SELECT * FROM dual;

INSERT ALL 
INTO movies VALUES (100, 'The Lion King', 2019, 3020,3.5) 
INTO movies VALUES (200, 'Beauty and the Beast', 2017, 1050, 4.20) 
INTO movies VALUES (300, 'Toy Story 4', 2019, 1020, 4.50) 
INTO movies VALUES (400, 'Mission Impossible', 2018, 2010,5.00) 
INTO movies VALUES (500, 'The Secret Life of Pets', 2016, 1010,3.90) 
SELECT * FROM dual;

/*Question 5*/

DROP TABLE castings, movies, actors, directors;
/* 
order matters because we cant attpemt to delete the child table without deleting the parent table. 
The parent table cannot be deleted when foreign key is used in child table. Therefore, the child table 
needs to be deleted first 
*/

/*Question 6*/

CREATE TABLE employee2 AS SELECT * FROM employees WHERE 1=0;

/*Question 7*/

ALTER TABLE employee2 ADD username VARCHAR(50);

/*Question 8*/

DELETE FROM employee2;

/*Question 9*/

INSERT INTO employee2 (employeenumber, lastname, firstname, extension,email,officecode,reportsto,jobtitle) 
SELECT *  FROM employees; 

/*Question 10*/

UPDATE employee2 
SET firstname = 'Ankush',
lastname ='Gauro'
WHERE employeenumber = 1002;

/*Question 11*/

SELECT rownum,lower(concat(substr(firstname,1,1),lastname))|| '@myseneca.ca' 
FROM employee2;

/*Question 12*/

DELETE FROM employee2
WHERE officecode = 4; 

/*Question 13*/

DROP TABLE employee2; 
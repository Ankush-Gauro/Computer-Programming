/*
1. A total of 8 tables have been created and they are:
    a)CUSTOMERS
    b)EMPLOYES
    c)OFFICES
    d)ORDERDETAILS
    e)ORDERS
    f)PAYMENTS
    g)PRODUCTLINES
    h)PRODUCTS


2. There are a total of 122 rows in the customers table

3. The sql statement to return the number of rows in the customers table is
*/
SELECT * FROM CUSTOMERS;

/*
4. There are a total of 13 columns in the customer table, and they are:
    a)CUSTOMERNUMBER
    b)CUSTOMERNAME 
    c)CONTACTLASTNAME
    d)CONTACTFIRSTNAME
    e)PHONE  
    f)ADDRESSLINE1
    g)ADDRESSLINE2
    h)CITY
    i)STATE
    j)POSTALCODE
    k)COUNTRY
    l)SALESREPEMPLOYEENUMBER
    m)CREDITLIMIT
    
5. The value of each column in first row in customers table is:
    a)CUSTOMERNUMBER = 103 (Datatype - Number(38, 0))
    b)CUSTOMERNAME = Atelier graphique (Datatype - VARCHAR2(50 BYTE)) 
    c)CONTACTLASTNAME = Schmitt (Datatype - VARCHAR2(50 BYTE))
    d)CONTACTFIRSTNAME = Carine (Datatype - VARCHAR2(50 BYTE))
    e)PHONE = 40.32.2555 (Datatype- Integer)
    f)ADDRESSLINE1 = 54, rue Royale (Datatype - VARCHAR2(50 BYTE))
    g)ADDRESSLINE2 = null (Datatype - VARCHAR2(50 BYTE))
    h)CITY = Nantes (Datatype - VARCHAR2(50 BYTE))
    i)STATE = null (Datatype - VARCHAR2(50 BYTE))
    j)POSTALCODE = 44000(Datatype - VARCHAR2(50 BYTE))
    k)COUNTRY = France(Datatype - VARCHAR2(50 BYTE))
    l)SALESREPEMPLOYEENUMBER = 1370(Datatype - Number(38, 0))
    m)CREDITLIMIT = 21000 (Datatype - Number(10, 0))
    
6. The rows and columns for rest of the tables are:
Table Name		    Rows		Columns
EMPLOYEES           23          8
OFFICES             7           9
ORDERDETAILS        2996        5
ORDERS              326         7
PAYMENTS            273         4
PRODUCTLINES        7           4
PRODUCTS            110         9

7. The orderdetails table includes 2996 rows.

*/


/*
8. The desc offices statement describes the features of the offices table
*/

SELECT * FROM employees;
SELECT * FROM customers ORDER BY ContactLastName;

/*
9. The first statement outputs all the content of employees table
The second statement does the same in customers table but it displays the output in orber ascending by the contactlastname column.

10. The products table have a total of 11 constraints.

11. Tools --> preferences --> code editor --> fonts
Did it. Font set to 15
*/




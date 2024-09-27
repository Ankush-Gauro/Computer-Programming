--Q1 Solution
SELECT employeenumber, firstname, lastname, city, phone, postalcode
FROM employees INNER JOIN offices USING (officecode)
WHERE UPPER(country) = 'FRANCE';

--Q2 Solution--
SELECT customernumber, customername, TO_CHAR (paymentdate, 'MON DD, YYYY') as paymentdate, amount
FROM customers INNER JOIN payments USING (customernumber)
WHERE UPPER(country) = 'CANADA'
ORDER BY customernumber;

--Q3 Solution--  IT IS INNER JOIN
SELECT customernumber, customername
FROM customers LEFT JOIN payments USING (customernumber)
WHERE payments.amount IS NULL
AND UPPER(country) = 'USA'
ORDER BY customernumber;

--Q4 Solution--
CREATE VIEW vwCustomerOrder AS 
SELECT customernumber, ordernumber, orderdate, productname, quantityordered, buyprice
FROM orders JOIN orderdetails USING (ordernumber) 
JOIN products ON orderdetails.productcode = products.productcode;
SELECT * FROM vwCustomerOrder;

--Q5 Solution--
SELECT * FROM vwCustomerOrder 
JOIN orderdetails USING (ordernumber) 
WHERE customernumber = 124 
ORDER BY ordernumber, orderlinenumber;

--Q6 Solution--
SELECT a.customernumber, a.contactfirstname, a.contactlastname, a.phone, a.creditlimit 
FROM CUSTOMERS a LEFT JOIN ORDERS b ON a.customernumber=b.customernumber
WHERE b.customernumber IS NULL;

--Q7 Solution--
CREATE VIEW vwEmployeeManager AS
SELECT a.employeenumber, a.lastname, a.firstname, a.extension, a.email, a.officecode,a.jobtitle, a.reportsto, b.firstname || ' ' || b.lastname as Manager FROM EMPLOYEES a
LEFT JOIN EMPLOYEES b ON a.reportsto=b.employeenumber WHERE a.reportsto=b.employeenumber OR a.reportsto IS NULL;

--Q8 Solution--
ALTER VIEW vwEmployeeManager AS 
SELECT a.employeenumber, a.lastname, a.firstname, a.extension, a.email, a.officecode,a.jobtitle, a.reportsto, CONCAT(b.firstname, ' ' , b.lastname) as Manager FROM EMPLOYEES a
LEFT JOIN EMPLOYEES b ON a.reportsto = b.employeenumber WHERE a.reportsto=b.employeenumber OR a.reportsto IS NOT NULL;

--Q9 Solution--
DROP VIEW vwCustomerOrderA;
DROP VIEW vwEmployeeManagerA;
-- ***********************
-- Name: Ankush Gauro, Praful Basnet, Eduardo Cam Chang (Group-4)
-- ID: 108593237(Ankush), 127740223(Praful), 141321224(Eduardo) 
-- Date: 2024/03/05
-- Purpose: Assignment 1 DBS211
-- ********************

--Q1 Solution--
SELECT
   e.employeenumber,
   e.lastname || ', ' || e.firstname AS "Employee Name",
   o.phone,
   e.extension,
   o.city,
   e.reportsto AS "Manager Id" 
FROM
   employees e 
   JOIN
      offices o USING (officecode) 
WHERE
   e.reportsto IS NULL
ORDER BY
   o.city,
   e.employeenumber;
   
--Q2 Solution--
SELECT e.employeenumber, e.firstname || ' ' || e.lastname as "Employee Name", o.phone, e.extension, o.city
FROM employees e JOIN offices o ON e.officecode = o.officecode 
WHERE UPPER(o.city) IN('NYC','TOKYO','PARIS') 
ORDER BY o.city, e.employeenumber;

--Q3 Solution--
SELECT e.employeenumber, e.firstname || ' ' || e.lastname as "Employee Name", o.phone, e.extension, o.city, e.reportsto as "Manager ID", m.firstname || ' ' || m.lastname as "Manager Name" 
FROM employees e LEFT JOIN employees m ON e.reportsto = m.employeenumber 
JOIN offices o ON e.officecode = o.officecode WHERE UPPER(o.city) IN('NYC','TOKYO','PARIS')  
ORDER BY o.city, e.employeenumber;

--Q4 Solution--
SELECT DISTINCT
    emp1.reportsto   AS "Manager ID",
    emp2.firstname
    || ' '
    || emp2.lastname AS "Manager Name",
    o.country,
    CASE
        WHEN emp2.reportsto IS NULL THEN
            'Does not report to anyone'
        ELSE
            concat(concat(concat(concat('Reports to ',
                                        concat(emp3.firstname,
                                               concat(' ', emp3.lastname))),
                                 ' ('),
                          emp3.jobtitle),
                   ')')
    END            AS "Reports to"
FROM
    employees emp1
    LEFT JOIN employees emp2 ON emp1.reportsto = emp2.employeenumber
    LEFT JOIN employees emp3 ON emp2.reportsto = emp3.employeenumber
    LEFT JOIN offices   o ON emp2.officecode = o.officecode
WHERE
    emp1.reportsto IS NOT NULL
ORDER BY
    emp1.reportsto;

--Q5 Solution--
SELECT
c.customernumber,
    c.customername,
    od.productcode,
    p.msrp AS oldprice,
    (p.msrp * 0.9) AS newprice
FROM
    customers c
    INNER JOIN orders o ON c.customernumber = o.customernumber
    INNER JOIN orderdetails od ON o.ordernumber = od.ordernumber
    INNER JOIN products p ON od.productcode = p.productcode
WHERE
    od.quantityordered > 55
    AND p.productcode IN (
        SELECT productcode FROM products WHERE productvendor = 'Exoto Designs'
    )
ORDER BY
    c.customernumber;
    
--Q6 Solution--
SELECT
    od1.priceeach AS "Maximum Price"
FROM
         orderdetails od1
    JOIN orderdetails od2 ON od1.productcode = od2.productcode
WHERE
        od1.productcode = 'S10_1678'
    AND od1.priceeach > od2.priceeach
    AND ROWNUM <= 1
ORDER BY
    od1.priceeach DESC;


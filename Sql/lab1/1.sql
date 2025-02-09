﻿--1--
SELECT ID, LAST_NAME || '(' || TITLE || ')' "Title", ROUND(SALARY * 1.15) "Full Salary" 
FROM S_EMP;

--2--
SELECT NAME
FROM S_CUSTOMER
WHERE LOWER(NAME) LIKE '%sport%';

--3.1--
SELECT NAME
FROM S_PRODUCT
WHERE NAME LIKE 'Pro%'
ORDER BY NAME;

--3.2--
SELECT NAME, SHORT_DESC
FROM S_PRODUCT
WHERE LOWER(SHORT_DESC) LIKE '%ski%';

--4.1--
SELECT NAME, PHONE, CREDIT_RATING
FROM S_CUSTOMER
WHERE SALES_REP_ID = 11;

--4.2--
SELECT NAME "Company", PHONE "Company ID", CREDIT_RATING "Rating"
FROM S_CUSTOMER
WHERE SALES_REP_ID = 11;

--5.1--
DESC S_EMP;

--5.2--
SELECT FIRST_NAME || ' ' || LAST_NAME "Employees", DEPT_ID
FROM S_EMP
WHERE DEPT_ID IN (10, 50)
ORDER BY LAST_NAME;

--5.3--
SELECT FIRST_NAME, START_DATE
FROM S_EMP
WHERE START_DATE
BETWEEN TO_DATE('14.05.1990', 'DD.MM.YYYY')
AND TO_DATE('26.05.1991', 'DD.MM.YYYY')
ORDER BY START_DATE DESC;

--5.4--
SELECT LAST_NAME "Employee Name", SALARY "MONTHLY SALARY"
FROM S_EMP
WHERE (DEPT_ID IN (31, 42, 50))
AND (SALARY NOT BETWEEN 1000 AND 2500);

--6--
SELECT FIRST_NAME || ' зарабатывает ' || SALARY || ' в месяц, но желает ' || SALARY * 3 || '.'
AS "Желания"
FROM S_EMP;

--7--
SELECT LAST_NAME,
ROUND(MONTHS_BETWEEN(SYSDATE, START_DATE)) Months
FROM S_EMP
ORDER BY Months;

--8--
SELECT LAST_NAME,
TO_CHAR(START_DATE, 'dd.mm.yyyy') "Start Date",
TO_CHAR(NEXT_DAY(ADD_MONTHS(START_DATE, 6), 'Monday'), 'dd.mm.yyyy') "Next Date"
FROM S_EMP;




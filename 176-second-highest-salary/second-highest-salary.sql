-- SELECT (
--     SELECT DISTINCT salary
--     FROM Employee
--     ORDER BY salary DESC
--     LIMIT 1 OFFSET 1
-- ) AS SecondHighestSalary;

SELECT max(salary) as 'SecondHighestSalary'
FROM (
    SELECT salary,
           DENSE_RANK() OVER(ORDER BY salary DESC) AS rnk
    FROM Employee
) as t
WHERE rnk = 2;
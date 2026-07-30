# Write your MySQL query statement below
-- Select E.name as "Employee" from Employee E where E.salary > (select M.salary from Employee M where M.id = E.managerId)

SELECT E.name AS Employee
FROM Employee E
JOIN Employee M
ON E.managerId = M.id
WHERE E.salary > M.salary;
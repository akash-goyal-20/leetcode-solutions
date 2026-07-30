# Write your MySQL query statement below
Select E.name as "Employee" from Employee E where E.salary > (select M.salary from Employee M where M.id = E.managerId)
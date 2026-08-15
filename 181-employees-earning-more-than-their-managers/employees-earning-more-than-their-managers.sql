# Write your MySQL query statement below
Select e.name as "Employee" from Employee e join Employee f 
on e.managerId = f.id where e.salary > f.salary
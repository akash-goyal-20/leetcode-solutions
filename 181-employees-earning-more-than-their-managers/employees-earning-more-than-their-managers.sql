# Write your MySQL query statement below
Select E.name as Employee from Employee E
inner join Employee M 
on E.managerID = M.id
where E.salary > M.salary
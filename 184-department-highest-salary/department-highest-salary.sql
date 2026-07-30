# Write your MySQL query statement below
select d.name as 'Department', e.name as 'Employee', e.salary as 'Salary' from Employee e 
inner join Department d on e.departmentId = d.id
where e.salary = (
    select max(a.salary) from Employee a group by a.departmentId
    having a.departmentId = e.departmentId
)
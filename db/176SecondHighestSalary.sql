#Tow select to slove null problem
#But I don not konw why
select (
  select distinct Salary from Employee order by Salary Desc limit 1 offset 1
)as SecondHighestSalary

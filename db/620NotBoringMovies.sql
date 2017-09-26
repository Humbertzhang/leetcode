# Write your MySQL query statement below
select *
from cinema
where mod(id, 2) = 1
and (description <>'boring')  #<> 为不等于, mysql 与　sqlite3的不同
order by rating desc

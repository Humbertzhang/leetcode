# LEFT JOIN performs a join starting with the first (left-most) table and then
# any matching second (right-most) table records.
# LEFT JOIN and LEFT OUTER JOIN are the same


select FirstName, LastName, City, State
from Person left join Address using(PersonId);

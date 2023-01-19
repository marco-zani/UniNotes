-- Find the minimum<, maximum, and average profit per movie for each director who is older than 50.
-- q1: director min max avg 
select distinct d.director, coalesce(min(profit),-1), coalesce(max(profit),-1), coalesce(round(avg(profit), 2),-1)
from (select director,title,year, gross-budget as profit
from movies) as m
right join directors d on m.director=d.director
where extract(year from now())-d.yearOfBirth>=50
group by d.director;



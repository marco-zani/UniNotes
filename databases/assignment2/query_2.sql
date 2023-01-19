-- Find the latest movie that won at least 3 awards. 
--q2: title year 
with big_winners as (
select a.title, a.year
from movieAwards a
where result='won'
group by a.title, a.year
having count(*)>2
)
select distinct title, year
from big_winners
where year=coalesce((select max(year) from big_winners),-1);
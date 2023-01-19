-- Find the movie that won the largest number of Oscars.
-- q6: title year 
with Oscars_won as (
select title, year, count(*)
from movieAwards
where award like 'Oscar%' and result='won'
group by title, year
)

select distinct title, year
from Oscars_won
where count=(select max(count) from Oscars_won);




-- Find the percentage of movies that won an Oscar among all movies made in the 80s.
-- q8: feature 
with eighties_films as(
    select m.title, m.year
    from movies m
    where m.year/10=198
)

select distinct coalesce(round(
        (
            cast(count(*) as decimal)/
            nullif(
            (   
            select count(*)
            from eighties_films
            ),0)
        )
    , 2),-1) as feature
from eighties_films f
join movieAwards a on a.title=f.title and a.year=f.year
where award like 'Oscar%' and result='won';



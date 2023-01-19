-- Find awards received by directors who made a high-grossing (over $1 million ) movie in the past 5 years.
-- q4: award year director 
with all_directors_awards as (
    select d1.director, d1.year, d1.award
    from directorAwards d1
    where result='won'
    union 
    select m.director, m.year, a.award
    from  movieawards a
    join movies m on m.title=a.title and m.year=a.year
    where a.result='won' and a.award like '%best director%'
)

select distinct a.award, a.year, a.director
from all_directors_awards a
where a.director in (
    select m.director
    from movies m
    where extract(year from now())-m.year <= 5 and m.gross>1000000
);

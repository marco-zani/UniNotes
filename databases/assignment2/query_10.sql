-- Find directors who won a 'best director' every year when a Spielberg movie won at least three awards.
-- q10: director 

with spielberg_years as(
select m.year
from movieAwards a
join movies m on a.title=m.title and a.year=m.year
where m.director='Steven Spielberg' and a.result='won'
group by m.title, m.year
having count(*)>2
),
all_directors_awards as (
    select d1.director, d1.year, d1.award
    from directorAwards d1
    where result='won'
    union 
    select m.director, m.year, a.award
    from  movieawards a
    join movies m on m.title=a.title and m.year=a.year
    where a.result='won' and a.award like '%best director%'
)

select distinct director
from (
    select distinct director, year
    from all_directors_awards
    where year in (select * from spielberg_years)
) as awards_in_spielberg_years
group by director
having count(*)=(select count(*) from spielberg_years);

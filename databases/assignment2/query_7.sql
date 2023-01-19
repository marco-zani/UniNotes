-- Find the youngest and the oldest directors who won an Oscar for "best director". 
-- q7: director feature 
with all_directors_oscars as (
    select d2.director, d2.yearOfBirth
    from (
        select d1.director
        from directorAwards d1
        where result='won' and d1.award like '%Oscar%'
        union 
        select m.director
        from  movieawards a
        join movies m on m.title=a.title and m.year=a.year
        where a.result='won' and a.award like 'Oscar%best director%'
    ) as d1
    join directors d2 on d1.director=d2.director
),


oldest_best_directors as(
select director, 'oldest' as feature
from all_directors_oscars
group by director, yearOfBirth
having yearOfBirth=(select min(yearOfBirth) from all_directors_oscars)
),



youngest_best_directors as (
select director, 'youngest' as feature
from all_directors_oscars
group by director, yearOfBirth
having yearOfBirth=(select max(yearOfBirth) from all_directors_oscars)
)



select distinct director, feature
from youngest_best_directors
union
select distinct director, feature
from oldest_best_directors;

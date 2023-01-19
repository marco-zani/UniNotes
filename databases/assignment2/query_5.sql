-- For each movie, find its award "success-rate", that is, the probability of getting an award it was nominated for. 
-- q5: title year s. rate 
with  win_prob as (
    select n.title, n.year, round((cast(coalesce(wins, 0) as decimal)/nominated),2) as success_rate
    from (
        select title, year, count(*) as nominated
        from movieawards 
        group by title, year
    ) as n
    left join (
        select title, year, count(*) as wins
        from movieawards  
        where result='won'
        group by title, year
    ) as w on n.title=w.title and n.year=w.year
)

select distinct m.title, m.year, coalesce(w.success_rate,-1) as success_rate
from movies m
left join win_prob w on w.title=m.title and w.year=m.year;
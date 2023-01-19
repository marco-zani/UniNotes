-- Find the most profitable movie, and the least expensive movie.
-- q3: feature title year 
with movie_profit as(
    select title, year, gross-budget as profit, budget
    from movies
),
most_profitable_movies as (
    select 'most profitable movie' as feature, title, year 
    from movie_profit
    where profit=(select max(profit) from movie_profit)
),
least_expensive_movies as (
    select 'least expensive movie' as feature, title, year 
    from movie_profit
    where budget=(select min(budget) from movie_profit)
)

select distinct feature, title, year
from most_profitable_movies
union
select distinct feature, title, year
from least_expensive_movies;
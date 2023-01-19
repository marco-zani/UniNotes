-- Find directors who won the 'best director' award, although the movie for which they won the award was not profitable.
-- q9: director 

select distinct m.director
from movieAwards a
join movies m on m.title=a.title and m.year=a.year
where a.award like '%best director%' and a.result='won' and m.gross<=m.budget;

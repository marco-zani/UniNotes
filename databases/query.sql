-- 1

select distinct language 
from languages l
join populations p on p.country=l.country
where -- l.percentage > 50 and 
p.sex_ratio = (select max(sex_ratio) from populations);


-- 2
drop view if exists tot_lang;

create temp view tot_lang as
    select count(*) as count1, country
    from languages
    group by country
;

select distinct e.poverty
from tot_lang t
join economies e on t.country=e.country
where t.count1 = (select max(count1) from tot_lang);

-- 3
select distinct country
from (
select country
from languages
where language = "English" and percentage > 50) as englishCountries
join economies e on englishCountries.country = e.country
where e.poverty > (
    select max(poverty) 
    from countries c
    join economies e2 on c.country=e2.country
    where c.name = "USA"
);

--4
select distinct name
from populations p
join countries c on p.country=c.code
where p.birth_rate-death_rate = (
    select min(p.birth_rate-death_rate)
    from populations);

--6
select distinct language, round(sum(l.percentage*p.population*1.0)/(select sum(population) from populations))
from (
    select country, population
    from populations
    where birth_rate-death_rate < 0) as p
join languages l on  l.country=p.country
group by language;

--8 
select distinct language
from languages l
join populations p on l.country=p.country
where percentage >24
group by language
order by avg(p.adult) desc, language;

-- 10
select code
from countries
order by area desc, name
limit 1 offset 14
;

--------------------------------------------------------------------------
select c.name, count(*)
from countries c
join languages l on c.code=l.country
group by c.code;


--------------------------------------------------------------------------

select aid
from Aircraft a
where aid in (
    select c.aid
    from certified c, employees e
    where c.eid=e.eid and not exists (
        select * 
        from employees e1
        where e1.eid=e.eid and e1.salary < 80000
    )
)


select c.eid, max(a.cruisingrange)
from certified c 
join Aircraft a on a.aid=c.aid
group by c.eid
having count(*)>3

select name, salary
from employees
where salary < (select min(price)
from flights
where from="los angeles" and to="honolulu")

select name, avg(e.salary)
from Aircraft a
join certified c on c.aid=a.aid
join employees e on e.eid=c.eid
where a.cruisingrange > 1000
group by aid


select *
from flights
where not exists(
    select * 
    from employees e
    where e.salary > 100000 and not exists(
        select * 
        from Aircraft a
        join 
    )
)

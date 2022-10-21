-- find the employees that can fly a plane from newyork to paris

select ename
from employee
join certified on eid=eid 
join aircraft on aid=aid
join flight on distance < cruiserange
where  from="newyork" and to="paris" OR (contrario) 

-- find the names of aircraft such that all pilots 
-- certified to operate them have salaries more tham 80.000

select aname
from aircraft
where aname not in (
    select aname
    from aircraft
    join certified
    join employee
    where salary < 80.000
)

--For each pilot who is certified for more than three aircraft, 
--find the eid and the maximum cruising range od the aircraft
-- for which the she or he is certified

select eid, max(cruisrange)
from certified
join aircraft
group by eid
having count (*) > 3

-- find the names of pilots whose salary is less than the price
--of the cheapest route from los angeles to honolulu

select * 
from employee
where salary < (
    select min(price)
    from flights
    where from="los angeles" and to="honolulu"
)

-- for all the aircraft with a cruisingrange over 1000 miles, 
-- find the name of the aircraft and the average salary of all
-- certified pilots for that aircraft

select name, avg(salary)
from aircraft
join certified
join employees
where cruisingrange > 1000
group by aid, aname

-- find the names of pilots certified for some boeing 

select eid
from certified
join aircraft
where aname like "boeing%"

-- find the aids for all aircraft that can be used on routes 
-- from los angeles to chicago

select aid
from aircraft
join flights on cruisingrange > distance and from="losangeles" and to="chicago"
-- not sure

-- identify the routes that can be piloted by every pilot
-- that makes more than 100.000

select *
from flight
where not exists (
    select eid
    from employees
    where salary < 100000 and
)
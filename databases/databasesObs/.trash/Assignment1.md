. We keep information about voters (name, fiscal code, and region they belong), and political parties (name and founded  
year). Voters may have membership to one or more political parties. It is important to know the date a voter applied for  
membership in a political party. Political parties are identified by their name and voters by their fiscal code, and parties  
may have no voters at all.  

2. A voter may have one or more party card. The party card can be given to any voter independently of whether they are  
members of a party or not. The cards however are personal. It is strictly forbidden for a party card to be used by a person  
other than the one that it was issued. A party card has a sequential number (e.g. 1st, 2nd, etc.) which indicates which card  
of that voter it is. The card has also a party name. The party name of the card may or may not be an existing party. This  
can happen for instance if the party had been disbanded or we have decided that we do not want to have information  
about that party in our database.  

3. Party cards have levels. Each card is of a specific level, which gives to the card holder specific privileges. We want to  
have the levels stored into the database so that we know them even if for some levels we have no cards.  

4. Each voter has some specific ideology. For an ideology we need to know other than the name (that identifies the  
ideology), the founder and the year that the ideology started.  

5. Parties may belong to coalitions. A coalition is nothing more than a number of parties. Of course, a coalition must be  
formed with at least a party participating.  

6. For a coalition to be formed, there must be some ideology on which the coalition is formed.  

7. Since the idea of an ideology is not always very clearly defined, and it can happen that different coalitions have the same  
ideology, it is only natural that parties may choose to belong to more than one coalition.  

8. Parties are always organized into one or more wings (like a military wing, a political wing, a government wing, etc.). Each  
wing of a party has a director that controls the wing. Wings are recognized by their name, i.e., wingName. We want to  
have the different kinds of wings into the database, so that we know them even if for some wings there are no parties with  
that wing.  

9. A party may have committee members (those are very different from the voters). Of course, a committee member must  
refer to exclusively one party. Some committee members are either candidates (which are those among which the voters  
will be asked to vote for if elections happen in the future) or officers. A party officer cannot be a party candidate, and vice  
versa.  

10. For the party committee members, we need to know the date they started to be party committee member. It is possible  
that some of them leave the party and come again at a later time. In these cases, we keep only the latest date they  
started the role of committee member. Each party committee member has a unique id, called memberId, which uniquely  
identifies the member.  

11. For every candidate of the party, we need to keep the number of times the candidate has participated in elections, so that  
we know to whom to give priority for the next elections candidacy.  

12. Party committee members may receive compensations (we need to know the amount) from coalition groups. When a  
coalition group gives some compensation to a party committee member, this is done for the purpose of a specific election.  
By law, a coalition group cannot compensate a party committee member for a specific election more than once, but of  
course it can compensate a member for different elections.  

13. Party officers have a seniority level. That is simply a number. The higher the number the more senior the person.  

14. Sometimes, when there are doubts about how devoted a voter is a party, a party officer may be asked to mentor/guide the  
membership of a voter in the party. Officers can mentor different memberships, but a membership cannot have more than  
one officer mentoring it.  

15. Candidates may participate in tours. For a tour we need to know the starting date.  

16. A tour is a sequence of stops in different locations. A tour that repeats the same location more than once is fine, but we  
need to know the sequence of the locations that the tour consists of
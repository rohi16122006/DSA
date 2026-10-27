# Write your MySQL query statement below
WITH C1 AS (
    SELECT id, visit_date, people, 
           id - ROW_NUMBER() OVER (ORDER BY id) AS grp
    FROM Stadium
    WHERE people >= 100
)
SELECT id, visit_date, people
FROM C1
WHERE grp IN (
    SELECT grp 
    FROM C1 
    GROUP BY grp 
    HAVING COUNT(*) >= 3
)
ORDER BY visit_date;
# Write your MySQL query statement below
SELECT
    visited_on,
    amount,
    ROUND(amount / 7, 2) AS average_amount
FROM (
    SELECT
        visited_on,
        SUM(total_amount) OVER (
            ORDER BY visited_on
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) AS amount,
        COUNT(*) OVER (
            ORDER BY visited_on
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) AS days_count
    FROM (
        SELECT
            visited_on,
            SUM(amount) AS total_amount
        FROM Customer
        GROUP BY visited_on
    ) AS daily
) AS result
WHERE days_count = 7
ORDER BY visited_on;
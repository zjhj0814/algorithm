-- 코드를 입력하세요
SELECT
fh.flavor
FROM first_half fh 
LEFT OUTER JOIN icecream_info ii ON fh.flavor = ii.flavor
WHERE ii.ingredient_type = 'fruit_based'
GROUP BY fh.flavor
HAVING sum(fh.total_order) > 3000
ORDER BY fh.total_order DESC;
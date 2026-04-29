-- 코드를 입력하세요
-- 7월의 맛별 총 주문량
SELECT j.flavor
FROM july j LEFT JOIN first_half fh ON j.shipment_id = fh.shipment_id
GROUP BY j.flavor
ORDER BY SUM(j.total_order) + IFNULL(fh.total_order,0) DESC
LIMIT 3;
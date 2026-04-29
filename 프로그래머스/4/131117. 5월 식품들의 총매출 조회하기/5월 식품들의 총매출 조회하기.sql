-- 코드를 입력하세요
SELECT p.product_id, p.product_name, price * sum(amount) as total_sales
FROM food_product p
LEFT OUTER JOIN food_order o ON p.product_id = o.product_id
WHERE o.produce_date >= '2022-05-01' AND o.produce_date < '2022-06-01'
GROUP BY product_id
ORDER BY total_sales DESC, product_id;

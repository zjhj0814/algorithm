-- 코드를 입력하세요
SELECT p.product_code, p.price * SUM(os.sales_amount) AS sales
FROM Product p JOIN Offline_sale os ON p.product_id = os.product_id
GROUP BY p.product_id
ORDER BY sales DESC, p.product_code;
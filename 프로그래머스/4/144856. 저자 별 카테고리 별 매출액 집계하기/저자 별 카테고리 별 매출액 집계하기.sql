-- 코드를 입력하세요
-- BOOK_SALES: SALES_DATE 2022년 1월 기준
SELECT b.author_id, a.author_name, b.category, SUM(b.price * s.sales) AS total_sales
FROM book b
JOIN author a ON b.author_id = a.author_id
LEFT JOIN book_sales s ON b.book_id = s.book_id
WHERE s.sales_date >= '2022-01-01' AND s.sales_date < '2022-02-01'
GROUP BY b.author_id, b.category
ORDER BY b.author_id, b.category DESC;
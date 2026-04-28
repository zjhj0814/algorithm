-- 코드를 입력하세요
SELECT
book_id, published_date
FROM book
WHERE YEAR(published_date) = '2021' AND category = '인문'
ORDER BY published_date;
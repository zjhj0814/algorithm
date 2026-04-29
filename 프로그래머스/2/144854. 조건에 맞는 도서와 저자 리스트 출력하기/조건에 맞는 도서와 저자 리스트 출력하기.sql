-- 코드를 입력하세요
SELECT b.book_id, a.author_name, b.published_date
FROM Book b JOIN Author a ON b.author_id = a.author_id
WHERE b.category = '경제'
ORDER BY b.published_date;
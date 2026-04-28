-- 코드를 입력하세요
SELECT
b.title,
b.board_id,
r.reply_id,
r.writer_id,
r.contents,
r.created_date
FROM USED_GOODS_BOARD b
JOIN USED_GOODS_REPLY r ON b.board_id = r.board_id
WHERE DATE(b.created_date) BETWEEN '2022-10-01' AND '2022-10-31'
ORDER BY r.created_date, b.title;
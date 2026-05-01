-- 코드를 입력하세요
SELECT 
user_id, 
nickname, 
CONCAT(city, ' ', street_address1, ' ', IFNULL(street_address2,'')) AS '전체 주소',
-- ⭐️ MYSQL 문자열은 1-based index
-- 1. CONCAT 방법: concat(s1, s2, s3, ...)
-- CONCAT(SUBSTRING(tlno,1,3),'-',SUBSTRING(tlno,4,4),'-',SUBSTRING(tlno,8,4)) AS '전화번호'
-- 2. INSERT 방법: insert(s, 시작 인덱스(앞부터 삽입), 교체할 문자 길이, 삽입할 문자열)
INSERT(INSERT(tlno, 4, 0, '-'),9,0,'-') AS '전화번호'
FROM used_goods_user
WHERE user_id IN (
    SELECT writer_id
    FROM used_goods_board
    GROUP BY writer_id
    HAVING COUNT(board_id) >= 3
)
ORDER BY user_id DESC;

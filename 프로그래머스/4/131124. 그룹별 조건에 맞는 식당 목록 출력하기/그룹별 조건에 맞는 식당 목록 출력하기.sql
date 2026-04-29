-- 코드를 입력하세요
SELECT m.member_name, r.review_text, r.review_date
FROM member_profile m
LEFT OUTER JOIN rest_review r ON m.member_id = r.member_id
WHERE r.member_id = (
    SELECT member_id 
    FROM rest_review 
    GROUP BY member_id 
    ORDER BY COUNT(review_id) DESC
    LIMIT 1
)
ORDER BY r.review_date, r.review_text;

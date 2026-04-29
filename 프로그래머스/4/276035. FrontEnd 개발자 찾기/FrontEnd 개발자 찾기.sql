-- 코드를 작성해주세요
-- SQL 비트 연산 &
-- 400 & 16 = 16 -> javascript 스킬 가지고 있음
SELECT DISTINCT d.id, d.email, d.first_name, d.last_name
FROM developers d, skillcodes s
WHERE s.category = 'Front End' 
AND d.skill_code & s.code > 0
ORDER BY d.id;
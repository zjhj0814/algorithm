-- 코드를 입력하세요
-- 2022년 10월 16일에 대여중 -> start_date가 2022년 10월 16일 이하 + end_date가 2022년 10월 16일 이상
SELECT car_id,
(CASE 
WHEN MAX(start_date <= '2022-10-16' AND end_date >= '2022-10-16') = 1 THEN '대여중'
ELSE '대여 가능' 
END) AS availability
-- 조건의 결과는 1(true) 또는 0(false)
-- COUNT(조건)은 1이든 0이든 그룹핑한 개수 세기
-- SUM(조건)은 조건 결과를 숫자로 더하기
-- MAX(조건)은 조건 결과 중 가장 큰 값 반환
FROM car_rental_company_rental_history
GROUP BY car_id
ORDER BY car_id DESC;


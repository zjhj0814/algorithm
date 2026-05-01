-- 코드를 입력하세요

-- rh: 10월에 대여중인 자동차 id
-- c: car_type = '세단'
SELECT car_id
FROM car_rental_company_car
WHERE car_type = '세단'
AND car_id IN (
    SELECT distinct(car_id)
    FROM car_rental_company_rental_history
    WHERE MONTH(start_date) = 10
)
ORDER BY car_id DESC;
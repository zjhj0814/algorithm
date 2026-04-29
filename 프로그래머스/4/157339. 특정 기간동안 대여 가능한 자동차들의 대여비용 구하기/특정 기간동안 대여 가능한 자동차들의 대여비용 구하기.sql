-- 코드를 입력하세요
SELECT car_id, car_type, fee
FROM (
    SELECT
        c.car_id,
        c.car_type,
        FLOOR(c.daily_fee * (100 - IFNULL(dp.discount_rate, 0)) * 0.01 * 30) AS fee -- 계산할 때 괄호 주의
    FROM car_rental_company_car c
    LEFT JOIN car_rental_company_discount_plan dp
        ON c.car_type = dp.car_type
        AND dp.duration_type = '30일 이상'
    WHERE c.car_type IN ('세단', 'SUV')
    AND NOT EXISTS ( -- 11월 대여기록이 없는 차만
        SELECT 1 FROM car_rental_company_rental_history rh
        WHERE rh.car_id = c.car_id
        AND rh.start_date <= '2022-11-30'
        AND rh.end_date >= '2022-11-01'
    )
) AS tmp           
WHERE fee >= 500000 -- 서브쿼리의 fee 사용
AND fee < 2000000
ORDER BY fee DESC, car_type ASC, car_id DESC;

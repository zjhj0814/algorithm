-- 코드를 입력하세요
-- user_info: 2021년에 joined한 전체 회원 대상
SELECT 
YEAR(s.sales_date) as year, MONTH(s.sales_date) as month, 
COUNT(DISTINCT u.user_id) as purchased_users,
ROUND(
    COUNT(DISTINCT u.user_id)
    /(SELECT COUNT(*) FROM user_info WHERE YEAR(joined) = '2021')
,1) as purchased_ratio
FROM online_sale s 
JOIN user_info u ON u.user_id = s.user_id
WHERE YEAR(u.joined) = '2021'
GROUP BY YEAR(s.sales_date), MONTH(s.sales_date)
ORDER BY year, month;
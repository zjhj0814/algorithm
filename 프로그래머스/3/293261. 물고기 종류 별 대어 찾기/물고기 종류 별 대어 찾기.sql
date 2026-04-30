-- 코드를 작성해주세요
SELECT i.id, ni.fish_name, i.length
FROM fish_info i
JOIN fish_name_info ni ON i.fish_type = ni.fish_type
WHERE (i.fish_type, length) IN (
    SELECT fish_type, MAX(length)
    FROM fish_info
    GROUP BY fish_type
)
GROUP BY i.fish_type
ORDER BY i.id;
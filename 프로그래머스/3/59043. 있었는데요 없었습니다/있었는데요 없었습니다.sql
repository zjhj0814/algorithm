-- 코드를 입력하세요
SELECT o.animal_id, o.name
FROM animal_outs o JOIN animal_ins i ON o.animal_id = i.animal_id
WHERE i.datetime > o.datetime
ORDER BY i.datetime;
-- 코드를 입력하세요
-- OUTS - INS(차집함)
SELECT animal_id, name
FROM animal_outs 
WHERE animal_id NOT IN (SELECT animal_id FROM animal_ins)
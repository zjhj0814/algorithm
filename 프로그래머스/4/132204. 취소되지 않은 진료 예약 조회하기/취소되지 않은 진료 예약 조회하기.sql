-- 코드를 입력하세요
-- appointment: apnt_cncl_yn이 N, mcdp_cd가 CS
SELECT a.apnt_no, p.pt_name, p.pt_no, a.mcdp_cd, d.dr_name, a.apnt_ymd
FROM appointment a
JOIN doctor d ON a.mddr_id = d.dr_id
JOIN patient p ON a.pt_no = p.pt_no
WHERE apnt_cncl_yn = 'N' AND DATE(apnt_ymd) = '2022-04-13' AND a.mcdp_cd = 'CS'
ORDER BY a.apnt_ymd;
-- 코드를 입력하세요
SELECT ANIMAL_ID, NAME
FROM ANIMAL_OUTS 
WHERE NOT EXISTS (SELECT ANIMAL_ID, NAME FROM ANIMAL_INS WHERE ANIMAL_INS.ANIMAL_ID = ANIMAL_OUTS.ANIMAL_ID)
ORDER BY ANIMAL_ID
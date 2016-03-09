--1
SELECT *
FROM riviere r
JOIN ville v ON r.id = v.id_riviere
WHERE v.nom LIKE 'G%';

--2
SELECT *
FROM riviere r
JOIN mer m ON r.id_mer = m.id
JOIN border b ON m.id = b.id_mer
JOIN pays p ON b.id_pays = p.id
WHERE p.nom = "France";

--3
SELECT count( * ) , AVG( r1.longueur )
FROM riviere r1
JOIN riviere r2 ON r1.id = r2.id_riviere
WHERE r1.nom = "Rhône"

--4
SELECT AVG( superficie ) AS SuperficieMoyenne
FROM pays p
JOIN border b ON p.id = b.id_pays
JOIN mer m ON m.id = b.id_mer
WHERE m.nom = 'méditerrannée'


--5
SELECT p.nom, count( v.id )
FROM pays p
JOIN ville v ON p.id = v.id_pays
GROUP BY p.id;

--6
SELECT m.nom, count( r.id ) AS NBfleuves
FROM mer m
JOIN riviere r ON m.id = r.id_mer
WHERE r.longueur >300;

--7
SELECT p.nom, SUM( v.nbHabitants )
FROM pays p
JOIN ville v ON p.id = v.id_pays
GROUP BY p.id
HAVING SUM( v.nbHabitants ) >1000000;

--8
SELECT r1.nom
FROM riviere r1
JOIN riviere r2 ON r1.id = r2.id_riviere
GROUP BY r1.id
HAVING MAX( r2.longueur ) >250;

--9
SELECT max( nbHabitants ) AS maxHab, ville.nom
FROM ville
GROUP BY ville.id
ORDER BY maxHab DESC
LIMIT 1;


--10

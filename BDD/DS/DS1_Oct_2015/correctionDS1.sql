--Exercice 1
--Correction orale
--1
SELECT NumC FROM CLIENT WHERE ville = 'Toulouse' and prenom like 'M%';

--2
SELECT numP FROM PRODUIT WHERE prixU > 10 and designation like '%S' or designation like '%T';

--3
SELECT numC, CLIENT.nom FROM CLIENT WHERE ville IS NULL;

--4
SELECT numA FROM ACHAT WHERE date BETWEEN '01/10/2014' AND '01/10/2015' AND quantite > 100;

--5
SELECT count(*) FROM ACHAT WHERE numC = 234;

--6
SELECT MIN(quantite), MAX(quantite), AVG(quantite) FROM ACHAT WHERE numC = 234;

--Exercice 2

--1 Produit cartésien
SELECT numP FROM CLIENT, ACHAT
WHERE CLIENT.numC = ACHAT.numC
AND CLIENT.prenom = 'Pierre' AND CLIENT.nom = 'Martin';
--Jointure Interne
SELECT numP FROM CLIENT INNER JOIN ACHAT ON CLIENT.numC = ACHAT.numC
WHERE CLIENT.prenom = 'Pierre' AND CLIENT.nom = 'Martin';

--2 Produit Cartésien
SELECT designation FROM CLIENT, ACHAT, PRODUIT
WHERE CLIENT.numC = ACHAT.numC AND ACHAT.numP = PRODUIT.numP
AND CLIENT.prenom = 'Pierre' AND CLIENT.nom = 'Martin';
--Jointure Interne
SELECT designation FROM CLIENT, ACHAT , PRODUIT
FROM CLIENT INNER JOIN ACHAT ON CLIENT.numC = ACHAT.numC
INNER JOIN PRODUIT ON ACHAT.numP = PRODUIT.numP
WHERE CLIENT.prenom = 'Pierre' AND CLIENT.nom = 'Martin';

--3 Produit Cartésien
SELECT FOURNISSEUR.nom FROM FOURNISSEUR, PRODUIT, FOURNIT
WHERE FOURNISSEUR.numF = FOURNIT.numF AND FOURNIT.numP = PRODUIT.numP
AND PRODUIT.numP = 15 AND FOURNISSEUR.ville = 'Lens';
--Jointure Interne
SELECT FOURNISSEUR.nom FROM FOURNISSEUR INNER JOIN FOURNIT ON FOURNISSEUR.numF = FOURNIT.numF
                                        INNER JOIN PRODUIT ON FOURNIT.numP = PRODUIT.numP
WHERE PRODUIT.numP = 15 AND FOURNISSEUR.ville = 'Lens';

--4 Produit Cartésien
SELECT FOURNISSEUR.nom FROM FOURNISSEUR, PRODUIT, FOURNIT
WHERE FOURNISSEUR.numF = FOURNIT.numF AND FOURNIT.numP = PRODUIT.numP
AND FOURNISSEUR.ville = 'Lens' AND designation = 'Super Ordi';
--Jointure Interne
SELECT FOURNISSEUR.nom FROM FOURNISSEUR INNER JOIN FOURNIT ON FOURNISSEUR.numF = FOURNIT.numF
                                        INNER JOIN PRODUIT ON FOURNIT.numP = PRODUIT.numP
WHERE FOURNISSEUR.ville = 'Lens' AND designation = 'Super Ordi';

--Exercice 3
--1
SELECT FOURNISSEUR.ville , count(*)
FROM FOURNISSEUR
GROUP BY ville;

--2
SELECT FOURNISSEUR.ville
FROM FOURNISSEUR
GROUP BY ville
HAVING count(numF) > 3;

--3
SELECT CLIENT.numC, CLIENT.nom, CLIENT.prenom, AVG(quantite)
FROM CLIENT, ACHAT
WHERE CLIENT.numC = ACHAT.numC
GROUP BY CLIENT.numC
HAVING COUNT(ACHAT.numA) >= 4;

--Exercice 4
--1
SELECT CLIENT.numC FROM CLIENT
WHERE CLIENT.ville = 'Lens'
EXCEPT
SELECT numC FROM PRODUIT, ACHAT
WHERE PRODUIT.numP = ACHAT.numP AND designation = 'Super Ordi';
--2
SELECT CLIENT.numC FROM CLIENT
WHERE CLIENT.ville = 'Lens'
INTERSECT
SELECT CLIENT.numC FROM ACHAT
WHERE ACHAT.date = '01/10/2015';

--Exercice 5
--1

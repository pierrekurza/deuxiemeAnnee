--Exercice 1
--1
SELECT NumLivre, Titre FROM LIVRE
WHERE NombrePages >= (
  SELECT AVG(NombrePages) FROM LIVRE);

--2
SELECT DISTINCT NumL FROM ECRIT
WHERE NumAuteur IN (
  SELECT NumAut FROM AUTEUR
  WHERE Prénom="Chester");

--3
SELECT DISTINCT NumAut FROM ECRIT
WHERE NumAut NOT IN (
  SELECT NumL FROM ECRIT
  WHERE NumL = 2);

--4
SELECT NumE, Nom FROM EDITEUR
WHERE NumE NOT IN (
  SELECT NumE FROM EDITE);

--5
SELECT NumAut, Nom FROM EDITEUR
WHERE NumAut NOT IN (
  SELECT NumAut FROM AUTEUR
  WHERE AUTEUR.Nom LIKE 'C%'
  );
  
 SELECT NumAut, Nom FROM AUTEUR
 WHERE Nom LIKE 'C%' AND NumAut NOT IN (
   SELECT NumAut FROM ECRIT
 )

--6
SELECT NumLivre, Titre FROM LIVRE
WHERE NumLivre IN (
  SELECT NumL FROM EDITE
  WHERE NumE = 0 )
  AND NumLivre NOT IN (
    SELECT NumL FROM ECRIT
    WHERE NumAut = 4
    )
  )
);

--7
SELECT NumAut
FROM ECRIT
GROUP BY NumAut 
HAVING count(*) = (
  SELECT MAX(count(*))
  FROM ECRIT
  GROUP BY NumAut )
); 


--Exercice 2
--1
SELECT NumAut FROM AUTEUR
where NumAut NOT IN (
  SELECT AnneeImpression FROM LIVRE, ECRIT
  WHERE LIVRE.NumLivre=ECRIT.NumL AND AnneeImpression=2003
);

--2
SELECT LIVRE.NumLivre , LIVRE.Titre as "Titre des livres" FROM LIVRE NOT IN (
  SELECT NumL FROM AUTEUR,ECRIT
  WHERE ECRIT.NumAut=AUTEUR.NumAut AND Nom = 'Himes' AND Prenom = 'Chester')
  AND NumLivre IN (
    SELECT NumL FROM EDITE,EDITEUR
    WHERE EDITE.NumE=EDITEUR.NumE AND Nom ='Gallimard'
  )
);

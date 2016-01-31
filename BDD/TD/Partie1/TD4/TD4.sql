--Exercice 1
CREATE TABLE Employes (
    idEmp      INT(8),
    nom        VARCHAR2(50) NOT NULL CHECK(CHAR_LENGTH(nom) > 3),
    prenom     VARCHAR2(50) NOT NULL CHECK(CHAR_LENGTH(prenom) > 3),
    numTel     VARCHAR2(10),
    PRIMARY KEY (idEmp)
);

CREATE TABLE Grille (
    indiceSalaire       INT(5),
    montant             DECIMAL(5,2) CHECK(montant > 1200),
    PRIMARY KEY (indiceSalaire)
);

CREATE TABLE Salaires (
    idEmp INT(8) FOREIGN KEY REFERENCES Employes(idEmp),
    indiceSalaire INT(8) FOREIGN KEY REFERENCES Grille(indiceSalaire),
    PRIMARY KEY (idEmp, indiceSalaire)
);

CREATE TABLE Departement (
    idDept      INT(4),
    nom         VARCHAR2(20) CHECK(CHAR_LENGTH(nom) > 3),
    effectif    INT(4) DEFAULT 0,
    PRIMARY KEY (idDept)
);

CREATE TABLE Affectation (
    idDept INT(4) FOREIGN KEY REFERENCES Departement(idDept),
    idEmp  INT(8) FOREIGN KEY REFERENCES Employes(idEmp),
    PRIMARY KEY (idDept, idEmp)
);

--Se passer de la table salaire ?
--Oui, mais lors de requetes, on aurait du faire des jointures avec les tables Grille et Employes.

--Exercice 2
INSERT INTO Employes(idEmp,nom,prenom) VALUES (204,'Martin','Paul');
INSERT INTO Salaires VALUES (204,451);
INSERT INTO Affectation VALUES (11,204);
INSERT INTO Affectation VALUES (12,204);

INSERT INTO Departement (idDept, nom) VALUES (20,'Produit de luxe');
INSERT INTO Affectation VALUES (20,14);
INSERT INTO Affectation VALUES (20,23);
INSERT INTO Affectation VALUES (20,67);

--Exercice 3

cf. ordre du TD

1-
Un employé avec l'id 0 , qui s'apelle Saade Mahmoud avec un num tel égal à...
2-
Un employé sera ajouté avec seulement 3 valeurs, son ID, nom et prenom.
3-
L'employé 0 : Saade Mahmoud aura un indice de salaire égal à 450.
4-
Dans la table Grille, pour un indiceSalaire de 450, le salaire sera égal a 1500
5-
Idem pour l'indiceSalaire , mais avec un salaire de 1700
6-
L'employé portant l'ID n°1, aura un indiceSalaire de 500, donc un salaire de 1700€
7-
idem pour l'employé num 1 , avec un second indiceSalaire
8-
L'employé avec l'ID 0 , est affecté au dpt Produit de luxe
9-
L'employé num 0 est affecté au département portant l'ID 1
10-
l'employé 0 est affecté aussi au département 1
11-
Le département num 1 , aura comme nom "Electroménager", avec numéro d'effectif = NULL
12-
L'employé portant l'ID 1 sera changé de département -> Produit de luxe
13-
l'employe avec id 1 sera affecte au département 1 = Electromenager

--Exercice 4
--1
DELETE  from Affectation where idDept = 2;
--2
DELETE  from Affectation
WHERE idDept IN (
    SELECT idDept
    FROM Departement
    WHERE nom = 'Electromenager'
);
DELETE FROM Departement WHERE nom = 'Electromenager';

--3
DELETE  from Affectation where idEmp = 14;

--4
DELETE  from Employes where idEmp = 15;
--5
DELETE indiceSalaire from Grille where montant > 3000;


--Exercice 5
--1
UPDATE Employes SET prenom = 'Marc'
WHERE idEmp = 14 ;
--2
UPDATE Departement SET nom = 'Luxe'
WHERE nom = 'Produit de luxe';
--3
UPDATE Grille SET montant = montant * 1.1;
--4
UPDATE
--5
UPDATE Departement SET effectif = 0
WHERE idDept = 10;


--Exercice 6
--1
SELECT idEmp , Nom FROM Employes where numTel = NULL;
--2
SELECT Departement.nom FROM Affectation, Employes
WHERE Employes.idEmp=Affectation.idEmp AND prenom = 'Marc' and Employes.nom = 'Dupont';
--3
SELECT Employes.nom , AVG(montant) FROM Grille, Affectation, Departement, Employes
WHERE

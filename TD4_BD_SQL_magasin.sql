
CREATE TABLE Employe (
    id SERIAL PRIMARY KEY,
    nom VARCHAR(50) NOT NULL,
    prenom VARCHAR(50) NOT NULL
);

CREATE TABLE Produit (
    id SERIAL PRIMARY KEY,
    nom VARCHAR(50) NOT NULL,
    volume INT NOT NULL CHECK(volume>0),
    prix FLOAT NOT NULL CHECK(prix>0)
);

CREATE TABLE Unite (
    id SERIAL PRIMARY KEY,
    volume INT NOT NULL CHECK (volume>0)
);

CREATE TABLE Operation (
    id SERIAL PRIMARY KEY,
    dateOP TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL,
    nature VARCHAR(50) NOT NULL CHECK nature IN('entree', 'sortie'),
    quantite INT NOT NULL CHECK(quantite>0),
    id_produit INT NOT NULL REFERENCES Produit(id) ,
    id_unite INT NOT NULL REFERENCES Unite(id)
);

CREATE TABLE EMP_OP (
    id_emp INT NOT NULL REFERENCES Employe(id),
    id_op INT NOT NULL REFERENCES Operation(id),
    PRIMARY KEY (id_emp, id_op)
);


--Insertion Tables

INSERT INTO Employe (nom, prenom)
VALUES
('Dupond', 'Kévin'),
('Legrand', 'Alice'),
('Legrand', 'Robert');


INSERT INTO Produit
VALUES
(default,'clé USB', 10, 5.12),
(default,'écran 17"', 200, 125.52),
(default,'écran 21"', 250, 185);

INSERT INTO Unite
VALUES
(DEFAULT,500),
(DEFAULT,1000),
(DEFAULT,2000);

INSERT INTO Operation ( nature, quantite, id_produit, id_unite)
VALUES
('entree', 120, (SELECT id FROM Produit WHERE nom='clé USB'), (SELECT id FROM Unite WHERE volume = (SELECT min(volume) FROM Unite)));

INSERT INTO Operation (nature, quantite, id_produit, id_unite)
VALUES
('entree', 50, (SELECT id FROM Produit WHERE nom='écran 17"'), (SELECT id FROM Unite WHERE id=2));

INSERT INTO Effectuer
VALUES
(1,1), (2,1);

INSERT INTO Effectuer SELECT id, 2 FROM Employe;

INSERT INTO Operation (nature, id_produit, quantite, id_unite)
SELECT 'entree', id, 10, 3 FROM Produit WHERE Produit.nom LIKE 'écran%';

INSERT INTO Effectuer SELECT id, 3  FROM Employe WHERE nom='Legrand';

INSERT INTO Effectuer SELECT id, 4  FROM Employe WHERE nom<>'Legrand';

CREATE TABLE entree1 (
    idOperation INT NOT NULL REFERENCES Operation(id),
    dateOperation DATE,
    idProduit INT NOT NULL REFERENCES Produit(id),
    quantiteP INT,
    volume INT
);

INSERT INTO entree1 SELECT op.id, op.dateOP, op.id_produit, op.quantite , op.quantite * p.volume FROM Operation op JOIN Produit p
ON p.id = op.id_produit
WHERE op.id_unite=1 AND op.nature='entree';

--Modification Tables
UPDATE Operation SET quantite = 110 WHERE id=1;

UPDATE Operation SET dateOP=date_sub(dateOP,interval 1 day) WHERE id_produit = (SELECT id from Produit WHERE nom='clé USB');

UPDATE Produit SET Prix=Prix*1.1 WHERE nom LIKE 'écran%';

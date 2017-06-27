--
-- Файл сгенерирован с помощью SQLiteStudio v3.1.1 в пн июня 26 15:04:45 2017
--
-- Использованная кодировка текста: UTF-8
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Таблица: Application
CREATE TABLE "Application"(
  "id" INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  "CartridgeID" INTEGER NOT NULL,
  "WorkerID" INTEGER NOT NULL,
  "VictimName" VARCHAR(45) NOT NULL,
  "VictimSurname" VARCHAR(45) NOT NULL,
  "VictimPatron" VARCHAR(45) NOT NULL,
  "Comment" VARCHAR(45) NOT NULL,
  "ApplicationDate" DATETIME NOT NULL,
  "ShipmentID" INTEGER NOT NULL,
  CONSTRAINT "WorkerID"
    FOREIGN KEY("WorkerID")
    REFERENCES "Workers"("id"),
  CONSTRAINT "CartridgeID"
    FOREIGN KEY("CartridgeID")
    REFERENCES "Cartridges"("id"),
  CONSTRAINT "shipmentID"
    FOREIGN KEY("ShipmentID")
    REFERENCES "Shipment"("id")
);

-- Таблица: Cartridges
CREATE TABLE "Cartridges"(
  "id" INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  "ReFull" INTEGER NOT NULL DEFAULT 0,
  "Status" INTEGER NOT NULL DEFAULT 1,
  "Type" INTEGER NOT NULL,
  CONSTRAINT "id_UNIQUE"
    UNIQUE("id"),
  CONSTRAINT "Type"
    FOREIGN KEY("Type")
    REFERENCES "CartridgeTypes"("id")
);

-- Таблица: CartridgeTypes
CREATE TABLE "CartridgeTypes"(
  "id" INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  "Brand" VARCHAR(45) NOT NULL,
  "Name" VARCHAR(45) NOT NULL,
  "Chip" INTEGER NOT NULL DEFAULT 0,
  "ChipModel" VARCHAR(45),
  "Color" VARCHAR(45),
  "Site" VARCHAR(45),
  "Photo" VARCHAR(45)
);

-- Таблица: Compatibility
CREATE TABLE "Compatibility"(
  "CatridgeID" INTEGER NOT NULL,
  "PrinterID" INTEGER NOT NULL,
  CONSTRAINT "CompatibilityKey"
    UNIQUE("CatridgeID","PrinterID"),
  CONSTRAINT "PrinterID"
    FOREIGN KEY("PrinterID")
    REFERENCES "Printers"("id"),
  CONSTRAINT "CatridgeID"
    FOREIGN KEY("CatridgeID")
    REFERENCES "CartridgeTypes"("id")
);

-- Таблица: Printers
CREATE TABLE "Printers"(
  "id" INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  "Name" VARCHAR(45) NOT NULL,
  "Colored" INTEGER NOT NULL,
  "Site" VARCHAR(45) NOT NULL,
  "Photo" BLOB,
  CONSTRAINT "id_UNIQUE"
    UNIQUE("id")
);

-- Таблица: Shipment
CREATE TABLE "Shipment"(
  "id" INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  "Service" VARCHAR(45),
  "ArrivalDate" DATE,
  "ReturnDate" DATE,
  "Precent" FLOAT
);

-- Таблица: Workers
CREATE TABLE "Workers"(
  "id" INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
  "Name" VARCHAR(45) NOT NULL,
  "Surname" VARCHAR(45) NOT NULL,
  "UserName" VARCHAR(45) NOT NULL,
  "Password" VARCHAR(45) NOT NULL,
  "Position" VARCHAR(45) NOT NULL,
  "Privilege" BINARY(11) NOT NULL
);

-- Индекс: Application.CatridgeID_idx
CREATE INDEX "Application.CatridgeID_idx" ON "Application" ("CartridgeID");

-- Индекс: Application.shipmentID_idx
CREATE INDEX "Application.shipmentID_idx" ON "Application" ("ShipmentID");

-- Индекс: Application.WorkerID_idx
CREATE INDEX "Application.WorkerID_idx" ON "Application" ("WorkerID");

-- Индекс: Cartridges.Type_idx
CREATE INDEX "Cartridges.Type_idx" ON "Cartridges" ("Type");

-- Индекс: Compatibility.PrinterID_idx
CREATE INDEX "Compatibility.PrinterID_idx" ON "Compatibility" ("PrinterID");

-- Триггер: arrivalCartridge
CREATE TRIGGER arrivalCartridge AFTER UPDATE OF ArrivalDate ON Shipment BEGIN UPDATE Cartridges SET Status = 4 WHERE Cartridges.id IN ( SELECT CartridgeID FROM Application WHERE ShipmentID = NEW.id); END;

-- Триггер: getCartridge
CREATE TRIGGER getCartridge AFTER INSERT ON Application BEGIN UPDATE Cartridges SET Status = 3 WHERE Cartridges.id = NEW.CartridgeID; END;

-- Триггер: returnCartridge
CREATE TRIGGER returnCartridge AFTER UPDATE OF ReturnDate ON Shipment BEGIN UPDATE Cartridges SET Status = 1, Refull=Refull+1 WHERE Cartridges.id IN ( SELECT CartridgeID FROM Application WHERE ShipmentID = NEW.id); END;

COMMIT TRANSACTION;
PRAGMA foreign_keys = on;

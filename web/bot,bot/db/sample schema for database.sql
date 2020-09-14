BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "users" (
	"id"	TEXT,
	"password"	TEXT,
	"role"	TEXT,
	"state"	TEXT
);
INSERT INTO "users" ("id","password","role","state") VALUES ('guest','guest','visitor','active');
INSERT INTO "users" ("id","password","role","state") VALUES ('admin','password','admin','blocked');
COMMIT;

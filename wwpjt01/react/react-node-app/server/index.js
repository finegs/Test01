const express = require("express");
const path = require("path");
const sqlite3 = require("sqlite3").verbose();

// Creating the Express server
const app = express();

const PORT = process.env.PORT || 3001;

// Server configuration
app.set("view engine", "ejs");
app.set("views", path.join(__dirname, "views"));
app.use(express.static(path.join(__dirname, "public")));
app.use(express.urlencoded({ extended: false }));

// Connection to the SQlite database
const db_name = path.join(__dirname, "data", "apptest.db");
const db = new sqlite3.Database(db_name, err => {
    if (err) {
        return console.error(err.message);
    }
    console.log("Successful connection to the database 'apptest.db'");
});

// Creating the Books table (Book_ID, Title, Author, Comments)
const sql_create = `CREATE TABLE IF NOT EXISTS Books (
  Book_ID INTEGER PRIMARY KEY AUTOINCREMENT,
  Title VARCHAR(100) NOT NULL,
  Author VARCHAR(100) NOT NULL,
  Comments TEXT
);`;
db.run(sql_create, err => {
    if (err) {
        return console.error(err.message);
    }
    console.log("Successful creation of the 'Books' table");
    // Database seeding
    const sql_insert = `INSERT INTO Books (Book_ID, Title, Author, Comments) VALUES
  (1, 'Mrs. Bridge', 'Evan S. Connell', 'First in the serie'),
  (2, 'Mr. Bridge', 'Evan S. Connell', 'Second in the serie'),
  (3, 'L''ingénue libertine', 'Colette', 'Minne + Les égarements de Minne') 
  ON CONFLICT(Book_ID) DO NOTHING;`;
    db.run(sql_insert, err => {
        if (err) {
            return console.error(err.message);
        }
        console.log("Successful creation of 3 books");
    });
});

// GET /
app.get("/", (req, res) => {
    // res.send("Hello world...");
    res.render("index");
});

// GET /about
app.get("/about", (req, res) => {
    res.render("about");
});

// GET /data
app.get("/data", (req, res) => {
    const test = {
        titre: "Test",
        items: ["one", "two", "three"]
    };
    res.render("data", { model: test });
});

// GET /books
app.get("/books", (req, res) => {
    const sql = "SELECT * FROM Books ORDER BY Title";
    db.all(sql, [], (err, rows) => {
        if (err) {
            return console.error(err.message);
        }
        res.render("books", { model: rows });
    });
});

// GET /create
app.get("/create", (req, res) => {
    const book = {
        Author: "__Created Author"
    };
    res.render("create", { model: book });
});

// POST /create
app.post("/create", (req, res) => {
    const sql = "INSERT INTO Books (Title, Author, Comments) VALUES (?, ?, ?)";
    const book = [req.body.Title, req.body.Author, req.body.Comments];
    db.run(sql, book, err => {
        if (err) {
            return console.error(err.message);
        }
        res.redirect("/books");
    });
});

// GET /edit/5
app.get("/edit/:id", (req, res) => {
    const id = req.params.id;
    const sql = "SELECT * FROM Books WHERE Book_ID = ?";
    db.get(sql, id, (err, row) => {
        if (err) {
            return console.error(err.message);
        }
        res.render("edit", { model: row });
    });
});

// POST /edit/5
app.post("/edit/:id", (req, res) => {
    const id = req.params.id;
    const book = [req.body.Title, req.body.Author, req.body.Comments, id];
    const sql = "UPDATE Books SET Title = ?, Author = ?, Comments = ? WHERE (Book_ID = ?)";
    db.run(sql, book, err => {
        if (err) {
            return console.error(err.message);
        }
        res.redirect("/books");
    });
});

// GET /delete/5
app.get("/delete/:id", (req, res) => {
    const id = req.params.id;
    const sql = "SELECT * FROM Books WHERE Book_ID = ?";
    db.get(sql, id, (err, row) => {
        if (err) {
            return console.error(err.message);
        }
        res.render("delete", { model: row });
    });
});

// POST /delete/5
app.post("/delete/:id", (req, res) => {
    const id = req.params.id;
    const sql = "DELETE FROM Books WHERE Book_ID = ?";
    db.run(sql, id, err => {
        if (err) {
            return console.error(err.message);
        }
        res.redirect("/books");
    });
});

app.listen(PORT, () => {
    console.log(`Server listening on ${PORT}`);
});
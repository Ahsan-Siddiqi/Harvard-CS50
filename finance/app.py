import os
import datetime

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd


# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd
app.jinja_env.globals.update(lookup=lookup)

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    rows = db.execute("SELECT symbol, shares, SUM(shares) AS total_shares FROM PURCHASES WHERE id = ? GROUP BY symbol", session["user_id"])
    user = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])

    total = 0

    for row in rows:
        total += (float(lookup(row["symbol"])["price"]) * float(row["total_shares"]))

    total += float(user[0]["cash"])

    return render_template("index.html", purchases=rows, cash=usd(user[0]["cash"]), total=usd(total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide a symbol", 400)

        elif not request.form.get("shares"):
            return apology("must provide number of shares", 400)

        try:
            if int(request.form.get("shares")) < 1:
                return apology("invalid number of shares", 400)
        except ValueError:
                return apology("invalid number of shares", 400)

        info = lookup(request.form.get("symbol"))

        if info == None:
            return apology("invalid symbol", 400)

        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

        if cash[0]["cash"] < (float(request.form.get("shares")) * info["price"]):
            return apology("you're too broke for this", 400)

        date = datetime.datetime.now()

        db.execute("INSERT INTO history (id, symbol, shares, price, date, type) VALUES (?, ?, ?, ?, ?, ?)", session["user_id"], (request.form.get("symbol")).upper(), int(request.form.get("shares")), info["price"], date.strftime("%c"), "buy")

        contains = db.execute("SELECT symbol FROM purchases WHERE symbol = ? AND id = ?", request.form.get("symbol").upper(), session["user_id"])

        if contains:
            db.execute("UPDATE purchases SET shares = ? WHERE id = ? and symbol = ?", int(request.form.get("shares")), session["user_id"], (request.form.get("symbol")).upper())
        else:
            db.execute("INSERT INTO purchases (id, symbol, shares) VALUES (?, ?, ?)", session["user_id"], request.form.get("symbol").upper(), request.form.get("shares"))


        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash[0]["cash"]-(float(request.form.get("shares")) * info["price"]), session["user_id"])

        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    rows = db.execute("SELECT * FROM history WHERE id = ?", session["user_id"])
    user = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])

    return render_template("history.html", purchases=rows, cash=usd(user[0]["cash"]))


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide a symbol", 400)

        info = lookup(request.form.get("symbol"))

        if info == None:
            return apology("invalid symbol", 400)

        return render_template("quoted.html", symbol=info["symbol"], price=info["price"])

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Ensure confirmation matches password
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords don't match", 400)

        # INSERT username and password in database
        try:
            rows = db.execute(
                "INSERT INTO users (username, hash) VALUES (?, ?)", request.form.get("username"), generate_password_hash(request.form.get("password"))
            )
        except ValueError:
            return apology("Username Already Exists", 400)

        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":

        if not request.form.get("symbol"):
            return apology("Must select a symbol", 400)

        try:
            if int(request.form.get("shares")) < 1:
                return apology("invalid number of shares", 400)
        except ValueError:
                return apology("invalid number of shares", 400)

        owned = db.execute("SELECT SUM(shares) AS total_shares, symbol FROM purchases WHERE id = ? AND symbol = ? GROUP BY symbol", session["user_id"], request.form.get("symbol"))

        if int(request.form.get("shares")) < owned[0]["total_shares"]:
            return apology("You don't have that many shares", 400)

        date = datetime.datetime.now()
        info = lookup(request.form.get("symbol"))

        db.execute("INSERT INTO history (id, symbol, shares, price, date, type) VALUES (?, ?, ?, ?, ?, ?)", session["user_id"], (request.form.get("symbol")).upper(), -int(request.form.get("shares")), info["price"], date.strftime("%c"), "sell")

        db.execute("INSERT INTO purchases (symbol, shares, id) VALUES (?, ?, ?)", (request.form.get("symbol")).upper(), -int(request.form.get("shares")), session["user_id"])

        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash[0]["cash"]-(float(request.form.get("shares")) * info["price"]), session["user_id"])

    else:
        owned = db.execute("SELECT symbol FROM purchases WHERE id = ? GROUP BY symbol", session["user_id"])

        return render_template("sell.html", symbols=owned)

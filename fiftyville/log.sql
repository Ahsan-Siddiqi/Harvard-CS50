-- Keep a log of any SQL queries you execute as you solve the mystery.

--interview info
SELECT transcript FROM interviews WHERE year = 2023 AND day = 28 AND month = 7;

--find earlist flight the day after
SELECT id FROM flights WHERE year = 2023 AND day = 29 ORDER BY hour ASC, minute ASC LIMIT 1;

--using the flight id, license plate from the security, and the phone number the day of which was less that one minute long get a list of suspects
SELECT name FROM people WHERE passport_number IN (
    SELECT passport_number FROM passengers WHERE flight_id = 36)
    AND license_plate IN (
        SELECT license_plate FROM bakery_security_logs WHERE year = 2023 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25)
    AND phone_number IN (SELECT caller FROM phone_calls WHERE year = 2023 AND day = 28 AND month = 7 AND duration < 60);

--check who withdrew the money at leggett street
SELECT name FROM people WHERE id IN (
    SELECT person_id FROM bank_accounts WHERE account_number IN (
        SELECT account_number FROM atm_transactions WHERE year = 2023 AND month = 7 AND day = 28 AND transaction_type = "withdraw" AND atm_location = "Leggett Street"));

--who was bruce talking to?
SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2023 AND day = 28 AND month = 7 AND duration < 60);

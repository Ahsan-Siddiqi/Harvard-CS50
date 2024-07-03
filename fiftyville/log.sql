-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT name FROM people WHERE passport_number IN (
    SELECT passport_number FROM passengers WHERE flight_id = 36)
    AND license_plate IN (
        SELECT license_plate FROM bakery_security_logs WHERE year = 2023 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25)
    AND phone_number IN (SELECT );

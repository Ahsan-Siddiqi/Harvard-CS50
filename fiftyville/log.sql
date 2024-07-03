-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36) AND license_plate IN (SELECT license_plate FROM bakery_security_logs WHERE );

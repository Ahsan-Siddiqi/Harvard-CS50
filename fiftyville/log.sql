-- Keep a log of any SQL queries you execute as you solve the mystery.

--using the flight id, license plate from the security, and the phone number the day of which was less that one minute long get a list of suspects
SELECT name FROM people WHERE passport_number IN (
    SELECT passport_number FROM passengers WHERE flight_id = 36)
    AND license_plate IN (
        SELECT license_plate FROM bakery_security_logs WHERE year = 2023 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25)
    AND phone_number IN (SELECT caller FROM phone_calls WHERE year = 2023 AND day = 28 AND month = 7 AND duration < 60);

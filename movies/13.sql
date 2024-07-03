SELECT name FROM people WHERE id IN (SELECT people_id FROM stars WHERE people_id = (SELECT id FROM people WHERE name = "Kevin Bacon"))
